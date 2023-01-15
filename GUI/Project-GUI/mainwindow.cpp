#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <iostream>
#include <XML.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    previous = 1;
}


void MainWindow::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    previous = 2;
}



void MainWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("Choose"),"c://","XML File (*.XML)");
    QTextStream in(&filename);
    ui->lineEdit->setText(in.readAll());
    QString file1 = ui->lineEdit->text();
    QFile file2(file1);
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    max_size = file2.size();
    text = file2.readAll();
    q = text.toStdString();
    QTextStream myfile_stream(&file2);
    ui->textBrowser->setText(text);

}


void MainWindow::on_pushButton_2_clicked()
{

    q = "";
    QString inputText;
    QFile file("F:\\Qt\\Project\\sample.xml");
    if(file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        inputText = ui->textEdit->toPlainText();
        stream <<inputText;

    }
    file.close();
    QTextStream out2(&file);
    ui->textBrowser->setText(inputText);
    q = inputText.toStdString();
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
    ui->textEdit->clear();

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
        if(previous == 1)
            this->ui->stackedWidget->setCurrentIndex(1);
        else if(previous == 2)
            this->ui->stackedWidget->setCurrentIndex(2);
    }
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_11_clicked()
{


    QString file1 = ui->lineEdit->text();
    QFile file2(file1);
    file2.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream out2(&file2);
    ui->textBrowser->setText(out2.readAll());

    //Go to options page
    ui->stackedWidget->setCurrentIndex(3);
}



//Detecting Errors Button
void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::warning(this,"Error Detecting Window",check_errors(q));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
}

