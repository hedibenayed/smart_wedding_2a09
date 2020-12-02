#include "vip_weddingW.h"
#include "ui_vip_weddingW.h"
#include "vip_weddingM.h"
#include <QMessageBox>
#include <QIntValidator>

VIP_Wedding::VIP_Wedding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VIP_Wedding)
{
    ui->setupUi(this);
    ui->table_VIP_Wedding_2->setModel(tmpVIP_Wedding.show());

}

VIP_Wedding::~VIP_Wedding()
{
    delete ui;
}

void VIP_Wedding::on_add_1_clicked()
{

        int id=ui->lineEdit_ID_1->text().toInt();
            QString name=ui->lineEdit_name_1->text();
            QString place=ui->lineEdit_place_1->text();
             QString plan=ui->lineEdit_plan_1->text();
             int price=ui->lineEdit_price_1->text().toInt();


             vip_wedding b(id,name,place,plan,price);
         bool test=b.add();
         /*QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }*/
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }



void VIP_Wedding::on_update_3_clicked()
{

            int ID=ui->lineEdit_ID_3->text().toInt();
            QString nom=ui->lineEdit_name_3->text();
              QString adresse=ui->lineEdit_place_3->text();
                QString typemusic= ui->lineEdit_plan_3->text();
                int prix=ui->lineEdit_price_3->text().toInt();




            vip_wedding E1 (ID,nom ,adresse,typemusic,prix);
             bool test=E1.modify();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
    ui->table_VIP_Wedding_2->setModel(E1.show());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}


void VIP_Wedding::on_delete_4_clicked()
{
    vip_wedding s;
    s.setID(ui->LineEdit_ID_4->text().toInt());
    bool test=s.erase(s.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_VIP_Wedding_2->setModel(s.show());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}
