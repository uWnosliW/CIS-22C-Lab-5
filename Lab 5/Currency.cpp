//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#include "Currency.h"
#include <string>
#include <iostream>
void Currency::normalize()
{
    int flip = (totalVal < 0)? -1:1;
    unitVal = flip*(flip*totalVal / 100);
    fracVal = flip*(flip*totalVal % 100);
}

std::ostream & operator<<(std::ostream &out, const Currency *c)
{
    out<<c->getUnitName()<<" "<<c->unitVal<<" "<<c->fracVal<<" "<<c->getFracName();
    return out;
}

std::ostream & operator<<(std::ostream &out, const Currency& c)
{
    out<<c.getUnitName()<<" "<<c.getUnitVal()<<" "<<c.getFracVal()<<" "<<c.getFracName();
    return out;
}
std::istream & operator>>(std::istream &in, Currency& c)
{
    std::string unit,frac;
    int whole, part;
    in>>unit>>whole>>part>>frac;
    c.setTotalVal(whole*100+part);
    c.normalize();
    return in;
}
Currency Currency::operator+(const Currency& money)
{
    Currency tempCurrency;
    if(this->getUnitName()!=money.getUnitName())
    {
        throw "CANNOT ADD TWO SEPARATE CURRENCIES -- COMMAND IGNORED.";
        return tempCurrency;
    }
    tempCurrency.setTotalVal(this->totalVal + money.totalVal);
    tempCurrency.normalize();
    return tempCurrency;
}
Currency Currency::operator-(const Currency& money)
{
    Currency tempCurrency;
    if(this->getUnitName()!=money.getUnitName())
    {
        throw "CANNOT SUBTRACT TWO SEPARATE CURRENCIES -- COMMAND IGNORED.";
        return tempCurrency;
    }
    tempCurrency.setTotalVal(this->totalVal - money.totalVal);
    tempCurrency.normalize();
    return tempCurrency;
}
Currency& Currency::operator=(const Currency& money)
{
    this->setTotalVal(money.getTotalVal());
    this->normalize();
    return *this;
}
