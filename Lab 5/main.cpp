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

Currency* validateFileInput(const string curr);
/* This function validates each row in file input
   Pre: const string curr - data in a row in input file
   Post:
   Return: pointer to a newly created Currency obj, else nullptr
*/

Currency* validateConsoleInput(const string curr, string& instruction);
/* This function validates console input
   Pre: const string curr - each command in console inputted by user
        string& instruction - specific instruction keyword by user
   Post:
   Return: pointer to newly created Currency obj, else nullptr
*/

// /Users/Wilson/Documents/De Anza/Lab 5/Lab 5/test.txt
// /Users/Wilson/Documents/De Anza/Lab 5/Lab 5/output.txt
int main()
{
    //get file path and initialize fstreams
    string fileIn,fileOut;
    cout<<"Please enter the absolute file path of the input file ensuring that special characters are escaped."<<endl;
    getline(cin,fileIn);
    //fileIn = fileIn + "input.txt";
    cout<<"Please enter the absolute file path of the output file ensuring that special characters are escaped."<<endl;
    getline(cin,fileOut);
    //fileOut = fileOut + "output.txt";
    
    ifstream fin(fileIn);
    if (!fin)
    {
        cerr << "Error in opening file." << endl;
        exit(0);
    }
    ofstream fout(fileOut);
    
    /* Take input from file */
    Currency currency;
    BST<Currency> bst;
    string curr;
    getline(fin, curr);
    while (!fin.eof())
    {
        Currency* currency = validateFileInput(curr);
        if (currency != nullptr)
        {
            bst.insertNode(*currency);
        }
        else
        {
            cerr << curr << " ignored: improper formatting" << endl;
            fout << curr << " ignored: improper formmating" << endl;
        }
        delete currency;
        getline(fin, curr);
    }
        
    cout<<"Type \"insert\", \"search\", or \"delete\" followed by a space, then a currency object to modify the BST. Type \"print\", \"end\" to print the BST inorder or end the program."<<endl;

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
                /* output to console*/
                cout<<"breadth first traversal"<<endl;
                bst.printBreadthFirst();
                cout<<endl<<"in order traversal"<<endl;
                bst.printInOrder();
                cout<<endl<<"pre order traversal"<<endl;
                bst.printPreOrder();
                cout<<endl<<"post order traversal"<<endl;
                bst.printPostOrder();
                fout<<"breadth first traversal"<<endl;
                
                /* output to file */
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
                try
                {
                bst.deleteNode(*currency);
                cout<<*currency<<" has been deleted from the BST"<<endl;

                }
                catch (string err)
                {
                    cout << err << endl;
                }
            }
            else
            {
                cout<<"Uncaught error, instruction ignored"<<endl;
            }
        }
        cout<<endl<<"Type \"insert\", \"search\", or \"delete\" followed by a currency object to modify the BST. Type \"print\", \"end\" to print the BST inorder or end the program."<<endl;
        getline(cin,curr);
        delete currency;
    }
    /* output to console */
    cout<<"breadth first traversal"<<endl;
    bst.printBreadthFirst();
    cout<<endl<<"in order traversal"<<endl;
    bst.printInOrder();
    cout<<endl<<"pre order traversal"<<endl;
    bst.printPreOrder();
    cout<<endl<<"post order traversal"<<endl;
    bst.printPostOrder();
    
    /* output to files */
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
 
    cout << "Finished running program. Press \"a\" and hit \"enter\" to end program\n";
    string endProgram;
    cin >> endProgram;
    
    return 0;
    
}
Currency* validateFileInput(const string curr)
{
    stringstream ss(curr);
    string whole = "", part = "";
    int bills = 0, coins = 0;
    ss >> whole >> bills >> coins >> part;
    
    if (!(ss.fail() || !(whole == "unit" && part == "frac") || !ss.eof()))
    {
        return new Currency(bills,coins);
    }
    return nullptr;
}

Currency* validateConsoleInput(const string curr, string& instruction)
{
    stringstream ss(curr);
    string whole = "", part = "";
    int bills = 0, coins = 0;
    ss>>instruction;
    for (auto i = 0; i < instruction.length(); i++)
    {
        instruction[i] = tolower(instruction[i]);
    }
    
    if (! (instruction =="insert" || instruction == "search" || instruction == "delete" || instruction == "print" || instruction == "end"))
    {
        instruction = "bad";
        return nullptr;
    }
    if ((instruction=="print" || instruction == "end"))
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
    
    for (auto i = 0; i < whole.length(); i++)
    {
        whole[i] = tolower(whole[i]);
        part[i] = tolower(part[i]);
    }
    
    if (!(ss.fail() || !(whole == "unit" && part == "frac") || !ss.eof()))
    {
        return new Currency(bills,coins);
    }
    instruction="bad";
    return nullptr;
}
