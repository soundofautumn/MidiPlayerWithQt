//
// Created by qjming on 2024/5/6.
//

#ifndef MIDIPLAYER_PIANOWIDGET_H
#define MIDIPLAYER_PIANOWIDGET_H

#include <QWidget>

class PianoWidget : public QWidget {
Q_OBJECT

public:
    explicit PianoWidget(QWidget *parent = nullptr);

    ~PianoWidget() override;

    void setKeyPressed(int key, bool pressed);

    void clearKeys();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool keys[128]{};
};


#endif //MIDIPLAYER_PIANOWIDGET_H
