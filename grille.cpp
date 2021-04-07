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
    list<string> lok;
    lok.push_back("1");
    lok.push_back("2");
    lok.push_back("3");
    lok.push_back("4");
    lok.push_back("5");
    lok.push_back("6");
    lok.push_back("8");
    lok.push_back("7");
    lok.push_back("9");
    list<string> lcopy = {"1", "2", "3", "4", "5", "6","7","8", "9"};
    lok.sort();
    bool vrai;
    vrai = (lok == lcopy);
    cout << vrai << endl;
}

void Grille::verif_matrice(){
    // verifie si la grille remplie par le joueur vérifie les règles du sudoku ou non

    bool victoire = true;
    list<string> lok= {"1", "2", "3", "4", "5", "6","7","8", "9"};
//    lok.push_back("1");
//    lok.push_back("2");
//    lok.push_back("3");
//    lok.push_back("4");
//    lok.push_back("5");
//    lok.push_back("6");
//    lok.push_back("7");
//    lok.push_back("8");
//    lok.push_back("9");

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

    for(int i =0;i<3;i++)
        for (int j=0;j<3;j++)
            case1.append(QString::fromStdString(grille[i][j]));

//    for(int i =0;i<3;i++){
//        case1.append(QString::fromStdString(grille[0][i]));
//    }
//    for(int i =0;i<3;i++){
//        case1.append(QString::fromStdString(grille[1][i]));
//    }
//    for(int i =0;i<3;i++){
//        case1.append(QString::fromStdString(grille[2][i]));
//    }

    valeurs.push_back(case1);

    for(int i =3;i<6;i++){
        case2.append(QString::fromStdString(grille[0][i]));
    }
    for(int i =3;i<6;i++){
        case2.append(QString::fromStdString(grille[1][i]));
    }
    for(int i =3;i<6;i++){
        case2.append(QString::fromStdString(grille[2][i]));
    }
    valeurs.push_back(case2);
    for(int i =6;i<9;i++){
        case3.append(QString::fromStdString(grille[0][i]));
    }
    for(int i =6;i<9;i++){
        case3.append(QString::fromStdString(grille[1][i]));
    }
    for(int i =6;i<9;i++){
        case3.append(QString::fromStdString(grille[2][i]));
    }
    valeurs.push_back(case3);

    for(int i =0;i<3;i++){
        case4.append(QString::fromStdString(grille[3][i]));
    }
    for(int i =0;i<3;i++){
        case4.append(QString::fromStdString(grille[4][i]));
    }
    for(int i =0;i<3;i++){
        case4.append(QString::fromStdString(grille[5][i]));
    }
    valeurs.push_back(case4);
    for(int i =3;i<6;i++){
        case5.append(QString::fromStdString(grille[3][i]));
    }
    for(int i =3;i<6;i++){
        case5.append(QString::fromStdString(grille[4][i]));
    }
    for(int i =3;i<6;i++){
        case5.append(QString::fromStdString(grille[5][i]));
    }
    valeurs.push_back(case5);

    for(int i =6;i<9;i++){
        case6.append(QString::fromStdString(grille[3][i]));
    }
    for(int i =6;i<9;i++){
        case6.append(QString::fromStdString(grille[4][i]));
    }
    for(int i =6;i<9;i++){
        case6.append(QString::fromStdString(grille[5][i]));
    }
    valeurs.push_back(case6);
    for(int i =0;i<3;i++){
        case7.append(QString::fromStdString(grille[6][i]));
    }
    for(int i =0;i<3;i++){
        case7.append(QString::fromStdString(grille[7][i]));
    }
    for(int i =0;i<3;i++){
        case7.append(QString::fromStdString(grille[8][i]));
    }
    valeurs.push_back(case7);
    for(int i =3;i<6;i++){
        case8.append(QString::fromStdString(grille[6][i]));
    }
    for(int i =3;i<6;i++){
        case8.append(QString::fromStdString(grille[7][i]));
    }
    for(int i =3;i<6;i++){
        case8.append(QString::fromStdString(grille[8][i]));
    }
    valeurs.push_back(case8);

    for(int i =6;i<9;i++){
        case9.append(QString::fromStdString(grille[6][i]));
    }
    for(int i =6;i<9;i++){
        case9.append(QString::fromStdString(grille[7][i]));
    }
    for(int i =6;i<9;i++){
        case9.append(QString::fromStdString(grille[8][i]));
    }
    valeurs.push_back(case9);


}

