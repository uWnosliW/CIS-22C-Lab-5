//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Rupee.h"

Rupee::Rupee()
{
    totalVal = 0;
    normalize();
    unitName = "Rupee";
    fracName = "paise";
}
Rupee::Rupee(int unitVal, int fracVal)
{
    totalVal = unitVal * 100 + fracVal;
    normalize();
    unitName = "Rupee";
    fracName = "paise";
}

Rupee::Rupee(Currency& money)
{
    this->totalVal = money.getTotalVal();
    normalize();
    unitName = "Rupee";
    fracName = "paise";
}

std::ostream & operator<<(std::ostream &out, const Rupee& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Rupee& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
