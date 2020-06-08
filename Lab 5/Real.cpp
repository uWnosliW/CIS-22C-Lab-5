//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Real.h"

Real::Real()
{
    totalVal = 0;
    normalize();
    unitName = "Real";
    fracName = "centavo";
}
Real::Real(int unitVal, int fracVal)
{
    totalVal = unitVal * 100 + fracVal;
    normalize();
    unitName = "Real";
    fracName = "centavo";
}

Real::Real(Currency& money)
{
    this->totalVal = money.getTotalVal();
    normalize();
    unitName = "Real";
    fracName = "centavo";
}

std::ostream & operator<<(std::ostream &out, const Real& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Real& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
