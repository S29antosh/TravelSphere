#ifndef REGISTRYFORCOMPANIES_H
#define REGISTRYFORCOMPANIES_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>

namespace Ui {
class registryForCompanies;
}

class registryForCompanies : public QDialog
{
    Q_OBJECT

public:
    explicit registryForCompanies(QWidget *parent = nullptr);
    ~registryForCompanies();

private slots:
    void on_register_PushButton_clicked();

private:
    Ui::registryForCompanies *ui;
};

#endif // REGISTRYFORCOMPANIES_H
