//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Dollar.h"
Dollar::Dollar()
{
    totalVal = 0;
    normalize();
    unitName = "Dollar";
    fracName = "cent";
}
Dollar::Dollar(int unitVal, int fracVal)
{
    totalVal = unitVal * 100 + fracVal;
    normalize();
    unitName = "Dollar";
    fracName = "cent";
}

Dollar::Dollar(Currency& money)
{
    this->totalVal = money.getTotalVal();
    normalize();
    unitName = "Dollar";
    fracName = "cent";
}

std::ostream & operator<<(std::ostream &out, const Dollar& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Dollar& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
