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
             tr("<table>"
            		 "<tr><td align=\"center\"><img src=\"resource/logo.png\"></td></tr>"
            		 "<tr><td>Open Source Reversi client v.0.99</td></tr> "
            		 "<tr><td>Created by <a href=\"http://www.linkedin.com/pub/alexey-buzdin/33/690/457\">Alexey Buzdin</a></td></tr>"
            		 "<tr><td>Source code can be seen <b><a href=\" https://github.com/LArchaon/Reversi\">here</a></b>.</td></tr>"
                "</table>"));
 }

 void MainWindow::disableTips()
 {
	 Reversi *reversi = (Reversi*)centralWidget;
	 reversi->changeShowHint();
 }

 void MainWindow::changeAI()
 {
	 Reversi *reversi = (Reversi*)centralWidget;
	 reversi->changeAI();
 }

 void MainWindow::createActions()
 {
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newGame()));

     settings = new QAction(tr("&Disable/Enable tips"), this);
     settings->setStatusTip(tr("Disable game tips"));
     connect(settings, SIGNAL(triggered()), this, SLOT(disableTips()));

     ai = new QAction(tr("&Disable/Enable AI"), this);
     ai->setStatusTip(tr("Disable Artificial Intelligent"));
     connect(ai, SIGNAL(triggered()), this, SLOT(changeAI()));

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
     fileMenu->addAction(ai);

     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);

 }
