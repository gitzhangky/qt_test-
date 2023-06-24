#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtCharts>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}
#define studentCount 50       //学生数量，行数
#define columCount 5        //总列数
#define nameColNo 0      //姓名列号
#define chineseColNo 1    //语文列号
#define mathColNo 2         //数学列号
#define englishColNo 3      //英语列号
#define averageColNo 4       //平均分列号
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QStandardItemModel* theModel;
    explicit MainWindow(QWidget *parent = 0);
    void initData();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
