#ifndef USERM_H
#define USERM_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class user
{
public:
    user();
    user(int,QString,int);
       int getID();
        QString getpassword();
          int getdegree();
          void setID(int );
          void setpassword(QString);
          void setdegree(int);
          bool add();
          QSqlQueryModel * show();
          bool erase(int);
          bool modify();


    private:
          QString password ;
          int ID , degree;
};



#endif // USERM_H
