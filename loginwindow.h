#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "tutorwindow.h"
#include "menucoordinador.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
