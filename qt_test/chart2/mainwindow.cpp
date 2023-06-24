#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    theModel = new QStandardItemModel(studentCount,columCount,this);
    ui->tableView->setModel(theModel);
    initData();

}

void MainWindow::initData()
{
    QStringList headList;
    float sum = 0;
    headList << "姓名" <<"语文"<<"数学"<<"英语"<< "平均分";
    theModel->setHorizontalHeaderLabels(headList);
    qsrand(QTime::currentTime().second());
    for(int i = 0;i< studentCount;i++)
    {
        QString stuName = QString::asprintf("学生%2d",i+1);
        QStandardItem* item = new QStandardItem(stuName);
        item->setTextAlignment(Qt::AlignHCenter);
        theModel->setItem(i,nameColNo,item);
        for(int j = chineseColNo;j< averageColNo;j++)
        {
            qreal score = 50+qrand()%50;
            sum+=score;
            item = new QStandardItem(QString::asprintf("%.0f",score));
            item->setTextAlignment(Qt::AlignHCenter);
            theModel->setItem(i,j,item);
        }
        item = new QStandardItem(QString::asprintf("%.1f",sum/3));
        item->setTextAlignment(Qt::AlignHCenter);
        item->setFlags(item->flags() & (!Qt::ItemIsEditable));   //不允许编辑
        theModel->setItem(i,averageColNo,item);
        sum = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
