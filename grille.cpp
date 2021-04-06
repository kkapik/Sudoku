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
    QList<QString> colors_case;
    for(int i =0;i<9;i++){
        colors_case.push_back("white");
    }


    for(int j =0;j<9;j++){
        colors.push_back(colors_case);
    }


    for(int i=0; i<9; i++) {
        cout << endl;
        list<int> L;
        for(int j=0; j<9; j++){
            //cout << grille[i][j] << "  ";
            cout << (grille[i][j] == "4") << ",";;
        }
    }
    cout <<endl<<endl;

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

void Grille::verif_matrice(){ // à compléter
    // verifier matrice
    bool victoire = true;
    list<string> lok;
    lok.push_back("1");
    lok.push_back("2");
    lok.push_back("3");
    lok.push_back("4");
    lok.push_back("5");
    lok.push_back("6");
    lok.push_back("7");
    lok.push_back("8");
    lok.push_back("9");


    for(int i=0; i<9; i++){ // On vérifie que les lignes soient correctes
        list<string> L;
        for(int j= 0; j<9; j++){
            L.push_back(grille[i][j]);
        }
        L.sort();
        victoire = victoire && (L==lok);
    }

    for(int i=0; i<9; i++){ // On vérifie que les colonnes soient correctes
        list<string> L;
        for(int j= 0; j<9; j++){
            L.push_back(grille[j][i]);
        }
        L.sort();
        victoire = victoire && (L==lok);
    }
    for(int l=0; l<3;l++){  // On parcourt les cases une par une
        for(int c = 0; c<3; c++){
            list<string> L;
            for(int i=3*l; i<3*l+3; i++){ // On vérifie que la case est correcte
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
    QList<QString> case1,case2,case3,case4,case5,case6,case7,case8,case9;
    for(int i =0;i<3;i++){
        case1.append(QString::fromStdString(grille[0][i]));
    }
    for(int i =0;i<3;i++){
        case1.append(QString::fromStdString(grille[1][i]));
    }
    for(int i =0;i<3;i++){
        case1.append(QString::fromStdString(grille[2][i]));
    }

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
//****************
void Grille::colorer_X(int i, int j, int p,int q){

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
void Grille::colorer_voisins( int grandCase,int petiteCase,bool focus){
    cout << focus<< grandCase << petiteCase<< endl;


    if(focus){
        for(int k =0;k<9;k++){
            for(int j =0;j<9;j++){

                colors[k][j]="white";
            }
        }

        for(int k =0;k<9;k++){
            colors[grandCase][k]="lavender";
        }
        //colorer lignes horizantales
        if(grandCase==0||grandCase==1||grandCase==2){
            if(petiteCase==0||petiteCase==1||petiteCase==2){
                colorer_X(0,3,0,3);

            }
            if(petiteCase==3||petiteCase==4||petiteCase==5){

                colorer_X(0,3,3,6);
            }
            if(petiteCase==6||petiteCase==7||petiteCase==8){

                colorer_X(0,3,6,9);
            }


        }
        //***
        if(grandCase==3||grandCase==4||grandCase==5){
            if(petiteCase==0||petiteCase==1||petiteCase==2){

                colorer_X(3,6,0,3);
            }
            if(petiteCase==3||petiteCase==4||petiteCase==5){

                colorer_X(3,6,3,6);
            }
            if(petiteCase==6||petiteCase==7||petiteCase==8){

                colorer_X(3,6,6,9);
            }


        }
        if(grandCase==6||grandCase==7||grandCase==8){
            if(petiteCase==0||petiteCase==1||petiteCase==2){

                colorer_X(6,9,0,3);
            }
            if(petiteCase==3||petiteCase==4||petiteCase==5){

                colorer_X(6,9,3,6);
            }
            if(petiteCase==6||petiteCase==7||petiteCase==8){

                colorer_X(6,9,6,9);
            }


        }
        //colorer lignes verticales
        if(grandCase==0||grandCase==3||grandCase==6){
            if(petiteCase==0||petiteCase==3||petiteCase==6){


                colorer_Y(0,7,0,7);
            }
            if(petiteCase==1||petiteCase==4||petiteCase==7){

                colorer_Y(0,9,1,10);
            }
            if(petiteCase==2||petiteCase==5||petiteCase==8){

                colorer_Y(0,9,2,11);
            }


        }
        if(grandCase==1||grandCase==4||grandCase==7){
            if(petiteCase==0||petiteCase==3||petiteCase==6){


                colorer_Y(1,8,0,7);
            }
            if(petiteCase==1||petiteCase==4||petiteCase==7){

                colorer_Y(1,8,1,8);
            }
            if(petiteCase==2||petiteCase==5||petiteCase==8){

                colorer_Y(1,8,2,9);
            }


        }
        if(grandCase==2||grandCase==5||grandCase==8){
            if(petiteCase==0||petiteCase==3||petiteCase==6){


                colorer_Y(2,9,0,7);
            }
            if(petiteCase==1||petiteCase==4||petiteCase==7){

                colorer_Y(2,9,1,8);
            }
            if(petiteCase==2||petiteCase==5||petiteCase==8){

                colorer_Y(2,9,2,9);
            }


        }


        emit focusChanged();
    }



}

void Grille::changer_valeur(int valeur, int grandCase,int petiteCase){
    cout << valeur<< grandCase << petiteCase<<endl;
    string value =to_string(valeur);
    string indice1 =to_string(grandCase);
    string indice2 =to_string(petiteCase);
    int ligne, colonne;
    if(indice1=="0"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=0;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=1;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=2;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=0;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=1;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=2;}
    }

    if(indice1=="1"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=0;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=1;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=2;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=3;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=4;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=5;}
    }


    if(indice1=="2"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=0;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=1;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=2;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=6;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=7;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=8;}
    }
    if(indice1=="3"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=3;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=4;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=5;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=0;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=1;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=2;}
    }
    if(indice1=="4"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=3;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=4;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=5;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=3;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=4;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=5;}
    }
    if(indice1=="5"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=3;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=4;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=5;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=6;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=7;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=8;}
    }
    if(indice1=="6"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=6;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=7;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=8;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=0;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=1;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=2;}
    }
    if(indice1=="7"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=6;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=7;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=8;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=3;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=4;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=5;}
    }
    if(indice1=="8"){
        if(indice2=="0"||indice2=="1"||indice2=="2"){
            ligne=6;
        }
        else if(indice2=="3"||indice2=="4"||indice2=="5"){
            ligne=7;
        }
        else if(indice2=="6"||indice2=="7"||indice2=="8"){
            ligne=8;
        }
        if(indice2=="0"||indice2=="3"||indice2=="6"){colonne=6;}
        else if(indice2=="1"||indice2=="4"||indice2=="7"){colonne=7;}
        else if(indice2=="2"||indice2=="5"||indice2=="8"){colonne=8;}
    }



    grille[ligne][colonne]=value;

    for(int i=0; i<9; i++) {
        cout << endl;
        for(int j=0; j<9; j++)
            cout << grille[i][j] << ", ";
    }
    cout <<endl<<endl;

    /*for (int i =0 ; i<9;i++){
for(int j =0;j<9;j++){
    if(grille[i][j] =="1"||grille[i][j] =="2"||grille[i][j] =="3"||grille[i][j] =="4"||grille[i][j] =="5"||grille[i][j] =="6"||grille[i][j] =="7"||grille[i][j] =="8"||grille[i][j] =="9"){
        cout<<grille[i][j];
    }
    else cout<<"_";

}
cout<<endl;
}*/

}

