#include "loginW.h"
#include "userM.h"
#include "vip_weddingM.h"
#include "user_configurationW.h"
#include "vip_weddingW.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion_bd.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion_base c;
    bool test=c.ouvrirConnexion();
    login w;
         if(test)
         {

             w.show();
             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("connection successful.\n""Click Cancel to exit."), QMessageBox::Ok);

             // qDebug()<<"Connection successful";
             login login;
             login.setModal(true);
             login.exec();
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}

