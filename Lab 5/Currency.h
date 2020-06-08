//Wilson Wu
//Lab 1A
//Demonstrate OOP concepts via implementing Currency classes.

#ifndef Currency_h
#define Currency_h

#include <iostream>
#include <string>
class Currency
{
public:
    Currency() { Currency(0,0); }
    Currency(int unitVal, int fracVal)
    {
        totalVal = unitVal * 100 + fracVal;
        normalize();
    }
    // Description: returns number of bills
    // Pre:
    // Post:
    // Return: int - number of bills
    int getUnitVal() const{ return unitVal; }
    
    // Description: returns number of coins
    // Pre:
    // Post:
    // Return: int - number of coins
    int getFracVal() const{ return fracVal; }
    
    // Description: total value in coins
    // Pre:
    // Post:
    // Return: int - total value
    int getTotalVal() const{ return totalVal; }
    
    // Description: sets number of bills
    // Pre: int - number of bills
    // Post: updates number of bills
    // Return:
    void setUnitVal(int unitVal) { this -> unitVal = unitVal; }
    
    // Description: sets number of coins
    // Pre: int - number of coins
    // Post: updates number of coins
    // Return:
    void setFracVal(int fracVal) { this -> fracVal = fracVal; }
    
    // Description: sets total value of currency in coins
    // Pre: int - total value of currency in coins
    // Post: updates total value
    // Return:
    void setTotalVal(int totalVal) { this -> totalVal = totalVal; }
    
    // Description: print out currency object in the proper format
    // Pre: ostream &out - output stream
    //      Currency* c - pointer to currency object to print
    // Post: formatted currency into the buffer
    // Return: ostream
    friend std::ostream & operator<<(std::ostream &out, const Currency *c);
    
    // Description: reads currency object in the proper format
    // Pre: istream &in - input stream
    //      Currency* &c - reference to pointer to currency object to read
    // Post: formatted currency into the buffer
    // Return: istream
    friend std::istream & operator>>(std::istream &in, Currency* &c);
    
    // Description: prints currency object in the proper format
    // Pre: ostream &out - output stream
    //      Currency& c - currency object to print
    // Post: formatted currency into the buffer
    // Return: ostream
    friend std::ostream & operator<<(std::ostream &out, const Currency& c);
    
    // Description: reads currency object in the proper format
    // Pre: istream &in - input stream
    //      Currency& c - reference to currency object to read
    // Post: formatted currency into the buffer
    // Return: istream
    friend std::istream & operator>>(std::istream &in, Currency& c);
    
    // Description: adds two currency objects
    // Pre: const Currency& money - currency object to add to this
    // Post:
    // Return: currency object
    virtual Currency operator+(const Currency& money);
    
    // Description: subtracts two currency objects
    // Pre: const Currency& money - currency object to subtract from this
    // Post:
    // Return: currency object
    virtual Currency operator-(const Currency& money);
    
    // Description: copies a currency object into this
    // Pre: const Currency& money - currency object to copy from this
    // Post:
    // Return: this
    virtual Currency& operator=(const Currency& money);
    
    // Description: lesser than operator for currency objects
    // Pre: const Currency& money - currency object to compare
    // Post:
    // Return: true if left hand side is less than right hand side
    bool operator<(const Currency& money) { return totalVal < money.getTotalVal(); }
    
    // Description: greater than operator for currency objects
    // Pre: const Currency& money - currency object to compare
    // Post:
    // Return: true if left hand side is greater than right hand side
    bool operator>(const Currency& money) { return totalVal > money.getTotalVal(); }

    // Description: equals to operator for currency objects
    // Pre: const Currency& money - currency object to compare
    // Post:
    // Return: true if left hand side is equal to than right hand side
    bool operator==(const Currency& money) { return totalVal == money.getTotalVal(); }
    
    // Description: not equals to operator for currency objects
    // Pre: const Currency& money - currency object to compare
    // Post:
    // Return: true if left hand side is not equal to than right hand side
    bool operator!=(const Currency& money) { return totalVal != money.getTotalVal(); }
    
    // Description: gets name of currency
    // Pre:
    // Post:
    // Return: name of currency as a string
    virtual std::string getUnitName() const { return "unit"; }
    
    // Description: gets name of coin
    // Pre:
    // Post:
    // Return: name of coin as a string
    virtual std::string getFracName() const { return "whole"; }
    
    // Description: sets name of currency
    // Pre: string unitname - name of currency
    // Post:
    // Return:
    virtual void setUnitName(std::string unitName) {}
    
    // Description: gets name of coin
    // Pre: string fracName - name of coin
    // Post:
    // Return:
    virtual void setFracName(std::string fracName) {}
    
    // Description: makes sure values of coins are always stored correctly
    // Pre:
    // Post: modifies unitVal and fracVal based on totalVal
    // Return:
    void normalize();
protected:
    int unitVal;
    int fracVal;
    int totalVal;
private:
};
#endif /* Currency_h */
