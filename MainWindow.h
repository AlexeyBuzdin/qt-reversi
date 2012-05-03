#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow: public QMainWindow {
Q_OBJECT
public:
	MainWindow();
	virtual ~MainWindow() {
	}
	;
protected:
	void contextMenuEvent(QContextMenuEvent *event);

private slots:
	void newGame();
	void about();
	void disableTips();
	void changeAI();

private:
	void createActions();
	void createMenus();

	QWidget *centralWidget;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QActionGroup *alignmentGroup;
	QAction *newAct;
	QAction *settings;
	QAction *ai;
	QAction *aboutAct;
};

#endif /* MAINWINDOW_H_ */
