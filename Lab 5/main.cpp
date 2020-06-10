// Wilson and Keith
// lab 5
// implement BST and BSTNode ADT
/*
 assumptions:
 1) a given BST can only have one specific type of currency, so any other currency types in the file or console will be ignored
 2) first currency object in the file defines what type the BST will be
 3) currencies are formatted correctly in the input file
 */
/*
 pseudocode:
 1) prompt user for the input and output file paths and open the files
 2) read in first element
 3) declare BST of that currency type
 4) while not end of file
 5)     read next currency object
 6)     check its formatted correctly and contains the correct information
 7)         insert into BST
 8) while user wants to continue
 9)    read and validate command (add/search/delete) and currency object
 10)    perform operation on BST
 11)print all four traversals to console and output file on exit
 12)close files, delete dynamically allocated objects
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "BST.h"
#include "Currency.h"
using namespace std;

// /Users/Wilson/Documents/De Anza/Lab 5/Lab 5/test.txt
// /Users/Wilson/Documents/De Anza/Lab 5/Lab 5/output.txt
int main(int argc, const char * argv[]) {
    
    //get file path and initialize fstreams
    string fileIn,fileOut;
    cout<<"Please enter the absolute file path of the input file ensuring that special characters are escaped."<<endl;
    //getline(cin,fileIn);
    fileIn = "/Users/Wilson/Documents/De Anza/Lab 5/Lab 5/test.txt";
    cout<<"Please enter the absolute file path of the output file ensuring that special characters are escaped."<<endl;
    //getline(cin,fileOut);
    fileOut = "/Users/Wilson/Documents/De Anza/Lab 5/Lab 5/output.txt";
    ifstream fin(fileIn);
    ofstream fout(fileOut);

    //declare BST with type of first currency object
    Currency currency;
    BST<Currency> bst;
    string curr;
    getline(fin, curr);
    while(!fin.eof())
    {
        stringstream ss(curr);
        string whole = "",part = "";
        int bills = 0,coins = 0;
        ss>>whole>>bills>>coins>>part;
        if(ss.fail() || !(whole == "unit" && part == "frac"))
        {
            cout<<curr<<" ignored because of incorrect formatting"<<endl;
        }
        else
        {
            bst.insertNode(Currency(bills,coins));
        }
        getline(fin, curr);
    }
    bst.printInOrder();

    //close files
    fin.close();
    fout.close();
    return 0;
}
