#ifndef ZSQLMANAGERWINDOW_H
#define ZSQLMANAGERWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTreeView>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTableView>

class ZSQLManagerWindow : public QWidget
{
    Q_OBJECT

public:
    ZSQLManagerWindow(QWidget *parent = nullptr);
    ~ZSQLManagerWindow();

private:
    QHBoxLayout *mainLayout;

    // left part
    QTreeView *databaseView;

    // right part
    QVBoxLayout *rightLayout;
    QTextEdit *sqlEdit;
    QTableView *resultView;

};
#endif // ZSQLMANAGERWINDOW_H
