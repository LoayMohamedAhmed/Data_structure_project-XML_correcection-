#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include "header.h"
//#include "Graph.h"


int previous = 0;     //For storing the previous stack page
int max_size=0;     //For storing the size of the input file
QString filename;   //For storing the path in the path
QString text;      //For storing the content of the file in QString
string q;
string word;
Graph graph;
int prev_prev = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowTitle("XML Editor");

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
        previous = 1;
        prev_prev = 1;
}


void MainWindow::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
        previous = 2;
        prev_prev = 2;
}



void MainWindow::on_pushButton_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("Choose"),"c://","XML File (*.XML);; text file (*.txt)");
    QTextStream in(&filename);
    ui->lineEdit->setText(in.readAll());
    QString file1 = ui->lineEdit->text();
    QFile file2(file1);
    file2.open(QIODevice::ReadOnly | QIODevice::Text);
    max_size = file2.size();
    text = file2.readAll();
    q = text.toStdString();
    QTextStream myfile_stream(&file2);
    //ui->textBrowser->setText(text);
    ui->textBrowser->setText(QString::fromStdString(q));

}


void MainWindow::on_pushButton_2_clicked()
{

    q = "";
    filename = QFileDialog::getSaveFileName(this,tr("Save File"),"c://",tr("Text files (*.txt);;XML files (*.xml)"));
    QString inputText;
    QFile file(filename);
    if(file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        inputText = ui->textEdit->toPlainText();
        stream <<inputText;

    }
    //file.close();
    QTextStream out2(&file);
    ui->textBrowser->setText(inputText);
    q = inputText.toStdString();
    ui->textBrowser->setText(QString::fromStdString(q));
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_actionSave_triggered()
{
    filename = QFileDialog::getSaveFileName(this,tr("Save File"),"c://",tr("Text files (*.txt);;XML files (*.xml)"));
    QString inputText;
    QFile file(filename);
    if(file.open(QIODevice::Append | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        inputText = ui->textBrowser_2->toPlainText();
        stream <<inputText;

    }
    //file.close();
    QTextStream out(&file);

}


void MainWindow::on_actionHome_Page_triggered()
{

    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit->clear();
    ui->textBrowser->clear();
    ui->textEdit->clear();
    ui->textBrowser_2->clear();
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
    else if(curr == 5){
        this->ui->stackedWidget->setCurrentIndex(3);
    }
    else if(curr == 4){
        this->ui->stackedWidget->setCurrentIndex(3);
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

    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText(check_errors(q));
}



//Correction Errors
void MainWindow::on_pushButton_4_clicked()
{

    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText(error_correction(q));
}

//Prettify the file
void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText(prettifying(q));

}

//Minify the file
void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText(minifying(q));


}

//Compress the file
void MainWindow::on_pushButton_7_clicked()
{
    XMLCompress(q);
    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText("Your file has been compressed successfully, check it :)");
}

//Decompress the file
void MainWindow::on_pushButton_8_clicked()
{
    XMLDecompress();
    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText("Your file has been decompressed successfully, check it :)");
}

//Convert to JSON
void MainWindow::on_pushButton_9_clicked()
{
    ui->textBrowser_2->clear();
    ui->textBrowser_2->setText(convert_jason(q));

}


void MainWindow::on_Search_2_clicked()
{
    ui->founded->clear();
    word = ui->search_bar->text().toStdString();

    deque que = intoQueue(q);
    tree tree;
    node *node = tree.add_child(tree.root, que, 0);
    vector<string> post = searchTopic(node, word, ui->comboBox->currentIndex());

    for(int i=0; i<post.size(); i++)
    {
        if(i==0)
        {
            ui->founded->append("\t");
            ui->founded->append("name: ");
            ui->founded->append(QString::fromStdString(post[i]));
        }
        else
        {
            ui->founded->append("\t");
            ui->founded->append("post: ");
            ui->founded->append(QString::fromStdString(post[i]));
        }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    previous = 3;
}


void MainWindow::on_pushButton_12_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);
    ui->output->clear();
    previous = 3;
}


void MainWindow::on_Search_5_clicked()
{
    ui->output->clear();
    graph = build_graph(q);
    QString most_active = graph.mostActive();
    ui->output->setText(most_active);

}


void MainWindow::on_Search_4_clicked()
{
    ui->output->clear();
    graph = build_graph(q);
    QString influence = graph.influencer();
    ui->output->setText(influence);
}


void MainWindow::on_Search_6_clicked()
{
    ui->search_bar_3->clear();
    ui->output->clear();
    graph = build_graph(q);
    QString s1 = ui->search_bar_4->text();
    QString s2 = ui->search_bar_5->text();
    //QString comm = graph.common(s1.toStdString(),s2.toStdString());
    deque<string>comm;
    vector<string> vec;
    comm = graph.common(s1.toStdString(),s2.toStdString());
    for(int i=0;i<comm.size();i++)
    {
        vec.push_back(comm.back());
        comm.pop_back();
    }
    for(int i=0; i<vec.size(); i++)
    {
        ui->output->setText(QString::fromStdString(vec[i]));
    }

}



void MainWindow::on_Search_7_clicked()
{
    ui->search_bar_4->clear();
    ui->search_bar_5->clear();
    ui->output->clear();
    graph = build_graph(q);
    QString s = ui->search_bar_3->text();
    deque<string>sugg;
    vector<string> vec;
    sugg = graph.suggest(s.toStdString());
    for(int i=0;i<sugg.size();i++)
    {
        vec.push_back(sugg.back());
        sugg.pop_back();
    }
    for(int i=0; i<vec.size(); i++)
    {
        ui->output->setText(QString::fromStdString(vec[i]));
    }

}

