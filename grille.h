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
    Q_INVOKABLE void changer_valeur(int valeur, int grandCase,int petiteCase);
    Q_INVOKABLE void colorer_voisins( int grandCase,int petiteCase, bool focus);
    Q_INVOKABLE void verif_matrice( );


private:
    void matriceToVectors();
    void colorer_X(int i, int l );
    void colorer_Y(int i, int c );
    QList<QList<QString>> colors;
    QList<QList<QString>> valeurs;
    string grille[9][9];
    int verif;


signals:
    void valChanged();
    void focusChanged();
    void verifClicked();

};

#endif // GRILLE_H
