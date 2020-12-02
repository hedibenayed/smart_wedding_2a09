#include "connexion_bd.h"


connexion_base::connexion_base()
{

}
bool connexion_base::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QSQLITE");

db.setDatabaseName("wedding planner 2A9");
db.setUserName("hedi");//inserer nom de l'utilisateur
db.setPassword("hedi1");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}
void connexion_base::fermerConnexion()
{db.close();}
