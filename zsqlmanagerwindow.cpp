#include "zsqlmanagerwindow.h"

ZSQLManagerWindow::ZSQLManagerWindow(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QHBoxLayout;
    databaseView = new QTreeView;
    rightLayout = new QVBoxLayout;
    sqlEdit = new QTextEdit;
    resultView = new QTableView;

    this->setLayout(mainLayout);
    mainLayout->addWidget(databaseView);
    mainLayout->addLayout(rightLayout);
    rightLayout->addWidget(sqlEdit);
    rightLayout->addWidget(resultView);
}

ZSQLManagerWindow::~ZSQLManagerWindow()
{
}
