#ifndef VIP_WEDDINGW_H
#define VIP_WEDDINGW_H
#include "vip_weddingM.h"
#include <QDialog>
#include <QWidget>

namespace Ui {
class VIP_Wedding;
}

class VIP_Wedding : public QDialog
{
    Q_OBJECT

public:

    explicit VIP_Wedding(QWidget *parent = nullptr);
    ~VIP_Wedding();

private:
    void on_add_1_clicked();

    void on_cancel_1_clicked();

    void on_update_3_clicked();

    void on_delete_4_clicked();

    Ui::VIP_Wedding *ui;
    vip_wedding tmpVIP_Wedding;
};

#endif // VIP_WEDDINGW_H
