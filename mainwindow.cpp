#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,150,120, 200);
    trem2 = new Trem(2, 150, 220, 300);
    trem3 = new Trem(3, 290, 220, 100);
    trem4 = new Trem(4, 290, 320, 400);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}