void Grille::colorer_X(int i, int j, int p,int q){
    // coloriage de la ligne
    for(int k =i;k<j;k++){
        for(int m=p;m<q;m++){
            colors[k][m]="lavender";
        }
    }
}
//****************
void Grille::colorer_Y(int i, int j, int p, int q  ){
    int k =i;
    int m =p;
    while(k<j){
        m=p;
        while(m<q){
            colors[k][m]="lavender";
            m+=3;
        }
        k+=3;
    }

}

//**********************
void Grille::colorer_voisins( int Carre,int Case,bool focus){
    cout << focus<< Carre << Case<< endl;


    if(focus){
        // reset les couleurs au blanc
        for(int k =0;k<9;k++){
            for(int j =0;j<9;j++){

                colors[k][j]="white";
            }
        }
        // recolore les cases du carré selectionné
        for(int k =0;k<9;k++){
            colors[Carre][k]="lavender";
        }

        //colorer lignes horizantales
        if(Carre==0||Carre==1||Carre==2){
            if(Case==0||Case==1||Case==2)
                colorer_X(0,3,0,3);
            if(Case==3||Case==4||Case==5)
                colorer_X(0,3,3,6);
            if(Case==6||Case==7||Case==8)
                colorer_X(0,3,6,9);
        }
        //***
        if(Carre==3||Carre==4||Carre==5){
            if(Case==0||Case==1||Case==2)
                colorer_X(3,6,0,3);
            if(Case==3||Case==4||Case==5)
                colorer_X(3,6,3,6);
            if(Case==6||Case==7||Case==8)
                colorer_X(3,6,6,9);
        }
        //***
        if(Carre==6||Carre==7||Carre==8){
            if(Case==0||Case==1||Case==2)
                colorer_X(6,9,0,3);
            if(Case==3||Case==4||Case==5)
                colorer_X(6,9,3,6);
            if(Case==6||Case==7||Case==8)
                colorer_X(6,9,6,9);
        }

        //colorer lignes verticales
        if(Carre==0||Carre==3||Carre==6){
            if(Case==0||Case==3||Case==6)
                colorer_Y(0,7,0,7);
            if(Case==1||Case==4||Case==7)
                colorer_Y(0,9,1,10);
            if(Case==2||Case==5||Case==8)
                colorer_Y(0,9,2,11);
        }
        //***
        if(Carre==1||Carre==4||Carre==7){
            if(Case==0||Case==3||Case==6)
                colorer_Y(1,8,0,7);
            if(Case==1||Case==4||Case==7)
                colorer_Y(1,8,1,8);
            if(Case==2||Case==5||Case==8)
                colorer_Y(1,8,2,9);
        }
        //***
        if(Carre==2||Carre==5||Carre==8){
            if(Case==0||Case==3||Case==6)
                colorer_Y(2,9,0,7);
            if(Case==1||Case==4||Case==7)
                colorer_Y(2,9,1,8);
            if(Case==2||Case==5||Case==8)
                colorer_Y(2,9,2,9);
        }
        emit focusChanged();
    }
}

void Grille::changer_valeur(int valeur, int Carre,int Case){
    string value =to_string(valeur);
    int ligne, colonne;

    // au lieu de faire plein de if, on peut utiliser case{} qui serait plus élégant

    if(Carre==0){
        ligne = Case%3;
        colonne = Case/3; // comme Case est un int, ca fait la division euclidienne
    }

    if(Carre==1){
        ligne = Case%3;
        colonne = Case/3+3;
    }

    if(Carre==2){
        ligne = Case%3;
        colonne = Case/3+6;
    }
    if(Carre==3){
        ligne = Case%3+3;
        colonne = Case/3;
    }

    if(Carre==4){
        ligne = Case%3+3;
        colonne = Case/3+3;
    }

    if(Carre==5){
        ligne = Case%3+3;
        colonne = Case/3+3;
    }

    if(Carre==6){
        ligne = Case%3+6;
        colonne = Case/3;
    }

    if(Carre==7){
        ligne = Case%3+6;
        colonne = Case/3+3;
    }

    if(Carre==8){
        ligne = Case%3+6;
        colonne = Case/3+6;
    }

    grille[ligne][colonne]=value;

    // on affiche la grille
    for(int i=0; i<9; i++) {
        cout << endl;
        for(int j=0; j<9; j++)
            cout << grille[i][j] << ", ";
    }
    cout <<endl<<endl;

}

