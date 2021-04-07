#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include  "grille.h"
#include <iostream>
#include <string>
#include <QQmlContext>


int main(int argc, char *argv[])
{
//    list<int> liste;
//    liste.push_back(3);
//    liste.push_back(2);
//    bool vrai;
//    list<int> l;
//    l.push_back(3);
//    l.push_back(3);
//    vrai = (liste == l);
//    cout << vrai <<endl;

//#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Grille aGrille ;
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("vueObjetCpt", &aGrille);
    engine.load(url);

    return app.exec();
}
