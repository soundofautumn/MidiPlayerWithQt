//
// Created by Qjming on 2023/6/28.
//

#ifndef MIDIEXAMPLE_MIDIPLAYER_H
#define MIDIEXAMPLE_MIDIPLAYER_H

#include "MidiFile.h"
#include "pianowidget.h"
#include <QString>
#include <windows.h>

class MIDIPlayer {
public:
    MIDIPlayer();

    ~MIDIPlayer();

    void setPianoWidget(PianoWidget *pianoWidget);

    void play(const QString &filename);

    void stop();

private:
    void play_track();

    volatile bool is_playing = false;
    HMIDIOUT hMidiOut{};
    smf::MidiFile midiFile;
    PianoWidget *pianoWidget = nullptr;
};

#endif //MIDIEXAMPLE_MIDIPLAYER_H
