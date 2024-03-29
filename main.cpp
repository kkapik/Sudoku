#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <string>
#include <QQmlContext>

#include  "grille.h"



int main(int argc, char *argv[]){
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
