#ifndef USER_CONFIGURATION_H
#define USER_CONFIGURATION_H
#include "userM.h"
#include <QDialog>

namespace Ui {
class user_configuration;
}

class user_configuration : public QDialog
{
    Q_OBJECT

public:
    void on_ceate_1_clicked();

    void on_update_3_clicked();

    void on_delete_4_clicked();

    explicit user_configuration(QWidget *parent = nullptr);
    ~user_configuration();

private:
    Ui::user_configuration *ui;
};

#endif // USER_CONFIGURATION_H
