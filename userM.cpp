#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include "userM.h"

user::user()
{ degree=0; ID=0;
    password="";

}

 user::user(int ID,QString password,int degree)
 {

this->ID=ID; this->password=password;this->degree=degree;

 }
   int user:: getID(){return ID;}
     QString user:: getpassword(){return password;}
     int user:: getdegree(){return degree;}

     void user:: setID(int ID ){this->ID=ID;}
      void user:: setpassword(QString password){this->password=password;}
      void user:: setdegree(int degree){this->degree=degree;}

      bool user:: add()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO boudinar (id,password,degree) "
                                "VALUES (:id, :password,:degree)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":password", password);
                  query.bindValue(":degree", degree);

                 return query.exec();}

      bool user::erase(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from user where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* user::show()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM boudinar");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifier"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("password"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("degree"));


        return  model;
      }
      bool user::modify()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

             query.prepare(" UPDATE user SET password=:password,degree=:degree WHERE ID=:ID");
                    query.bindValue(":password",password);
                    query.bindValue(":degree",degree);


                    return query.exec();


      }
