// Wilson and Keith
// lab 5
// implement BST and BSTNode ADT
/*
 assumptions:
 1) a given BST can only have one specific type of currency, so any other currency types in the file or console will be ignored
 2) first currency object in the file defines what type the BST will be
 */
/*
 pseudocode:
 1) prompt user for the input and output file paths and open the files
 2) read in first element
 3) declare BST of that currency type
 4) while not end of file
 5)     read next currency object
 6)     check formatting errors
 7)         check same same currency type
 8)             insert into BST
 9) while user wants to continue
 10)    read and validate command (add/search/delete) and currency object
 11)    perform operation on BST
 12)print all four traversals to console and output file on exit
 13)close files, delete dynamically allocated objects
 */
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include "Rupee.h"
#include "Real.h"
#include "Yen.h"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Currency* a = new Dollar(50,50);
    Currency* b = new Rupee(50,50);
    cout<<((*a)==(*b))<<endl;
    ifstream fin("//Users//Wilson//Documents//De Anza//Lab 5//Lab 5//test.txt");
    BST<Dollar> bstDollar;
    Dollar temp;
    fin>>temp;
    while(!(fin.eof()))
    {
        cout<<temp;
        bstDollar.insertNode(temp);
        fin>>temp;
    }
    cout<<endl;
    cout<<"in order"<<endl;
    bstDollar.printInOrder();
    cout<<endl<<"pre order"<<endl;
    bstDollar.printPreOrder();
    cout<<endl<<"post order"<<endl;
    bstDollar.printPostOrder();
    cout<<endl<<"breadth"<<endl;
    bstDollar.printBreadthFirst();
    fin.close();
    temp = Dollar(50,50);
    cout<<(bstDollar.search(temp) == nullptr)<<endl;
    int asdf;
    cin>>asdf;
    return 0;
}
