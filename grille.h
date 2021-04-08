#ifndef GRILLE_H
#define GRILLE_H

#include <QObject>
#include<string>
using namespace std;

class Grille : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<QList<QString>> values MEMBER valeurs NOTIFY valChanged)
    Q_PROPERTY(QList<QList<QString>> colors MEMBER colors NOTIFY focusChanged)
    Q_PROPERTY(int verifier MEMBER verif NOTIFY verifClicked)

public:
    explicit Grille(QObject *parent = nullptr);
    Q_INVOKABLE void changer_valeur(int valeur, int Carre,int Case);
    Q_INVOKABLE void colorer_voisins( int Carre,int Case, bool focus);
    Q_INVOKABLE void verif_matrice( );
    void Print();


private:
    void matriceToVectors();
    void colorer_X(int i, int l );
    void colorer_Y(int i, int c );
    QList<QList<QString>> colors;   // contient les couleurs de chaque case
    QList<QList<QString>> valeurs;  // contient les valeurs de chaque case sous forme de Qstring
    string grille[9][9];            // contient les valeurs de chaque case sous forme de string
    int verif;


signals:
    void valChanged();
    void focusChanged();
    void verifClicked();

};

#endif // GRILLE_H
