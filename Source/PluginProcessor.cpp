#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>
HoltertProcessor::HoltertProcessor():juce::AudioProcessor(BusesProperties().withInput("Kick Input",juce::AudioChannelSet::stereo(),true).withOutput("Rumble Only",juce::AudioChannelSet::stereo(),true)),params(*this,nullptr,"PARAMETERS",makeParams()){}
juce::AudioProcessorValueTreeState::ParameterLayout HoltertProcessor::makeParams(){
 std::vector<std::unique_ptr<juce::RangedAudioParameter>> p;
 auto add=[&](const char* id,const char* name,float lo,float hi,float def){p.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID{id,1},name,juce::NormalisableRange<float>(lo,hi),def));};
 add("rumble","Rumble",0,1,0.65f);add("decay","Decay",0.05f,0.94f,0.68f);add("drive","Drive",0,1,0.42f);add("tone","Tone",45,350,140);add("duck","Ducking",0,1,0.72f);add("output","Output",0,1,0.75f);
 juce::AudioProcessorValueTreeState::ParameterLayout layout;
 for (auto& param : p) layout.add(std::move(param));
 return layout;
}
void HoltertProcessor::prepareToPlay(double sr,int){sampleRateHz=sr;const auto n=juce::jmax(1,(int)std::ceil(sr*2.0));delayL.assign((size_t)n,0);delayR.assign((size_t)n,0);writeIndex=0;lpL=lpR=env=prevInput=0;}
bool HoltertProcessor::isBusesLayoutSupported(const BusesLayout& l) const {const auto i=l.getMainInputChannelSet();return i==l.getMainOutputChannelSet()&&(i==juce::AudioChannelSet::mono()||i==juce::AudioChannelSet::stereo());}
void HoltertProcessor::processBlock(juce::AudioBuffer<float>& b,juce::MidiBuffer&){
 juce::ScopedNoDenormals noDenormals;
 if(delayL.empty()){b.clear();return;}
 const float rumble=*params.getRawParameterValue("rumble"),feedback=*params.getRawParameterValue("decay"),drive=*params.getRawParameterValue("drive"),cut=*params.getRawParameterValue("tone"),duck=*params.getRawParameterValue("duck"),output=*params.getRawParameterValue("output");
 double bpm=150.0;if(auto* ph=getPlayHead()){if(auto pos=ph->getPosition()){if(auto tempo=pos->getBpm())bpm=*tempo;}}
 bpm=juce::jlimit(40.0,300.0,bpm);
 const int delaySamples=juce::jlimit(1,(int)delayL.size()-1,(int)std::round(sampleRateHz*60.0/bpm/4.0)); // 1/16 note
 const float a=std::exp(-2.0f*juce::MathConstants<float>::pi*cut/(float)sampleRateHz);
 const float attack=std::exp(-1.0f/(float)(sampleRateHz*0.002));
 const float release=std::exp(-1.0f/(float)(sampleRateHz*0.09));
 auto* l=b.getWritePointer(0);auto* r=b.getNumChannels()>1?b.getWritePointer(1):nullptr;
 for(int i=0;i<b.getNumSamples();++i){
  const float inL=l[i],inR=r?r[i]:inL,mono=0.5f*(inL+inR);
  const float energy=std::abs(mono);
  env=energy>env?attack*env+(1-attack)*energy:release*env+(1-release)*energy;
  const bool hit=energy>0.085f&&energy>prevInput*1.9f;
  prevInput=energy;
  const float duckGain=1.0f-duck*juce::jlimit(0.0f,1.0f,env*4.0f);
  const int rd=(writeIndex-delaySamples+(int)delayL.size())%(int)delayL.size();
  const float dL=delayL[(size_t)rd],dR=delayR[(size_t)rd];
  // Stable feedback and low-pass filtering; the dry kick is never sent to output.
  lpL=a*lpL+(1-a)*dL;lpR=a*lpR+(1-a)*dR;
  const float saturation=1.0f+drive*6.0f;
  const float wetL=std::tanh(lpL*saturation),wetR=std::tanh(lpR*saturation);
  delayL[(size_t)writeIndex]=juce::jlimit(-1.0f,1.0f,inL*0.55f+wetL*feedback*0.88f);
  delayR[(size_t)writeIndex]=juce::jlimit(-1.0f,1.0f,inR*0.55f+wetR*feedback*0.88f);
  const float gain=rumble*output*duckGain;
  l[i]=std::tanh(wetL*gain*1.8f);
  if(r)r[i]=std::tanh(wetR*gain*1.8f);
  writeIndex=(writeIndex+1)%(int)delayL.size();
  juce::ignoreUnused(hit);
 }
}
juce::AudioProcessorEditor* HoltertProcessor::createEditor(){return new HoltertEditor(*this);}
void HoltertProcessor::getStateInformation(juce::MemoryBlock& dest){if(auto xml=params.copyState().createXml())copyXmlToBinary(*xml,dest);}
void HoltertProcessor::setStateInformation(const void* data,int size){if(auto xml=getXmlFromBinary(data,size))if(xml->hasTagName(params.state.getType()))params.replaceState(juce::ValueTree::fromXml(*xml));}
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter(){return new HoltertProcessor();}
