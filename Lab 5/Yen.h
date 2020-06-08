//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#ifndef Yen_h
#define Yen_h

#include "Currency.h"
#include <stdio.h>

class Yen: public Currency
{
public:
    Yen();
    Yen(int unitVal, int fracVal);
    Yen(Currency& money);
    
    // Description: prints currency object in the proper format
    // Pre: ostream &out - output stream
    //      Currency& c - currency object to print
    // Post: formatted currency into the buffer
    // Return: ostream
    friend std::ostream & operator<<(std::ostream &out, const Yen& c);
    
    // Description: reads currency object in the proper format
    // Pre: istream &in - input stream
    //      Currency& c - reference to currency object to read
    // Post: formatted currency into the buffer
    // Return: istream
    friend std::istream & operator>>(std::istream &in, Yen& c);
    
    
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
    std::string unitName = "Yen";
    std::string fracName = "sen";
};

#endif /* Yen_hpp */
