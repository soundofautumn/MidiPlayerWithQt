//
// Created by qjming on 2024/5/6.
//

#ifndef MIDIPLAYER_MAINVIEW_H
#define MIDIPLAYER_MAINVIEW_H

#include <QWidget>
#include "MIDIPlayer.h"
#include "pianowidget.h"
#include "picturewidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class MainView : public QWidget {
Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);

    ~MainView() override;

private slots:
    void chooseFile();

    void play();



private:
    Ui::MainView *ui;

    QString filename;

    PianoWidget *pianoWidget = nullptr;

    PictureWidget *pictureWidget = nullptr;

    MIDIPlayer *player = nullptr;
};


#endif //MIDIPLAYER_MAINVIEW_H
