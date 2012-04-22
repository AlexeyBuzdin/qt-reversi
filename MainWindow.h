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
	void newFile();
	void open();
	void save();
	void print();
	void undo();
	void redo();
	void cut();
	void copy();
	void paste();
	void bold();
	void italic();
	void leftAlign();
	void rightAlign();
	void justify();
	void center();
	void setLineSpacing();
	void setParagraphSpacing();
	void about();
	void aboutQt();

private:
	void createActions();
	void createMenus();

	QWidget *centralWidget;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QActionGroup *alignmentGroup;
	QAction *newAct;
	QAction *settings;
	QAction *aboutAct;
};

#endif /* MAINWINDOW_H_ */
