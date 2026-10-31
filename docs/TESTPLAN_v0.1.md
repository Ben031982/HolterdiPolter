# Testplan v0.1 – Abnahme in Ableton Live 12

Ziel: herausfinden, ob der Prototyp lädt und sinnvoll arbeitet. Ergebnisse ehrlich eintragen, auch „weiß nicht“. Erwartete Einschränkungen von v0.1 sind **keine Fehler**, sondern werden nur notiert.

**Vorbereitung**
- Monitor-/Kopfhörerlautstärke niedrig stellen.
- Artefakt `HoltertDiPolter-v0.1-Windows-VST3` herunterladen und entpacken.
- Den kompletten Ordner `HoltertDiPolter Rumble Maker.vst3` nach `C:\Program Files\Common Files\VST3\` kopieren (Administrator-Rechte).
- Ableton: Preferences → Plug-ins → „Use VST3 System Folders“ an, Rescan (Alt gedrückt = Deep-Rescan).

**Routing (v0.1 nutzt den Hauptbus)**
- Spur A „Kick“: Kick-Sample, ohne Plugin, hörbar.
- Spur B „Rumble“: dieselbe Kick als Clip, Plugin darauf. Die Ausgabe ist nur der Rumble, Spur A bleibt der Dry-Sound.
- Alternativ Spur B mit „Audio From: Spur A“ (Post FX), Monitor „In“.

## Prüfpunkte

| # | Prüfung | Erwartung | Ergebnis (ok / Fehler / Anmerkung) |
|---|---|---|---|
| 1 | Plugin erscheint unter Plug-ins → VST3 | ja | |
| 2 | Plugin lässt sich auf Spur B laden | ohne Fehlermeldung | |
| 3 | Oberfläche öffnet | Fenster mit sechs Reglern | |
| 4 | Alle sechs Regler bewegen (Rumble, Decay, Drive, Tone, Duck, Output) | jeder verändert hörbar etwas | |
| 5 | Spur A stumm, nur Spur B hören | nur Rumble, keine trockene Kick | |
| 6 | Output auf Minimum / Maximum | kein Pegelsprung, keine Übersteuerung, die weh tut | |
| 7 | Tempo ändern (z. B. 120, 150, 170 BPM) | Delay folgt dem Tempo | |
| 8 | Wiedergabe stoppen | notieren, ob und wie lange es nachklingt (siehe Hinweis) | |
| 9 | Projekt speichern, schließen, neu öffnen | Reglerstände bleiben erhalten | |
| 10 | Zweite Instanz auf einer weiteren Spur | beide laufen unabhängig | |
| 11 | Puffergröße ändern (Preferences → Audio, z. B. 128 und 512) | kein Knacken, kein Absturz | |
| 12 | Stille / Kick-Pause im Clip | keine Dauerstörgeräusche | |
| 13 | CPU-Anzeige von Ableton ablesen | Wert notieren | |

**Hinweise zu den Erwartungen**
- v0.1 ist im Kern ein tempo-synchrones Echo (1/16) mit Tiefpass, Sättigung und Ducking. Es hat **keinen Reverb**, keine Kick-Analyse und keinen Sidechain-Eingang. Dass es noch nicht nach fertigem Rumble klingt, ist zu erwarten.
- Punkt 8: Sofortiges Verstummen beim Stopp ist erst ab Version 0.2 geplant. Ein Nachklingen ist in v0.1 kein Fehler.
- Standard-Tempo ohne Host-Tempo ist 150 BPM.

## Rückmeldung an die Entwicklung
Bitte mitgeben:
1. Ausgefüllte Tabelle.
2. Falls das Plugin nicht erscheint oder nicht lädt: Screenshot der Plug-in-Liste und, wenn vorhanden, die Meldung aus Ableton.
3. Ein Satz zum Klang: Was klingt gut, was stört, was fehlt?
4. Welche Kick wurde benutzt (Dateiname) und mit welchem Tempo?
