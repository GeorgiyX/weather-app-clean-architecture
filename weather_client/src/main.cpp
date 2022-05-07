#include <iostream>
#include <QGuiApplication>


int main(int argc, char *argv[])
{
    
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    return 0;
}
