# HoltertDiPolter Rumble Maker – Arbeitsanweisungen

Privates VST3-Plugin (C++ / JUCE / CMake) für Schranz / Hard Techno. Ziel: aus einer Kick einen druckvollen, groovenden Rumble erzeugen, der mit Kick und Percussion wie aus einem Guss klingt. Klangqualität und Mix-Integration gehen vor Funktionsumfang.
Plattform: Windows 11, Ableton Live 12 Suite, VST3 64 Bit. Roadmap: `ROADMAP.md`.

## Arbeitsregel (verbindlich)
**Vor jedem Arbeitsauftrag nennst du dem Nutzer das ideale Modell und Reasoning für diese Aufgabe und wartest auf sein OK.** Richtwerte stehen je Version in `ROADMAP.md`.

## Grundprinzipien
1. Das Repository ist die Quelle der Wahrheit. Keine Annahmen über Dateistand oder Branch, erst nachsehen.
2. Nie erfundene Hörtests, CPU-Messungen oder getestete Features melden. Ein grüner Build beweist nur Kompilierbarkeit, nicht Klang oder Host-Kompatibilität. Ungetestetes ausdrücklich kennzeichnen.
3. Keine neue Version, bevor die vorherige in Ableton gehört und getestet wurde. Funktionierende Stände als Tag erhalten.
4. Der Nutzer hat gern Widerspruch. Bei Unklarheit fragen. Wenn er sich in einem Thema verrennt, sag es ihm.
5. Sprache: Gespräch und `ROADMAP.md` auf Deutsch, Code, UI-Texte und README auf Englisch.

## Technik
- Audio-Thread: keine Allokationen, kein Blockieren, keine Datei-I/O. Analyse außerhalb des Audio-Threads. Parameter glätten, Feedback begrenzen, Ausgangspegel absichern.
- Zu testen: Stille, Tempo- und Samplerate-Wechsel, Puffergrößen, Mono/Stereo, DAW-Stop, Preset-State, mehrere Instanzen.
- Erste Hörtests bei geringer Lautstärke.
- JUCE-Lizenz vor Weitergabe oder kommerzieller Nutzung prüfen.
- Windows-Build: lokal mit Visual Studio, zusätzlich CI über `.github/workflows/build-windows.yml`.
- Kein Commit mit Quellcode-Änderungen ohne Absprache. Reine Doku-Commits dürfen `[skip ci]` tragen.
