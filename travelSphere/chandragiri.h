#ifndef CHANDRAGIRI_H
#define CHANDRAGIRI_H

#include <QDialog>

namespace Ui {
class chandragiri;
}

class chandragiri : public QDialog
{
    Q_OBJECT

public:
    explicit chandragiri(QWidget *parent = nullptr);
    ~chandragiri();

private:
    Ui::chandragiri *ui;
};

#endif // CHANDRAGIRI_H
