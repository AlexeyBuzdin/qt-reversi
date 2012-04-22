#include "MainWindow.h"
#include <QtGui>
#include "reversi.h"

 MainWindow::MainWindow()
 {

	 this->setFixedSize(460, 500);
	 this->layout()->setSizeConstraint( QLayout::SetFixedSize );

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

     setWindowTitle(tr("Menus"));
     setMinimumSize(160, 160);
     resize(480, 320);
 }

 void MainWindow::contextMenuEvent(QContextMenuEvent *event)
 {
     QMenu menu(this);
     menu.exec(event->globalPos());
 }

 void MainWindow::newFile()
 {
	 Reversi *reversi = (Reversi*)centralWidget;
	 reversi->newGame();
 }

 void MainWindow::about()
 {

     QMessageBox::about(this, tr("About Menu"),
             tr("The <b>Menu</b> example shows how to create "
                "menu-bar menus and context menus."));
 }

 void MainWindow::aboutQt()
 {

 }

 void MainWindow::createActions()
 {
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     settings = new QAction(tr("&Settings"), this);
     settings->setStatusTip(tr("Game Settings"));
     connect(settings, SIGNAL(triggered()), this, SLOT(newFile()));

     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&Game"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(settings);

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);

 }
