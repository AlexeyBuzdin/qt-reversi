#include "MainWindow.h"
#include <QtGui>
#include "reversi.h"

 MainWindow::MainWindow()
 {

	 centralWidget = new Reversi();
     setCentralWidget(centralWidget);

     QWidget *topFiller = new QWidget;
     topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

     QWidget *bottomFiller = new QWidget;
     bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

     createActions();
     createMenus();

 #ifndef Q_OS_SYMBIAN
     QString message = tr("Have a nice game");
     statusBar()->showMessage(message);
 #endif

     setWindowTitle(tr("Reversi"));
	 this->setFixedSize(460, 500);

 }

 void MainWindow::contextMenuEvent(QContextMenuEvent *event)
 {
     QMenu menu(this);
     menu.exec(event->globalPos());
 }

 void MainWindow::newGame()
 {
	 Reversi *reversi = (Reversi*)centralWidget;
	 reversi->newGame();
 }

 void MainWindow::about()
 {
     QMessageBox::about(this, tr("Reversi"),
             tr("The <b>Menu</b> example shows how to create "
                "menu-bar menus and context menus."));
 }

 void MainWindow::disableTips()
 {
	 Reversi *reversi = (Reversi*)centralWidget;
	 reversi->changeShowHint();
 }


 void MainWindow::createActions()
 {
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newGame()));

     settings = new QAction(tr("&Disable tips"), this);
     settings->setStatusTip(tr("Disable game tips"));
     connect(settings, SIGNAL(triggered()), this, SLOT(disableTips()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&Game"));
     fileMenu->addAction(newAct);

     fileMenu = menuBar()->addMenu(tr("&Settings"));
     fileMenu->addAction(settings);

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);

 }
