#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionSave_triggered();

    void on_actionHome_Page_triggered();

    void on_actionReturn_triggered();

    void on_actionQuit_triggered();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_Search_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_Search_5_clicked();

    void on_Search_4_clicked();

    void on_Search_6_clicked();

    void on_Search_7_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
