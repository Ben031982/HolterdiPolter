#pragma once
#include <JuceHeader.h>
#include <vector>
#include <atomic>
class HoltertProcessor final : public juce::AudioProcessor {
public:
 HoltertProcessor();
 void prepareToPlay(double, int) override;
 void releaseResources() override {}
 void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
 bool isBusesLayoutSupported(const BusesLayout&) const override;
 juce::AudioProcessorEditor* createEditor() override;
 bool hasEditor() const override {return true;}
 const juce::String getName() const override {return "HoltertDiPolter Rumble Maker";}
 bool acceptsMidi() const override {return false;}
 bool producesMidi() const override {return false;}
 bool isMidiEffect() const override {return false;}
 double getTailLengthSeconds() const override {return 2.0;}
 int getNumPrograms() override {return 1;}
 int getCurrentProgram() override {return 0;}
 void setCurrentProgram(int) override {}
 const juce::String getProgramName(int) override {return {};}
 void changeProgramName(int,const juce::String&) override {}
 void getStateInformation(juce::MemoryBlock&) override;
 void setStateInformation(const void*,int) override;
 juce::AudioProcessorValueTreeState params;
private:
 static juce::AudioProcessorValueTreeState::ParameterLayout makeParams();
 std::vector<float> delayL, delayR;
 int writeIndex=0;
 double sampleRateHz=44100.0;
 float lpL=0,lpR=0,env=0,prevInput=0;
 JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HoltertProcessor)
};
