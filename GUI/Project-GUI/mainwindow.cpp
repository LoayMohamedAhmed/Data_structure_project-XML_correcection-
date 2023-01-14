#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <iostream>
#include <XML.h>

int previous = 0;     //For storing the previous stack page
int max_size=0;     //For storing the size of the input file
QString filename;   //For storing the path in the path
QString text;      //For storing the content of the file in QString


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}


QString check_errors(string data)
{

    stack<char> characters;
    stack<tag> errors_miss;
    stack<tag> errors_miss1;
    stack<tag> errors_wrong_poss;
    stack<tag> errors_wrong_poss1;
    deque<tag> tags;
    deque<tag> temp;
    string message;
    int i =0;
    tag T;
    int mark = 0;
    int k = 50;

    while(i<data.size())
    {

        if(data[i]=='<')
        {

            int k=i;
            mark++;
            do
            {
                  characters.push(data[k]);
                  k++;

            }
            while(data[k]!='>');
            characters.push(data[k]);
            int size1 = characters.size() - 1;
            char temp_array[size1 + 1];



            for (int j = size1; j >= 0; j--)
            {
                temp_array[j] = characters.top();
                characters.pop();
            }
            T.s = conv_to_string(temp_array, size1 + 1);
            T.index = k;
            if (mark==1)
            {
                tags.push_front(T);
            }

            if (!tags.empty() && mark != 1)
            {
                if (compare1(T.s, tags.front().s))
                {

                    tags.pop_front();
                }
                else
                {
                    tags.push_front(T);
                }
            }
            i = k;
        }
        i++;
    }
    if(tags.empty())
    {

        message+="No errors found";

    }
    else
    {

        while(!tags.empty())
        {
            if(compare1(tags.front().s,tags.back().s))
            {
                tags.pop_front();
                tags.pop_back();
            }
            else
            {
                while(!tags.empty())
                {
                    if(compare1(tags.front().s,tags.back().s))
                    {
                       errors_wrong_poss.push(tags.back());
                       errors_wrong_poss.push(tags.front());
                       tags.pop_front();
                       tags.pop_back();
                       break;
                    }
                    else
                    {
                        if (tags.size() == 1)
                        {
                            errors_miss.push(tags.front());
                            tags.pop_front();
                            break;
                        }
                        temp.push_front(tags.front());
                        tags.pop_front();
                    }
                }
                while(!temp.empty())
                {

                    tags.push_front(temp.front());
                    temp.pop_front();
                }
            }
        }


        while(!errors_miss.empty())
        {

            errors_miss1.push(errors_miss.top());
            int num =order(data,errors_miss.top().index)+1;
            //cout<<"you have an error in line "<<num<<"at tag ("<<errors_miss.top().s<<")"<<endl;
            message += "You have an error in line " + to_string(num) + " at tag (" + errors_miss.top().s+")\n";
            errors_miss.pop();
        }
        while (!errors_wrong_poss.empty())
        {

            errors_wrong_poss1.push(errors_wrong_poss.top());
            int num = order(data, errors_wrong_poss.top().index) + 1;
            //cout << "you have an error in line " << num << "at tag (" << errors_wrong_poss.top().s << ")" << endl;
            message += "You have an error in line " + to_string(num) + " at tag (" + errors_wrong_poss.top().s +")\n";
            errors_wrong_poss.pop();
        }

    }


    return QString::fromStdString(message);
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



string q;
QString browse_error_message;
void MainWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("Choose"),"c://","XML File (*.XML)");
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
    max_size = file2.size();
    text = file2.readAll();
    q = text.toStdString();
    QTextStream myfile_stream(&file2);
    ui->textBrowser->setText(text);
    browse_error_message = check_errors(q);

}

QString text_error_message;
string text_q;
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
    //max_size = file.size();
    QTextStream out2(&file);
    ui->textBrowser->setText(inputText);
    text_q = inputText.toStdString();
    browse_error_message = check_errors(text_q);
    max_size = text_q.size();
    //Go to options page
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
    QMessageBox::warning(this,"Error Detecting Window",browse_error_message);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
}

