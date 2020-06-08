//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Yen.h"

Yen::Yen()
{
    totalVal = 0;
    normalize();
    unitName = "Yen";
    fracName = "sen";
}
Yen::Yen(int unitVal, int fracVal)
{
    totalVal = unitVal * 100 + fracVal;
    normalize();
    unitName = "Yen";
    fracName = "sen";
}

Yen::Yen(Currency& money)
{
    this->totalVal = money.getTotalVal();
    normalize();
    unitName = "Yen";
    fracName = "sen";
}

std::ostream & operator<<(std::ostream &out, const Yen& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Yen& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
