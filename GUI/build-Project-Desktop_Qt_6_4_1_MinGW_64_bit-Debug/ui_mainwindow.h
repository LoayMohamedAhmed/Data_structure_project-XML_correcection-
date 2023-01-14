/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *browse;
    QTextEdit *monetor;
    QPushButton *ok;
    QLineEdit *path;
    QPushButton *textinput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        browse = new QPushButton(centralwidget);
        browse->setObjectName("browse");
        browse->setGeometry(QRect(650, 40, 121, 41));
        monetor = new QTextEdit(centralwidget);
        monetor->setObjectName("monetor");
        monetor->setGeometry(QRect(30, 140, 741, 311));
        ok = new QPushButton(centralwidget);
        ok->setObjectName("ok");
        ok->setGeometry(QRect(530, 90, 101, 41));
        path = new QLineEdit(centralwidget);
        path->setObjectName("path");
        path->setGeometry(QRect(60, 40, 571, 41));
        textinput = new QPushButton(centralwidget);
        textinput->setObjectName("textinput");
        textinput->setGeometry(QRect(490, 480, 281, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        ok->setText(QCoreApplication::translate("MainWindow", "ok", nullptr));
        textinput->setText(QCoreApplication::translate("MainWindow", "write it yourself", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
