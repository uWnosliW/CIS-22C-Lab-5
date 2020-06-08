//
//  main.cpp
//  Lab 5
//
//  Created by Wilson Wu on 6/7/20.
//  Copyright © 2020 None. All rights reserved.
//

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
    int a;
    cin>>a;
    return 0;
}
