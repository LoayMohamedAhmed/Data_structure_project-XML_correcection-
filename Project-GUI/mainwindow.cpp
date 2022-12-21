#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

int prev = 0;
void MainWindow::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    prev = 1;
}


void MainWindow::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    prev = 2;
}

QString filename;


void MainWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(
                    this,
                    tr("Choose"),
                    "c://",
                    "XML File (*.XML)"
                    );
        //QFile file (QFileDialog::getOpenFileName(
        //            this,
        //            tr("Choose"),
        //            "c://",
        //            "Text File (*.XML)"
        //            ));


        QTextStream in(&filename);
        ui->lineEdit->setText(in.readAll());



        QString file1 = ui->lineEdit->text();
            QFile file2(file1);
            file2.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream out2(&file2);
            ui->textBrowser->setText(out2.readAll());



}


void MainWindow::on_pushButton_2_clicked()
{
    QString inputText;
    QFile file("C:\\Users\\shoro\\OneDrive\\Desktop\\name.xml");
    if(file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        inputText = ui->textEdit->toPlainText();
        stream <<inputText;

    }
    file.close();
    QTextStream out2(&file);
    ui->textBrowser->setText(inputText);

    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_actionHome_Page_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->textBrowser->clear();

}


void MainWindow::on_actionReturn_triggered()
{
    int curr = this->ui->stackedWidget->currentIndex();

    if(curr == 1){

        this->ui->stackedWidget->setCurrentIndex(0);

    }
    else if(curr == 2){

        this->ui->stackedWidget->setCurrentIndex(0);

    }
    else if(curr == 3){
        if(prev == 1)
            this->ui->stackedWidget->setCurrentIndex(1);
        else if(prev == 2)
            this->ui->stackedWidget->setCurrentIndex(2);
    }
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_11_clicked()
{
    /*QFile file (filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //if(!file.open(QIODevice::ReadOnly))
    //    QMessageBox::information(0,"info",file.errorString());


    QTextStream out(&file);
    ui->textBrowser->setText(out.readAll());*/

    QString file1 = ui->lineEdit->text();
        QFile file2(file1);
        file2.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream out2(&file2);
        ui->textBrowser->setText(out2.readAll());



     ui->stackedWidget->setCurrentIndex(3);
}

