#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <typeinfo>
#include <QFileDialog>

#include "QtHarrixLibrary.h"
#include "MathHarrixLibrary.h"
#include "QtHarrixLibraryForQWebView.h"

MainWindow::MainWindow(QWidget *parent,QString FileNameFromArgv) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(QDateTime::currentMSecsSinceEpoch () % 1000000);

    DS=QDir::separator();//какой разделитель используется в пути между папками
    Path=QGuiApplication::applicationDirPath()+DS;//путь к папке, где находится приложение
    HQt_BeginHtml(Path);
    ui->webView->setUrl(QUrl::fromLocalFile(Path+"index.html"));// и в webViewотображаем index.html (его вообще не трогаем)

    if (FileNameFromArgv.length()>0)
    {
        QString Html;
        HQt_BeginHtml (Path);

        Html=HQt_ReadHdataToHtmlChart (FileNameFromArgv);
        HQt_AddHtml(Html);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    QString Html;
    HQt_BeginHtml (Path);

    QString filename;
    filename=QFileDialog::getOpenFileName(this, tr("Открыть файл с данными графика"),"",tr("Harrix Data 1.0 (*.hdata)"));

    if (filename.length()>0)
    {
    Html=HQt_ReadHdataToHtmlChart (filename);
    HQt_AddHtml(Html);
    }
}
