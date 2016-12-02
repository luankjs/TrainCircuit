#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    semaforo1 = new Semaforo(1,1,IPC_CREAT|0600);
    semaforo2 = new Semaforo(2,1,IPC_CREAT|0600);
    semaforo3 = new Semaforo(3,1,IPC_CREAT|0600);

    QVector<Semaforo*> semaforos_trem1;
    semaforos_trem1.push_back(semaforo1);
    trem1 = new Trem(1,150,120, semaforos_trem1, 200);
    QVector<Semaforo*> semaforos_trem2;
    semaforos_trem2.push_back(semaforo1);
    semaforos_trem2.push_back(semaforo2);
    trem2 = new Trem(2, 150, 220, semaforos_trem2, 300);
    QVector<Semaforo*> semaforos_trem3;
    semaforos_trem3.push_back(semaforo2);
    semaforos_trem3.push_back(semaforo3);
    trem3 = new Trem(3, 290, 220, semaforos_trem3, 100);
    QVector<Semaforo*> semaforos_trem4;
    semaforos_trem4.push_back(semaforo3);
    trem4 = new Trem(4, 290, 320, semaforos_trem4, 400);

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

