/********************************************************************************
** Form generated from reading UI file 'picturewidgetxdoguc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PICTUREWIDGETXDOGUC_H
#define PICTUREWIDGETXDOGUC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictureWidget
{
public:
    QWidget *centralwidget;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QWidget *PictureWidget)
    {
        if (PictureWidget->objectName().isEmpty())
            PictureWidget->setObjectName("PictureWidget");
        PictureWidget->resize(717, 487);
        centralwidget = new QWidget(PictureWidget);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 281, 45));
        btnPrev = new QPushButton(centralwidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setGeometry(QRect(21, 11, 75, 23));
        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(102, 11, 75, 23));
        menubar = new QMenuBar(PictureWidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 717, 23));
        statusbar = new QStatusBar(PictureWidget);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 20));

        retranslateUi(PictureWidget);

        QMetaObject::connectSlotsByName(PictureWidget);
    } // setupUi

    void retranslateUi(QWidget *PictureWidget)
    {
        PictureWidget->setWindowTitle(QCoreApplication::translate("PictureWidget", "Swiper by: GongJianBo", nullptr));
        btnPrev->setText(QCoreApplication::translate("PictureWidget", "\344\270\212\344\270\200\345\274\240", nullptr));
        btnNext->setText(QCoreApplication::translate("PictureWidget", "\344\270\213\344\270\200\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PictureWidget: public Ui_PictureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PICTUREWIDGETXDOGUC_H
