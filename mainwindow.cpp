#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

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




void MainWindow::on_suwak_1_valueChanged(int value)
{
    ui->widget->setValue1(value);
    ui->widget->changed();
    string liczba=to_string(value);
    ui->label->setText(QString::fromStdString(liczba));
}


void MainWindow::on_suwak_2_valueChanged(int value)
{

    ui->widget->setValue3(value);
    ui->widget->changed();
    string liczba=to_string(value);
    ui->label_2->setText(QString::fromStdString(liczba));
}


void MainWindow::on_suwak_3_valueChanged(int value)
{
    ui->widget->setValue2(value);
    ui->widget->changed();
    string liczba=to_string(value);
    ui->label_3->setText(QString::fromStdString(liczba));
}

