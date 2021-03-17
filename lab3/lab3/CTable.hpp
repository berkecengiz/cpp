//
//  cTable.hpp
//  lab3
//

#ifndef CTable_hpp
#define CTable_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class CTable
{
private:
    string s_name ="";
    int* tab;
    const int default_size = 8;
    const string default_name = "default name";
    int tableLength = default_size;
    
public:
    
    CTable();
    CTable(string name, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();
    
    void vSetName(string name);
    string vGetName();
    
    int getTabSize();
    bool bSetSize(int iTableLen);
    
    CTable *pcClone();
    CTable *pcGetReverted();
    
    void fill_array();
    void display();
    
    int * operator + (CTable &pcOther);
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab2(CTable cTab, int iNewSize);
void v_fill_an_array(CTable **cTab, int ArrSize);
#endif /* CTable_hpp */
