#pragma once
#include "PluginProcessor.h"
class HoltertEditor final : public juce::AudioProcessorEditor {
public:
 explicit HoltertEditor(HoltertProcessor&);
 void paint(juce::Graphics&) override;
 void resized() override;
private:
 HoltertProcessor& processor;
 juce::Label title,subtitle,notice;
 std::array<juce::Slider,6> knobs;
 std::array<juce::Label,6> labels;
 using Attachment=juce::AudioProcessorValueTreeState::SliderAttachment;
 std::vector<std::unique_ptr<Attachment>> attachments;
 JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HoltertEditor)
};
