//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Pound.h"

Pound::Pound()
{
    totalVal = 0;
    normalize();
    unitName = "Pound";
    fracName = "pence";
}
Pound::Pound(int unitVal, int fracVal)
{
    totalVal = unitVal * 100 + fracVal;
    normalize();
    unitName = "Pound";
    fracName = "pence";
}

Pound::Pound(Currency& money)
{
    this->totalVal = money.getTotalVal();
    normalize();
    unitName = "Pound";
    fracName = "pence";
}

std::ostream & operator<<(std::ostream &out, const Pound& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Pound& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
