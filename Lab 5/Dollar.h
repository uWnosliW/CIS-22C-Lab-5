//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#ifndef Dollar_h
#define Dollar_h
#include "Currency.h"
#include <stdio.h>
class Dollar: public Currency
{
public:
    Dollar();
    Dollar(int unitVal, int fracVal);
    Dollar(Currency& money);
    
    // Description: prints currency object in the proper format
    // Pre: ostream &out - output stream
    //      Currency& c - currency object to print
    // Post: formatted currency into the buffer
    // Return: ostream
    friend std::ostream & operator<<(std::ostream &out, const Dollar& c);
    
    // Description: reads currency object in the proper format
    // Pre: istream &in - input stream
    //      Currency& c - reference to currency object to read
    // Post: formatted currency into the buffer
    // Return: istream
    friend std::istream & operator>>(std::istream &in, Dollar& c);
    
    // Description: gets name of currency
    // Pre:
    // Post:
    // Return: name of currency as a string
    virtual std::string getUnitName() const { return unitName; }
    
    // Description: gets name of coin
    // Pre:
    // Post:
    // Return: name of coin as a string
    virtual std::string getFracName() const { return fracName; }
    
    // Description: sets name of currency
    // Pre:
    // Post:
    // Return:
    virtual void setUnitName(std::string unitName) { this->unitName = unitName; }
    
    // Description: sets name of coin
    // Pre:
    // Post:
    // Return:
    virtual void setFracName(std::string fracName) { this->fracName = fracName; }
protected:
private:
    std::string unitName = "Dollar";
    std::string fracName = "cent";
};


#endif /* CurrencyTypes_hpp */
