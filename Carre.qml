import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    function envoyer_valeur(app){
        var i;
        var j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                var carr = repeater.itemAt(i).rep.itemAt(j).input
                if (app === carr){
                    vueObjetCpt.changer_valeur(app.text,i,j);
                }
            }
        }
        var values = vueObjetCpt.values;
        var l
        var c
        for(l=0;l<9;l++){
            for(c=0;c<9;c++){
                var v = repeater.itemAt(l).rep.itemAt(c).input
                v.text=values[l][c];
            }
        }
        var colors = vueObjetCpt.colors;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                var w = repeater.itemAt(i).rep.itemAt(j)
                w.color=colors[i][j];
            }
        }
    }

    function changer_couleur(app, focus){
        var i;
        var j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                var carr = repeater.itemAt(i).rep.itemAt(j).input
                if (app === carr){
                    vueObjetCpt.colorer_voisins(i,j,focus);
                }
            }
        }
        var colors = vueObjetCpt.colors;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                var v = repeater.itemAt(i).rep.itemAt(j)
                v.color=colors[i][j];
            }
        }
    }
    property alias rep : repeater1

    Grid{
        id : grid
        x: 3; y:3
        rows:3; columns:3; spacing :2


        Repeater{ id : repeater1
            model : 9

            Rectangle{
                color : "#ffffff"
                width : 68; height: 68
                property alias input : input
                border.width : 2
                border.color : "#000000"

                TextInput{
                    id:input
                    color:'#333333'
                    width : parent.width
                    height:parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    readOnly: false
                    font.pointSize: 24
                    maximumLength: 1
                    validator: RegExpValidator { regExp: /[1-9]+/ }
                    onFocusChanged: {
                        changer_couleur(this, focus)
                    }
                    onTextEdited : envoyer_valeur(this)
                }
            }
        }
    }
}

