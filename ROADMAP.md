# HoltertDiPolter Rumble Maker – Versions-Roadmap

Jede Version endet mit einem **Hörtest in Ableton Live 12**. Ein grüner Build beweist nur Kompilierbarkeit, nicht Klang oder Host-Kompatibilität.
Die Reihenfolge ist gegenüber dem ersten Plan bewusst umgestellt: erst Signalweg und Routing, dann die Intelligenz.

## Regeln
1. Keine neue Version, bevor die vorherige gehört und in Ableton getestet wurde.
2. Jede Version bleibt als Tag im Repo erhalten (Rückfall-Stand).
3. „Option“ heißt: wird nur gebaut, wenn der Klang es braucht, nicht weil es in der Spezifikation steht.
4. Nach 0.9 kommen keine neuen Features mehr in 1.0, nur Fehlerbehebung.

## Bis 1.0

### 0.1.1 – Abnahme des Prototyps (nächster Schritt)
- Plugin korrekt installieren (kompletten `.vst3`-Ordner nach `C:\Program Files\Common Files\VST3\`, Rescan) und in Ableton laden.
- Sechs Regler, Rumble-only, Knacksen, Pegel, Stille und DAW-Stop prüfen.
- README korrigieren, `PLUGIN_CODE` bereinigen, Tag `v0.1` setzen.
- Lokalen Build mit Visual Studio auf dem Gaming-PC einrichten.

**Abnahme:** Plugin lädt, erzeugt hörbaren Rumble ohne Pegelsprünge oder Abstürze.
**Modell:** Sonnet 5.5, Reasoning medium

### 0.2 – Rumble-Engine
- Reverb seriell hinter dem Delay, Tails mit abnehmender Dichte, Bass klingt schneller aus.
- Vierband-Distortion mit 2x Oversampling, DC-Blocker, Soft-Clip, Feedback-Begrenzung.
- Parameterglättung, Anti-Click-Rampe bei DAW-Stop, sauberes Verhalten bei Tempo- und Samplerate-Wechsel.
- Testsuite: Stille, Feedback-Stabilität, Puffergrößen, Mono/Stereo, CPU-Messung.

**Abnahme:** Mit drei verschiedenen Referenz-Kicks klingt das Ergebnis nach Rumble und bleibt stabil.
**Modell:** Opus 5.5, Reasoning high

### 0.3 – Kick-Trigger und Sidechain
- Zuverlässige Kick-Erkennung statt der einfachen Schwelle aus v0.1.
- Externer Sidechain-Eingang für das Routing in Ableton; der Hauptbus bleibt als Alternative.
- Start mitten im Track auf den nächsten Kick; bei Kick-Pause stoppt der Rumble.
- Frequenzselektives Ducking vor der nächsten Kick.

**Abnahme:** Rumble sitzt im Loop tight auf der Kick, auch bei Pausen und Ghost-Kicks.
**Modell:** Opus 5.5, Reasoning high

### 0.4 – Kick-Analyse und AUTO/LEARN/FREEZE
- Analyse im Hintergrundthread: Tonhöhe mit Unsicherheitsangabe, Länge, Hüllkurve.
- Parametervorschläge mit Hysterese, damit nicht bei jeder kleinen Variation umgestellt wird.
- Sample-Modus: Kick per Drag-and-drop ins Plugin, automatischer Vierteltakt.
- Manuelle Werte haben Vorrang vor der Automatik.

**Abnahme:** AUTO liefert bei drei Kicks hörbar passende Einstellungen, ohne dass nachgeregelt werden muss.
**Modell:** Opus 5.5, Reasoning high

### 0.5 – Groove und Mix-Integration
- Rumble pulsiert zwischen den Kicks und schafft Platz vor der nächsten.
- Groove Fusion mit optionalem Percussion-Sidechain.
- Auto-EQ, adaptive Kompression, Sub mono, höhere Anteile adaptiv stereo.
- Output-Pegel mit Headroom, Peak/RMS-gestützt.

**Abnahme:** In einem echten Schranz-Loop klingt der Rumble wie aus einem Guss mit Kick und Percussion.
**Modell:** Opus 5.5, Reasoning high

### 0.6 – Industrial-UI, Presets, Undo
- Easy- und Advanced-Modus, Echtzeit-Spektrum, Status von AUTO/LEARN/FREEZE.
- Kick-adaptive Presets und User-Presets, Undo/Redo.
- Feste Fenstergröße, Look nach dem Mock-up.

**Abnahme:** Alle Funktionen sind ohne Handbuch bedienbar; Projekte laden mit Presets korrekt.
**Modell:** Sonnet 5.5, Reasoning medium

### 0.9 – Beta
- Hörtests mit vielen Kicks und Genres, Regressionstests, CPU-Messung.
- pluginval und Test unter Ableton mit mehreren Instanzen.
- JUCE-Lizenz klären, portable Installation und Installationsanleitung.

**Abnahme:** Keine bekannten Abstürze, keine Pegel- oder Klickprobleme in zwei Wochen Praxis.
**Modell:** Opus 5.5, Reasoning high für die Fehlersuche

### 1.0 – Release
- Nur Fehlerbehebung und Dokumentation, keine neuen Features.
- Release-Tag und gesicherter Rückfall-Stand im Repo.

**Abnahme:** Das Plugin läuft in einem echten Track und würde nicht mehr getauscht.
**Modell:** Sonnet 5.5, Reasoning medium

## Nach 1.0

### 1.1 – Mix Advisor light
- Spektrum von Kick und Rumble mit markierten Konfliktbereichen und kurzen Hinweisen.
- Optionaler Drum-Kontext (Percussion, Loops) nur zur Analyse.
- Empfehlungen einzeln oder gesammelt übernehmen, mit Undo.

**Abnahme:** Die Hinweise treffen bei fünf eigenen Tracks in mindestens vier Fällen zu.
**Modell:** Sonnet 5.5, Reasoning high

### 1.2 – Workflow-Komfort
- A/B-Vergleich mit Lautheitsabgleich.
- Preset-Browser, Deterministic-Modus mit gespeichertem Seed.
- Offline-Render klingt wie Echtzeit.

**Abnahme:** Bounce und Echtzeit sind bei gleichem Seed identisch.
**Modell:** Sonnet 5.5, Reasoning medium

### 1.3 – Klangqualität (Option)
- 4x Oversampling bei Bedarf, optional Linear-Phase-Crossover (Latenz beachten).
- Dynamic EQ und ein zweiter Reverb-Algorithmus, nur bei hörbarem Mehrwert.
- A/B-Hörtest gegen die vorherige Version.

**Abnahme:** Im Blindtest hörbar besser, sonst wird es nicht übernommen.
**Modell:** Opus 5.5, Reasoning high

### 2.0 – Lernen und Erweiterungen (Option)
- Projektbezogene Präferenzen pro Kick, ohne Cloud.
- Build- und Drop-Erkennung als Vorschlag; Score 0–100 als rein technische Orientierung.
- Weitere Formate (AU, CLAP) und Installer, falls weitere Nutzer dazukommen.

**Abnahme:** Nur starten, wenn 1.x im Alltag stabil läuft und echter Bedarf besteht.
**Modell:** Fable 5.1 oder Opus 5.5, Reasoning high
