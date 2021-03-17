//
//  CTable.hpp
//  task2
//
//  Created by Adriana Wilkowska on 30/10/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CTable_hpp
#define CTable_hpp

#include <stdio.h>
#include "CTable.hpp"
#include <iostream>

using namespace std;

class CTable {
public:
    //Constructors
    CTable();
    CTable(string s_name, int iTableLen);
    CTable(const CTable &other_ctable);
    
    //Deconstructor
    ~CTable();
    
    //Methods    
    bool setSize(int size);
    CTable *Clone();
    int getLength();
    void setName(string new_name);
    void fill_array();
    void display();
    void vSetValues(int iNewVal);
    void vSetValueAt(int iOffset, int iNewVal);

    
    CTable* operator+(const CTable& rigth);

    
private:
    int length;
    int * tab;
    string s_name;

    const int DEFAULT_SIZE = 10;
    const string DEFAULT_NAME = "CTable";
};

void v_fill_an_array(CTable **cTab, int ArrSize);
void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab2(CTable cTab, int iNewSize);


#endif /* CTable_hpp */
