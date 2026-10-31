# HoltertDiPolter Rumble Maker v0.1

First **experimental** JUCE VST3 prototype for Windows 11 / Ableton Live 12. See [ROADMAP.md](ROADMAP.md) for the planned versions.

## Status
- The Windows build via GitHub Actions was reported **green** by the project owner.
- **Not yet tested in Ableton** (loading, controls, sound). A green build only proves that the code compiles.

## Implemented
- Real-time kick audio input; **rumble-only** output (dry input is not passed through).
- Tempo-synced 1/16 delay, low-pass feedback, saturation, basic envelope-based ducking.
- Six controls: Rumble, Decay, Drive, Tone, Duck, Output.
- Parameter state is saved in the DAW project.
- Initial dark UI.

## Not implemented in v0.1
- External sidechain bus, drag-and-drop kick sample, auto kick analysis, reverb, context analysis, presets, Mix Advisor, learning, advanced UI, multi-band DSP.
- The kick must arrive on the plugin's main input. Keep the original kick on its own track.
- This is a **prototype**, not the finished product.

## Build without a local toolchain
1. Open the repository's **Actions** tab and select **Build Windows VST3**.
2. It runs on every push to `main`/`master`, or start it with **Run workflow**.
3. After a successful run, download the artifact `HoltertDiPolter-v0.1-Windows-VST3` (a ZIP) and extract it.

## Install (Windows)
1. Copy the **complete** `HoltertDiPolter Rumble Maker.vst3` folder (not only the file inside) to `C:\Program Files\Common Files\VST3\`. This needs administrator rights.
2. In Ableton Live 12: Preferences → Plug-ins → enable **Use VST3 System Folders**, then rescan (hold Alt for a deep rescan).
3. The plugin appears under Plug-ins → VST3. Dragging the file into the Ableton window does **not** install it.
4. Test at low monitoring volume first.

## Important
- GitHub Actions needs internet access to fetch JUCE during CMake configuration.
- JUCE has licensing terms. Review the JUCE license before distribution or commercial use.
- Routing behaviour in Ableton is still to be verified.
