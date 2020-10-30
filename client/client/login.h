#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSettings>
#include "ui_login.h"
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

public slots:
    void login_(bool p);
    void logon_(bool p);
    void isConnectServer(bool p);

private slots:
    void on_showSettingButton_clicked();
    void on_loginButton_clicked();
    void on_logonButton_clicked();

private:
    Ui::login *ui;

signals:
    void showMainWindow();
};

#endif // LOGIN_H
