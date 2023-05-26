#ifndef EKRAN_H
#define EKRAN_H

#include <QWidget>

class Ekran : public QWidget
{
    Q_OBJECT
public:
        explicit Ekran(QWidget *parent = nullptr);
        void changed();
        void fromRGBtoHSV(int j,int i);
        void fromHSVtoRGB(int j,int i);
        void setValue1(int value);
        void setValue2(int value);
        void setValue3(int value);
protected:
        void paintEvent(QPaintEvent *);
private:
        QImage im,im2;
        double S,H,V;
        int value1=0,value2=0,value3=0;
signals:

};

#endif // EKRAN_H
