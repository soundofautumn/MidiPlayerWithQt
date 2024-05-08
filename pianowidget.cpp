//
// Created by qjming on 2024/5/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PianoWidget.h" resolved

#include "pianowidget.h"
#include <QPainter>

PianoWidget::PianoWidget(QWidget *parent) : QWidget(parent) {
    for (bool &key: keys) {
        key = false;
    }
}

PianoWidget::~PianoWidget() = default;

void PianoWidget::clearKeys() {
    for (bool &key: keys) {
        key = false;
    }
    update();
}

void PianoWidget::setKeyPressed(int key, bool pressed) {
    if (key >= 0 && key < 128) {
        keys[key] = pressed;
        update();  // trigger a repaint
    }
}

void PianoWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    // draw the piano keys here
    // if keys[i] is true, draw the key as pressed

    const int w_k_width = 20;
    const int w_k_height = 100;
    const int b_k_width = 10;
    const int b_k_height = 60;


    // white keys
    for (int i = 0; i < 52; ++i) {
        if (keys[i]) {
            // 白键按下
            painter.setBrush(Qt::gray);
        } else {
            // 白键未按下
            painter.setBrush(Qt::white);
        }
        painter.drawRect(i * 20, 0, w_k_width, w_k_height);
    }
    // black keys
    for (int i = 52; i < 88; ++i) {
        if (keys[i]) {
            // 黑键按下
            painter.setBrush(Qt::yellow);
        } else {
            // 黑键未按下
            painter.setBrush(Qt::black);
        }
        // 转化为相对于白键的坐标
        int j = i - 52;
        // 0度
        if (j == 0) {
            painter.drawRect(20 * 1 - 5, 0, b_k_width, b_k_height);
            continue;
        }
        int n = (j - 1) / 5;
        int m = (j - 1) % 5;
        switch (m) {
            case 0:
                painter.drawRect(40 + 20 * (n * 7 + 1) - 5, 0, b_k_width, b_k_height);
                break;
            case 1:
                painter.drawRect(40 + 20 * (n * 7 + 2) - 5, 0, b_k_width, b_k_height);
                break;
            case 2:
                painter.drawRect(40 + 20 * (n * 7 + 4) - 5, 0, b_k_width, b_k_height);
                break;
            case 3:
                painter.drawRect(40 + 20 * (n * 7 + 5) - 5, 0, b_k_width, b_k_height);
                break;
            case 4:
                painter.drawRect(40 + 20 * (n * 7 + 6) - 5, 0, b_k_width, b_k_height);
                break;
        }
    }

}