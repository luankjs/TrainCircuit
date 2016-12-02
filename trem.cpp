#include "trem.h"

//Trem::Trem(int id, int x, int y, int x_min, int x_max, int y_min, int y_max, int direction, int velocidade=250)
Trem::Trem(int id, int x, int y, QVector<Semaforo*> semaforos, int velocidade=250)
{
    this->id = id;
    this->x = x;
    this->y = y;
//    this->x_min = x_min;
//    this->x_max = x_max;
//    this->y_min = y_min;
//    this->y_max = y_max;
//    this->direction = direction;
    this->velocidade = velocidade;
    enable = true;
    this->semaforos = semaforos;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable)
            {
                //X: {min: 150, max: 290}
                //Y: {min: 120, max: 220}
                emit updateGUI(id,x,y);
                if (y == 120 && x > 150)
                    x-=10;
                else if (x == 290 && y > 120)
                    y-=10;
                else if (x < 290 && y == 220)
                    x+=10;
                else
                    y+=10;
            }
            break;
        case 2:
            if (enable)
            {
                //X: {min: 150, max: 290}
                //Y: {min: 220, max: 320}
                emit updateGUI(id,x,y);
                if (y == 220 && x < 290)
                    x+=10;
                else if (x == 290 && y < 320)
                    y+=10;
                else if (x > 150 && y == 320)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 3:
            if (enable)
            {
                //X: {min: 290, max: 430}
                //Y: {min: 220, max: 320}
                emit updateGUI(id,x,y);
                if (y == 220 && x < 430)
                    x+=10;
                else if (x == 430 && y < 320)
                    y+=10;
                else if (x > 290 && y == 320)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 4:
            if (enable)
            {
                //X: {min: 290, max: 430}
                //Y: {min: 320, max: 420}
                emit updateGUI(id,x,y);
                if (y == 320 && x < 430)
                    x+=10;
                else if (x == 430 && y < 420)
                    y+=10;
                else if (x > 290 && y == 420)
                    x-=10;
                else
                    y-=10;
            }
            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

