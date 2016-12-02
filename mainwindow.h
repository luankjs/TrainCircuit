#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "semaforo.h"
#include <QMainWindow>
#include <QList>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateInterface(int,int,int);

private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Semaforo *semaforo1;
    Semaforo *semaforo2;
    Semaforo *semaforo3;
};

#endif // MAINWINDOW_H
