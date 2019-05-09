#ifndef AIM_H
#define AIM_H


class Aim
{
private:
    double delta = 100;
public:
    Aim();
    double x;
    double y;
    bool shoot();
    void replace();
};

#endif // AIM_H
