#include "user_configurationW.h"
#include "ui_user_configurationW.h"
#include "userM.h"
#include <QMessageBox>
#include <QIntValidator>

user_configuration::user_configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_configuration)
{
    ui->setupUi(this);
}

user_configuration::~user_configuration()
{
    delete ui;
}



void user_configuration::on_ceate_1_clicked()
{

        int id=ui->lineEdit_ID_1->text().toInt();
            QString password=ui->lineEdit_password_1->text();
             int degree=ui->comboBox_degree_1->currentText().toInt();


             user b(id,password,degree);
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



void user_configuration::on_update_3_clicked()
{

            int ID=ui->lineEdit_insert_ID_3->text().toInt();
              QString password=ui->lineEdit_change_password_3->text();
                int degree=ui->comboBox_degree_3->currentText().toInt();




            user E1 (ID,password,degree);
             bool test=E1.modify();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
    ui->user_table_3->setModel(E1.show());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}


void user_configuration::on_delete_4_clicked()
{
    user s;
    s.setID(ui->lineEdit_ID_4->text().toInt());
    bool test=s.erase(s.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->user_table_3->setModel(s.show());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}
