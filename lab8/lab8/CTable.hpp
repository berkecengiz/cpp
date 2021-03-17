//
//  CTable.hpp
//  lab8
//
//

#ifndef CTable_hpp
#define CTable_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class CTable {
    
public:
    CTable();
    CTable(string sName, int iTableLen);
    CTable(const CTable &pcOther);
    CTable(CTable &&pcOther);
    ~CTable();

    void vSetName(string sName);
    bool bSetNewSize(int iTableLen);
    void vSetValueAt(int iOffset, int iNewVal);

    int iGetSize();
    string sGetName();
    int* piGetTable();

    CTable *pcClone();
    CTable *pcGetReverted();

    void vPrint();
    
    CTable operator+(int iNewVal);
    CTable operator+(CTable &pcOther);
    CTable operator=(const CTable &pcOther);
    CTable& operator=(CTable &&pcOther);
    
private:
    string s_name;
    int i_table_len;
    int *pi_table;
};

#endif /* CTable_hpp */
