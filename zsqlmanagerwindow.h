#ifndef ZSQLMANAGERWINDOW_H
#define ZSQLMANAGERWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTreeView>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTableView>
#include <QStackedWidget>

#include <QVector>
#include <QMenu>
#include <QAction>

class ZSQLManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    ZSQLManagerWindow(QWidget *parent = nullptr);
    ~ZSQLManagerWindow();

private:
    QMenu *fileMenu;
    QVector<QString> *fileActionsStr;
    QVector<QAction *> *fileActions;

    QMenu *editMenu;
    QVector<QString> *editActionsStr;
    QVector<QAction *> *editActions;

    QMenu *helpMenu;
    QVector<QString> *helpActionsStr;
    QVector<QAction *> *helpActions;

    QHBoxLayout *mainLayout;

    // left part
    QTreeView *databaseView;

    // right part
    QVBoxLayout *rightLayout;
    QTextEdit *sqlEdit;
    QTableView *resultView;

    void initMenu();
    void initFileMenu();
    void initEditMenu();
    void initHelpMenu();

    void addActions(QMenu *menu, const QVector<QString> *actionStrs, QVector<QAction *> *actions);
};
#endif // ZSQLMANAGERWINDOW_H
