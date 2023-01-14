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
//#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHome_Page;
    QAction *actionSave;
    QAction *actionReturn;
    QAction *actionQuit;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *page_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QWidget *page_3;
    QLabel *label_3;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QWidget *page_4;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menufile;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(756, 663);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        actionHome_Page = new QAction(MainWindow);
        actionHome_Page->setObjectName("actionHome_Page");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/icons/icons8-home-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHome_Page->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/icons/icons8-save-94.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionReturn = new QAction(MainWindow);
        actionReturn->setObjectName("actionReturn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/icons/icons8-go-back-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReturn->setIcon(icon2);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/icons/icons8-close-window-94.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 741, 581));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 40, 499, 81));
        radioButton = new QRadioButton(page);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(121, 243, 231, 41));
        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(121, 150, 271, 31));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget_2 = new QWidget(page_2);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 50, 711, 111));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(530, 170, 91, 31));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 291, 31));
        textEdit = new QTextEdit(page_3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 60, 671, 261));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 330, 81, 31));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        textBrowser = new QTextBrowser(page_4);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 681, 321));
        layoutWidget = new QWidget(page_4);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 358, 661, 161));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 1, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout->addWidget(pushButton_10, 2, 1, 1, 1);

        pushButton_12 = new QPushButton(layoutWidget);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout->addWidget(pushButton_12, 2, 2, 1, 1);

        stackedWidget->addWidget(page_4);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 756, 31));
        menufile = new QMenu(menubar);
        menufile->setObjectName("menufile");
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::BottomToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menubar->addAction(menufile->menuAction());
        menufile->addAction(actionHome_Page);
        menufile->addAction(actionSave);
        menufile->addAction(actionReturn);
        menufile->addAction(actionQuit);
        toolBar_2->addAction(actionHome_Page);
        toolBar_2->addAction(actionSave);
        toolBar_2->addAction(actionReturn);
        toolBar_2->addAction(actionQuit);
        toolBar_2->addSeparator();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHome_Page->setText(QCoreApplication::translate("MainWindow", "Home Page", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionReturn->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose how do want to enter your path", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Enter file's Text", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Enter the file's path", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter The Path", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter your file as a text", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Detecting Errors", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Correcting Errors", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Prettifying", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Converting to JSON", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Minifying", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Decompressing", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Compressing", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        menufile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
