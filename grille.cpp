#include "grille.h"
#include<iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;

Grille::Grille(QObject *parent) : QObject(parent)
{
    int i = 0;
    ifstream myFile("D:/Centrale/2A/S8/A-11_Programmation_C++/projet/Sudoku/grilles/grilleDebutant.csv");
    string ligne[9];
    while(myFile.good() & (i<9)){
        getline(myFile,ligne[0],'|');
        getline(myFile,ligne[1],'|');
        getline(myFile,ligne[2],'|');
        getline(myFile,ligne[3],'|');
        getline(myFile,ligne[4],'|');
        getline(myFile,ligne[5],'|');
        getline(myFile,ligne[6],'|');
        getline(myFile,ligne[7],'|');
        getline(myFile,ligne[8],'\n');
        for(int k=0;k<9;k++){
            if (ligne[k]!="."){
                grille[i][k]=ligne[k];
            }
        }
        i++;
    }
    matriceToVectors();

    // coloriage des cases en blanc
    QList<QString> colors_case;
    for(int i =0;i<9;i++){
        colors_case.push_back("white");
    }
    for(int j =0;j<9;j++){
        colors.push_back(colors_case);
    }

    // je vois vraiment pas à quoi sert ce bloc, peut-être à vérifier que les deux méthodes de création de liste sont identiques
//    list<string> lok;
//    lok.push_back("1");
//    lok.push_back("2");
//    lok.push_back("3");
//    lok.push_back("4");
//    lok.push_back("5");
//    lok.push_back("6");
//    lok.push_back("8");
//    lok.push_back("7");
//    lok.push_back("9");
//    list<string> lcopy = {"1", "2", "3", "4", "5", "6","7","8", "9"};
//    lok.sort();
//    bool vrai;
//    vrai = (lok == lcopy);
//    cout << vrai << endl;
}

void Grille::verif_matrice(){
    // verifie si la grille remplie par le joueur vérifie les règles du sudoku ou non

    bool victoire = true;
    list<string> lok= {"1", "2", "3", "4", "5", "6","7","8", "9"};

    // vérification par ligne
    for(int i=0; i<9; i++){
        list<string> L;
        for(int j= 0; j<9; j++){
            L.push_back(grille[i][j]);
        }
        L.sort();
        victoire = victoire && (L==lok);
    }

    // vérification par colonne
    for(int i=0; i<9; i++){
        list<string> L;
        for(int j= 0; j<9; j++){
            L.push_back(grille[j][i]);
        }
        L.sort();
        victoire = victoire && (L==lok);
    }
    // vérification par case 3x3
    for(int l=0; l<3;l++){
        for(int c = 0; c<3; c++){
            list<string> L;
            for(int i=3*l; i<3*l+3; i++){
                for(int j=3*c; j<3*c+3; j++){
                    L.push_back(grille[i][j]);
                }
            }
            L.sort();
            victoire = victoire && (L==lok);
        }
    }

    verif = victoire;
    emit verifClicked();
}

void Grille::matriceToVectors(){
    //passage d'un array nommé grille de taille 9x9 de string à valeurs qui est une QList<QList<QString>>
    QList<QString> case1,case2,case3,case4,case5,case6,case7,case8,case9;

    // on peut encore simplifier tout ca

    for(int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            case1.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case1);

    for(int i=0;i<3;i++)
        for (int j=3;j<6;j++)
            case2.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case2);

    for(int i=0;i<3;i++)
        for (int j=6;j<9;j++)
            case3.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case3);

    for(int i=3;i<6;i++)
        for (int j=0;j<3;j++)
            case4.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case4);

    for(int i=3;i<6;i++)
        for (int j=3;j<6;j++)
            case5.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case5);

    for(int i=3;i<6;i++)
        for (int j=6;j<9;j++)
            case6.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case6);

    for(int i=6;i<9;i++)
        for (int j=0;j<3;j++)
            case7.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case7);

    for(int i=6;i<9;i++)
        for (int j=3;j<6;j++)
            case8.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case8);

    for(int i=6;i<9;i++)
        for (int j=6;j<9;j++)
            case9.append(QString::fromStdString(grille[i][j]));
    valeurs.push_back(case9);
}

void Grille::colorer_X(int i, int l){
    // coloriage dans les carrés i à i+3 de la ligne l
    for(int k =i;k<i+3;k++)
        for(int m=l*3;m<l*3+3;m++)
            colors[k][m]="lavender";
}

void Grille::colorer_Y(int i, int c){
    // coloriage dans tous les carrés de la colonne i (entre 0 et 2) de la colonne l (entre 0 et 2 également)
    for (int k=i;k<i+7;k+=3)
        for (int m=c;m<c+7;m+=3)
            colors[k][m]="lavender";
}

void Grille::colorer_voisins( int Carre,int Case,bool focus){

    if(focus){
        // reset les couleurs de toute la grille au blanc
        for(int k =0;k<9;k++){
            for(int j =0;j<9;j++){

                colors[k][j]="white";
            }
        }
        // recolore les cases du carré selectionné
        for(int k =0;k<9;k++){
            colors[Carre][k]="lavender";
        }

        //colorer les lignes horizontales
        switch(Carre/3){
            case 0:
                colorer_X(0,Case/3);
                break;
            case 1:
                colorer_X(3,Case/3);
                break;
            case 2:
                colorer_X(6,Case/3);
                break;
        }
        // colorer les lignes verticales
        switch(Carre%3){
            case 0:
                colorer_Y(0,Case%3);
                break;
            case 1:
                colorer_Y(1,Case%3);
                break;
            case 2:
                colorer_Y(2,Case%3);
                break;
        }
        emit focusChanged();
    }
}

void Grille::changer_valeur(int valeur, int Carre,int Case){
    string value =to_string(valeur);
    int ligne, colonne;

    switch(Carre){
        case 0:
            colonne = Case%3;
            ligne = Case/3;
            grille[ligne][colonne]=value;
            break;
        case 1:
            colonne = Case%3+3;
            ligne = Case/3;
            grille[ligne][colonne]=value;
            break;
        case 2:
            colonne = Case%3+6;
            ligne = Case/3;
            grille[ligne][colonne]=value;
            break;
        case 3:
            colonne = Case%3;
            ligne = Case/3+3;
            grille[ligne][colonne]=value;
            break;
       case 4:
            colonne = Case%3+3;
            ligne = Case/3+3;
            grille[ligne][colonne]=value;
            break;
       case 5:
            colonne = Case%3+6;
            ligne = Case/3+3;
            grille[ligne][colonne]=value;
            break;
       case 6:
            colonne = Case%3;
            ligne = Case/3+6;
            grille[ligne][colonne]=value;
            break;
       case 7:
            colonne = Case%3+3;
            ligne = Case/3+6;
            grille[ligne][colonne]=value;
            break;
       case 8:
            colonne = Case%3+6;
            ligne = Case/3+6;
            grille[ligne][colonne]=value;
            break;
    }


    // affichage de la grille
    for(int i=0; i<9; i++) {
        cout << endl;
        for(int j=0; j<9; j++)
            cout << grille[i][j] << ", ";
    }
    cout <<endl<<endl;

}

