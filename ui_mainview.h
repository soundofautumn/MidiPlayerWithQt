/********************************************************************************
** Form generated from reading UI file 'mainviewAQhjGe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINVIEWAQHJGE_H
#define MAINVIEWAQHJGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QGroupBox *groupBox;
    QPushButton *chooseMidi;
    QLineEdit *midiName;
    QPushButton *playMidi;

    void setupUi(QWidget *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName("MainView");
        MainView->resize(1100, 661);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainView->sizePolicy().hasHeightForWidth());
        MainView->setSizePolicy(sizePolicy);
        groupBox = new QGroupBox(MainView);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(780, 160, 301, 491));
        chooseMidi = new QPushButton(groupBox);
        chooseMidi->setObjectName("chooseMidi");
        chooseMidi->setGeometry(QRect(40, 200, 100, 40));
        midiName = new QLineEdit(groupBox);
        midiName->setObjectName("midiName");
        midiName->setGeometry(QRect(32, 120, 221, 20));
        midiName->setReadOnly(true);
        playMidi = new QPushButton(groupBox);
        playMidi->setObjectName("playMidi");
        playMidi->setGeometry(QRect(164, 200, 100, 40));

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QWidget *MainView)
    {
        MainView->setWindowTitle(QCoreApplication::translate("MainView", "\346\227\266\344\273\243\351\237\263\347\224\273", nullptr));
        groupBox->setTitle(QString());
        chooseMidi->setText(QCoreApplication::translate("MainView", "\351\200\211\346\213\251midi\346\226\207\344\273\266", nullptr));
        playMidi->setText(QCoreApplication::translate("MainView", "\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINVIEWAQHJGE_H
