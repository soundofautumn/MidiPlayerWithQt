//
// Created by Qjming on 2023/6/28.
//
#include "MIDIPlayer.h"
#include "thread"
#include "conio.h"
#include <fstream>

MIDIPlayer::MIDIPlayer() {
    midiOutOpen(&hMidiOut, MIDIMAPPER, 0, 0, 0);// 打开MIDI播放设备
}

MIDIPlayer::~MIDIPlayer() {
    midiOutClose(hMidiOut);
}

void MIDIPlayer::setPianoWidget(PianoWidget *_pianoWidget) {
    this->pianoWidget = _pianoWidget;
}

void MIDIPlayer::stop() {
    is_playing = false;
    midiOutShortMsg(hMidiOut, 0x00B0);
    pianoWidget->clearKeys();
}

void MIDIPlayer::play_track() {
    midiOutShortMsg(hMidiOut, 0x00B0);
    smf::MidiEventList &event_list = midiFile[0];
    double seconds = 0;
    for (int i = 0; i < event_list.getSize(); ++i) {
        if (!is_playing) {
            break;
        }
        smf::MidiEvent &event = event_list[i];
        QDebug debug = qDebug();
        debug << " Tick: " << event.tick << " Seconds: " << event.seconds;
        debug << " Command: " << event.getCommandByte() << " Data1: " << event[1] << " Data2: " << event[2];
        if (event.isMetaMessage()) {
            debug << " Meta: " << event.getMetaType();
            continue;
        }
        if (event.isNoteOn()) {
            pianoWidget->setKeyPressed(event.getKeyNumber(), true);
        } else if (event.isNoteOff()) {
            pianoWidget->setKeyPressed(event.getKeyNumber(), false);
        }
        midiOutShortMsg(hMidiOut, event[0] | (event[1] << 8) | (event[2] << 16));
        if (seconds < event.seconds) {
            std::this_thread::sleep_for(std::chrono::milliseconds((int) ((event.seconds - seconds) * 1000)));
            seconds = event.seconds;
        }
    }
    this->stop();
}

void MIDIPlayer::play(const QString &filename) {
    std::fstream file;
    file.open(filename.toStdWString().c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        printf("Error: could not open MIDI file.\n");
        return;
    }
    if (!midiFile.read(file)) {
        printf("Error: could not read MIDI file.\n");
        return;
    }
    midiFile.joinTracks();
    midiFile.doTimeAnalysis();
    is_playing = true;
    std::thread(&MIDIPlayer::play_track, this).detach();
    // 按回车键停止播放
    std::thread([this] {
        while (is_playing);
        this->stop();
    }).detach();
}

