#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->login=new Login();
    this->login->show();
    this->client = new QTcpSocket(this);
    connect(login, &Login::showMainWindow, this, &MainWindow::showMainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow(){
    this->show();
}
