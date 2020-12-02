#ifndef LOGINW_H
#define LOGINW_H
#include "userM.h"
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class loginwn; }
QT_END_NAMESPACE

class loginwn : public QDialog
{
    Q_OBJECT

public:
    void on_connect_clicked();

    loginwn(QWidget *parent = nullptr);
    ~loginwn();

private:
    Ui::loginwn *ui;
};
#endif // LOGINW_H
