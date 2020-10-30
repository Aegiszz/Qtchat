#include "login.h"
#include "ui_login.h"
#include<iostream>

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::login){
    ui->setupUi(this);
    this->resize(500,240);
    connect(ui->loginButton,&QPushButton::clicked,this,&Login::login_);
}

Login::~Login(){
    delete ui;
}

void Login::login_(bool p){
    if(p){
        emit showMainWindow();
        this->close();
    }else{
        ui->statusLabel->setText("登陆失败");
        ui->statusLabel->setStyleSheet("color:red;");
    }
}

void Login::logon_(bool p){
    if(p){
        ui->statusLabel->setText("注册成功，请登录");
        ui->statusLabel->setStyleSheet("color:green;");
    }else{
        ui->statusLabel->setText("注册失败");
        ui->statusLabel->setStyleSheet("color:red;");
    }
}

void Login::on_showSettingButton_clicked(){
    if(this->height()==240){
        this->resize(500,400);
    }else{
        this->resize(500,240);
    }
}

void Login::on_loginButton_clicked(){
    std::cout<<ui->userLineEdit->text().toLocal8Bit().toStdString()<<std::endl;
    std::cout<<ui->passwordLineEdit->text().toLocal8Bit().toStdString()<<std::endl;
}

void Login::on_logonButton_clicked(){
    if(ui->userLineEdit->text().length()<4||ui->passwordLineEdit->text().length()<6){
        ui->statusLabel->setText("用户名或密码长度太小");
        ui->statusLabel->setStyleSheet("color:red;");
    }else{
        ui->statusLabel->setText("注册成功");
        ui->statusLabel->setStyleSheet("color:green;");
    }
}

void Login::isConnectServer(bool p){
    if(p){
        this->ui->statusLabel->setText("服务器已连接");
        this->ui->statusLabel->setStyleSheet("color:green;");
        this->ui->loginButton->setEnabled(true);
    }else{
        this->ui->statusLabel->setText("服务器未连接");
        this->ui->statusLabel->setStyleSheet("color:red;");
        this->ui->loginButton->setEnabled(false);
    }
}



