#include "reversi.h"

#include <QtGui>
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
/*
	QApplication a(argc, argv);
	Reversi w;
	w.show();
	*/
	//return a.exec();
}
