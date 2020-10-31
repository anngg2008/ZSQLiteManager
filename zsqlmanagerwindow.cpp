#include <QMenuBar>

#include "zsqlmanagerwindow.h"

void ZSQLManagerWindow::initFileMenu()
{
    fileMenu = new QMenu(tr("&File"), this);

    fileActionsStr = new QVector<QString> {
            tr("&Create DB"),
            tr("&Save DB"),
            tr("Save &As DB"),
            tr("Clos&e DB"),
            "-",
            tr("&Create SQL"),
            tr("&Save SQL"),
            tr("Save &As SQL"),
            tr("Clos&e SQL"),
            "-",
            tr("E&xit"),
    };
    fileActions = new QVector<QAction *>;
    addActions(fileMenu, fileActionsStr, fileActions);

    this->menuBar()->addMenu(fileMenu);

    // connect
    connect(fileActions->at(8), &QAction::triggered, this, &QMainWindow::close);
}

void ZSQLManagerWindow::initEditMenu()
{
    editMenu = new QMenu(tr("&Edit"), this);

    editActionsStr = new QVector<QString> {
            tr("Cu&t"),
            tr("&Copy"),
            tr("&Paste"),
    };

    editActions = new QVector<QAction *>;
    addActions(editMenu, editActionsStr, editActions);

    this->menuBar()->addMenu(editMenu);
}

void ZSQLManagerWindow::initHelpMenu()
{
    helpMenu = new QMenu(tr("&Help"), this);
    helpActionsStr = new QVector<QString> {
            tr("About &Qt"),
            tr("&About"),
    };

    helpActions = new QVector<QAction *>;
    addActions(helpMenu, helpActionsStr, helpActions);

    this->menuBar()->addMenu(helpMenu);
}

void ZSQLManagerWindow::addActions(QMenu *menu, const QVector<QString> *actionStrs, QVector<QAction *> *actions)
{
    for(auto str: *actionStrs) {
        if("-" != str) {
            auto action = new QAction(str, this);
            actions->push_back(action);
            menu->addAction(action);
        } else {
            menu->addSeparator();
        }
    }
}

void ZSQLManagerWindow::initMenu()
{
    // File menu.
    initFileMenu();

    // Edit menu.
    initEditMenu();

    // Help menu.
    initHelpMenu();

}

ZSQLManagerWindow::ZSQLManagerWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initMenu();

    mainLayout = new QHBoxLayout;
    databaseView = new QTreeView;
    rightLayout = new QVBoxLayout;
    sqlEdit = new QTextEdit;
    resultView = new QTableView;

    mainLayout->addWidget(databaseView);
    mainLayout->addLayout(rightLayout);
    rightLayout->addWidget(sqlEdit);
    rightLayout->addWidget(resultView);

    this->setLayout(mainLayout);
}

ZSQLManagerWindow::~ZSQLManagerWindow()
{
}
