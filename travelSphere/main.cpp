#include "loginpage.h"
#include<mainwindow.h>
#include "registerpage.h"
#include <QApplication>
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //registerpage r;
    loginpage w;
    registerpage r;
    //r.show();

    w.show();
    return a.exec();
}
