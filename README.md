# HoltertDiPolter Rumble Maker v0.1

First **experimental** JUCE VST3 source project. No binary is included and the Windows build has **not yet been verified**.

## Implemented
- Real-time kick audio input; **rumble-only** output (dry input not passed through).
- Tempo-synced 1/16 delay, low-pass feedback, saturation, basic envelope-based ducking.
- Six controls: Rumble, Decay, Drive, Tone, Duck, Output.
- Parameter state saved in DAW project.
- Initial dark Industrial-style UI.

## Not implemented in v0.1
- External sidechain bus, drag-and-drop kick sample, auto kick analysis, adaptive reverb, context analysis, presets, Mix Advisor, learning, advanced UI, multi-band DSP.
- The first version expects audio on its main input. Route the Kick audio to the plugin track; monitor the original Kick separately.
- This is a **prototype**, not the completed v1.0 specification.

## Build without installing developer tools locally
1. Extract this ZIP and upload the files **including `.github/workflows/build-windows.yml`** to the root of your GitHub repository. The GitHub web uploader may not handle hidden directories well; use **Add file > Create new file** for `.github/workflows/build-windows.yml` if needed.
2. Open the repository's **Actions** tab and select **Build Windows VST3**. The workflow should run after push to `main` or `master`; alternatively click **Run workflow**.
3. After a successful run, open the workflow run and download the artifact `HoltertDiPolter-v0.1-Windows-VST3`.
4. Copy the extracted `.vst3` bundle into `C:\Program Files\Common Files\VST3\` and rescan plugins in Ableton Live 12.
5. Test with low speaker/headphone volume first; keep the dry Kick on its own track.

## Important
- GitHub Actions requires internet access to fetch JUCE during CMake configuration.
- The workflow and C++ code have not been compiled on a Windows runner yet. Build issues may require a small correction.
- JUCE has licensing terms. Review the JUCE license before distribution or commercial use.
- v0.1 may not yet expose an input configuration suitable for every Ableton routing setup; routing must be tested.
