// Wilson and Keith
// lab 5
// implement BST and BSTNode ADT
/*
 assumptions:
 1) each currency object is written on a newline in the file so the program validates input one line at a time
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
#include <string>
#include "BST.h"
#include "Currency.h"
using namespace std;

Currency* validateFileInput(const string curr)
{
    stringstream ss(curr);
    string whole = "",part = "";
    int bills = 0,coins = 0;
    ss>>whole>>bills>>coins>>part;
    if (!(ss.fail() || !(whole == "unit" && part == "frac") || !ss.eof()))
    {
        return new Currency(bills,coins);
    }
    return nullptr;
}
Currency* validateConsoleInput(const string curr,string &instruction)
{
    stringstream ss(curr);
    string whole = "",part = "";
    int bills = 0,coins = 0;
    ss>>instruction;
    if(!(instruction == "insert" || instruction == "search" || instruction == "delete" || instruction == "print" ||instruction == "end"))
    {
        instruction = "bad";
        return nullptr;
    }
    if((instruction == "print" || instruction == "end"))
    {
        if(!ss.eof())
        {
            instruction = "bad";
            return nullptr;
        }
        else
        {
            return nullptr;
        }
    }
    ss>>whole>>bills>>coins>>part;
    if (!(ss.fail() || !(whole == "unit" && part == "frac") || !ss.eof()))
    {
        return new Currency(bills,coins);
    }
    instruction = "bad";
    return nullptr;
}
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
        Currency* currency = validateFileInput(curr);
        if(currency!=nullptr)
        {
            bst.insertNode(*currency);
        }
        else
        {
            cout<<curr<<" ignored: improper formatting"<<endl;
        }
        delete currency;
        getline(fin, curr);
    }
    bst.printInOrder();
    
    cout<<"Type \"insert\", \"search\", or \"delete\" followed by a currency object to modify the BST. Type \"print\", \"end\" to print the BST inorder or end the program."<<endl;
    getline(cin,curr);
    while(curr != "end")
    {
        string instruction;
        Currency* currency = validateConsoleInput(curr,instruction);
        if(instruction == "bad")
        {
            cout<<curr<<" ignored: improper formatting"<<endl;
        }
        else
        {
            if(instruction == "print")
            {
                cout<<"breadth first traversal"<<endl;
                bst.printBreadthFirst();
                cout<<endl<<"in order traversal"<<endl;
                bst.printInOrder();
                cout<<endl<<"pre order traversal"<<endl;
                bst.printPreOrder();
                cout<<endl<<"post order traversal"<<endl;
                bst.printPostOrder();
                fout<<"breadth first traversal"<<endl;
                bst.printBreadthFirst(fout);
                fout<<endl<<"in order traversal"<<endl;
                bst.printInOrder(fout);
                fout<<endl<<"pre order traversal"<<endl;
                bst.printPreOrder(fout);
                fout<<endl<<"post order traversal"<<endl;
                bst.printPostOrder(fout);
            }
            else if(instruction == "insert")
            {
                bst.insertNode(*currency);
                cout<<*currency<<" has been inserted into the BST"<<endl;
            }
            else if(instruction == "search")
            {
                BSTNode<Currency>* temp = bst.search(*currency);
                if(temp == nullptr)
                {
                    cout<<*currency<<" is not in the BST"<<endl;
                }
                else
                {
                    cout<<*currency<<" is found in the BST"<<endl;
                }
            }
            else if(instruction == "delete")
            {
                bst.deleteNode(*currency);
                cout<<*currency<<" has been deleted from the BST"<<endl;
            }
            else
            {
                cout<<"Uncaugth error, instruction ignored"<<endl;
            }
        }
        cout<<endl<<"Type \"insert\", \"search\", or \"delete\" followed by a currency object to modify the BST. Type \"print\", \"end\" to print the BST inorder or end the program."<<endl;
        getline(cin,curr);
        delete currency;
    }
    
   
    cout<<"breadth first traversal"<<endl;
    bst.printBreadthFirst();
    cout<<endl<<"in order traversal"<<endl;
    bst.printInOrder();
    cout<<endl<<"pre order traversal"<<endl;
    bst.printPreOrder();
    cout<<endl<<"post order traversal"<<endl;
    bst.printPostOrder();
    fout<<"breadth first traversal"<<endl;
    bst.printBreadthFirst(fout);
    fout<<endl<<"in order traversal"<<endl;
    bst.printInOrder(fout);
    fout<<endl<<"pre order traversal"<<endl;
    bst.printPreOrder(fout);
    fout<<endl<<"post order traversal"<<endl;
    bst.printPostOrder(fout);
    
    //close files
    fin.close();
    fout.close();
    return 0;
}
