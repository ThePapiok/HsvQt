#include "ekran.h"
#include <QPainter>
#include <QMouseEvent>
#include <algorithm>
#include <QImage>

using namespace std;

Ekran::Ekran(QWidget *parent)
    : QWidget{parent}
{
    im=QImage(":/zdj/swain.jpg");
    im2=im;
}

void Ekran::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0,0,im);
}

void Ekran::changed()
{
    for(int i=0;i<im.height();i++)
    {
        for(int j=0;j<im.width();j++)
        {
            fromRGBtoHSV(j,i);
            H+=value1;
            if(H<0)
            {
                H+=360;
            }
            else if(H>=360)
            {
                H-=360;
            }
            S+=value2/100.0;
            if(S<0)
            {
                S=0;
            }
            else if(S>1)
            {
                S=1;
            }
            V+=value3/100.0;
            if(V<0)
            {
                V=0;
            }
            else if(V>1)
            {
                V=1;
            }
            fromHSVtoRGB(j,i);
        }

    }
    update();

}

void Ekran::fromRGBtoHSV(int j,int i)
{
    double Cmax,Cmin,delta;
    double Red,Green,Blue;
    QRgb pix;
    pix=im2.pixel(j,i);
    Red=qRed(pix)/255.0;
    Green=qGreen(pix)/255.0;
    Blue=qBlue(pix)/255.0;
    Cmax=max(max(Red,Green),Blue);
    Cmin=min(min(Red,Green),Blue);
    delta=Cmax-Cmin;
    V=Cmax;
    if(delta==0)
    {
        H=0;
        S=0;
    }
    else
    {
        S=delta/Cmax;
        if(Red==Cmax)
        {
            H=(Green-Blue)/delta;
        }
        else if(Green==Cmax)
        {
            H=2+(Blue-Red)/delta;
        }
        else
        {
            H=4+(Red-Green)/delta;
        }
        H*=60;
        if(H<0)
        {
            H+=360;
        }

    }
}

void Ekran::fromHSVtoRGB(int j,int i)
{
    double Red,Green,Blue;
    double f,p,q,t;
    int x;
    QRgb pix;
    if(S==0)
    {
        Red=Green=Blue=V;
    }
    else
    {
        x=static_cast<int>(H/60)%6;
        f=H/60-x;
        p=V*(1-S);
        q=V*(1-f*S);
        t=V*(1-(1-f)*S);
        switch (x)
        {
            case 0:
                Red=V;
                Green=t;
                Blue=p;
                break;
            case 1:
                Red=q;
                Green=V;
                Blue=p;
                break;
            case 2:
                Red=p;
                Green=V;
                Blue=t;
                break;
            case 3:
                Red=p;
                Green=q;
                Blue=V;
                break;
            case 4:
                Red=t;
                Green=p;
                Blue=V;
                break;
            case 5:
                Red=V;
                Green=p;
                Blue=q;
                break;
        }
    }
    Red*=255.0;
    Green*=255.0;
    Blue*=255.0;
    pix=qRgb((int)Red,(int)Green,(int)Blue);
    im.setPixel(j,i,pix);
}

void Ekran::setValue1(int value)
{
    value1=value;
}

void Ekran::setValue2(int value)
{
    value2=value;
}

void Ekran::setValue3(int value)
{
    value3=value;
}
