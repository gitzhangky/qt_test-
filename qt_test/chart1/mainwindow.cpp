#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createCharts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createCharts()
{
    //创建图标
    QChartView* chartView = new QChartView;
    QChart* chart = new QChart;
    chart->setTitle("简单函数曲线");
    chartView->setChart(chart);
    setCentralWidget(chartView);
    //创建折现序列
    QLineSeries* lineseries0 = new QLineSeries;
    QLineSeries* lineseries1 = new QLineSeries;
    lineseries0->setName("sin曲线");
    lineseries1->setName("cos曲线");
    chart->addSeries(lineseries0);
    chart->addSeries(lineseries1);
    //序列添加数值
    qreal t = 0,y0,y1,intv = 0.1;
    int cnt = 100;
    for(int i = 0;i< cnt;i++)
    {
        y0 = qSin(t);
        lineseries0->append(t,y0);
        y1 = qCos(t+20);
        lineseries1->append(t,y1);
        t+=intv;
    }
    //创建坐标轴
    QValueAxis* axisX = new QValueAxis;   //x轴
    QValueAxis* axisY = new QValueAxis;    //y轴
    axisX->setRange(0,10);
    axisX->setTitleText("secs");
    axisY->setRange(-2,2);
    axisY->setTitleText("val");
    //为序列添加坐标轴
    chart->setAxisX(axisX,lineseries0);
    chart->setAxisY(axisY,lineseries0);
    chart->setAxisX(axisX,lineseries1);
    chart->setAxisY(axisY,lineseries1);
}
