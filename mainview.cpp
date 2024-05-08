//
// Created by qjming on 2024/5/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainView.h" resolved

#include <QFileDialog>
#include <QMessageBox>
#include  "MIDIPlayer.h"
#include "mainview.h"
#include "ui_MainView.h"


MainView::MainView(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainView),
        player(new MIDIPlayer()),
        pianoWidget(new PianoWidget(this)),
        pictureWidget(new PictureWidget(this)) {
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    pianoWidget->setGeometry(20, 20, 1200, 100);
    pictureWidget->setGeometry(20, 140, 1000, 400);
    player->setPianoWidget(pianoWidget);
    connect(ui->chooseMidi, &QPushButton::clicked, this, &MainView::chooseFile);
    connect(ui->playMidi, &QPushButton::clicked, this, &MainView::play);
}

MainView::~MainView() {
    delete ui;
}

void MainView::chooseFile() {
    filename = QFileDialog::getOpenFileName(this, "选择文件", "", "MIDI文件(*.mid)");
    // 选择文件后，将文件名显示在按钮上 仅显示文件名
    auto pos = filename.toStdString().find_last_of('/');
    if (pos != std::string::npos) {
        ui->midiName->setText(QString::fromStdString(filename.toStdString().substr(pos + 1)));
    } else {
        ui->midiName->setText("选择文件");
    }
}

void MainView::play() {
    static bool is_playing = false;

    if (is_playing) {
        ui->playMidi->setText("播放");
        is_playing = false;
        player->stop();
    } else {
        if (filename.isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please choose a file first!");
            return;
        }
        ui->playMidi->setText("停止");
        is_playing = true;
        player->play(filename);
    }

}


