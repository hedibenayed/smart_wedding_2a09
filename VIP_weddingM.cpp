#include "vip_weddingM.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
vip_wedding::vip_wedding()
{ price=0; ID=0;
    plan=name=place="";

}

 vip_wedding::vip_wedding(int ID,QString name,QString place,QString plan,int price)
 {

this->ID=ID; this->name=name; this->place=place; this->plan=plan;this->price=price;

 }
   int vip_wedding:: getID(){return ID;}
    QString  vip_wedding::getname(){return name;}
     QString vip_wedding:: getplace(){return place;}
     QString vip_wedding:: getplan(){return plan;}
     int vip_wedding:: getprice(){return price;}

     void vip_wedding:: setID(int ID ){this->ID=ID;}
      void vip_wedding:: setname(QString name ){this->name=name;}
      void vip_wedding:: setplace(QString place ){this->place=place;}
      void vip_wedding:: setplan(QString plan){this->plan=plan;}
      void vip_wedding:: setprice(int price){this->price=price;}

      bool vip_wedding:: add()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO vip_wedding (id, name, place,plan,price) "
                                "VALUES (:id, :name, :place, :plan,:price)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":name", name);
                  query.bindValue(":place", place);
                  query.bindValue(":plan", plan);
                  query.bindValue(":price", price);

                 return query.exec();}

      bool vip_wedding::erase(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from boudinar where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* vip_wedding::show()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM boudinar");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("place"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("plan"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));


        return  model;
      }
      bool vip_wedding::modify()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

             query.prepare(" UPDATE vip_wedding SET ID=:ID,name=:name_vip_wedding,place=:place_vip_wedding,plan=:plan,price=:price WHERE ID=:ID");
                    query.bindValue(":ID", id_string);
                    query.bindValue(":name_vip_wedding",name);
                       query.bindValue(":place_vip_wedding",place);
                    query.bindValue(":plan",plan);
                    query.bindValue(":price",price);


                    return query.exec();


      }
