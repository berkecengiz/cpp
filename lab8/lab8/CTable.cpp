//
//  CTable.cpp
//  lab8
//

#include "CTable.hpp"
#include <iostream>
#include <string>

using namespace std;

const string S_DEFAULT_NAME = "myTable";
const int I_DEFAULT_TABLE_LEN = 10;

CTable::CTable()
{
    s_name = S_DEFAULT_NAME;
    i_table_len = I_DEFAULT_TABLE_LEN;
    
    pi_table = new int[i_table_len];
    
    cout << "\nConstructor without parameters: " + s_name;
}

CTable::CTable(string sName, int iTableLen)
{
    s_name = sName;
    if (iTableLen > 0) {
        i_table_len = iTableLen;
        pi_table = new int[iTableLen];
        cout << "\nConstructor with parameters: " + s_name;
    }
    else cout << "\nFailed to create\n";
}

CTable::CTable(const CTable &pcOther)
{
    s_name = pcOther.s_name + "_copy";
    i_table_len = pcOther.i_table_len;
    pi_table = new int[i_table_len];
    
    for(int i = 0; i < i_table_len; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
    cout << "\nCopied Constructor:" + s_name;
}

CTable::CTable(CTable &&cOther)
{
    s_name = cOther.s_name + "_move";
    pi_table = cOther.pi_table;
    i_table_len = cOther.i_table_len;
    cOther.pi_table = NULL;
    cout << "\nTransfered Constructor:" ;
}

CTable::~CTable()
{
    delete pi_table;
    cout << "\nDestructed:" + s_name; //or sGetName()
}

void CTable::vSetName(string sName)
{
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
    if(iTableLen > 0 && iTableLen != i_table_len) {
        int *i_temp_table = new int[iTableLen];
        for(int i = 0; i < iTableLen && i < i_table_len; i++) {
            i_temp_table[i] = pi_table[i];
        }
        delete[] pi_table;
        pi_table = i_temp_table;
        i_table_len = iTableLen;
        return true;
    }
    return false;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
    if(iOffset < iGetSize() && iOffset >=0) {
        pi_table[iOffset] = iNewVal;
    }
    else cout << "The offset indicated is outside the table!\n";
}

int CTable::iGetSize()
{
    return i_table_len;
}

string CTable::sGetName()
{
    return s_name;
}

int* CTable::piGetTable()
{
    return pi_table;
}

CTable * CTable::pcClone()
{
    return new CTable(*this);
}

CTable * CTable::pcGetReverted(){
    CTable *pc_reverted = new CTable(s_name + "_rev", i_table_len);
    //cTable *pc_reverted = new CTable(*this)
    
    for (int i = 0; i < i_table_len; i++) {
        pc_reverted->piGetTable()[i] = pi_table[i_table_len - 1 - i];
    }
    return pc_reverted;
}

void CTable::vPrint()
{
    cout << "\n\n" + s_name +":\n";
    for(int i = 0 ; i < i_table_len; i++) {
        cout << pi_table[i] << " ";
    }
}

CTable CTable::operator+(int iNewVal)
{
    cout << "\nOperator+(val):\n " ;
    CTable c_result(sGetName() + "_val", i_table_len + 1);
    for(int i = 0 ; i < i_table_len; i++) {
        c_result.vSetValueAt(i, pi_table[i]);
    }
    for(int i = i_table_len ; i < i_table_len +1; i++) {
        c_result.vSetValueAt(i_table_len, iNewVal);
    }
    
    return c_result;
}

CTable CTable::operator+(CTable &pcOther)
{
    cout << "\nOperator+(table)";
    int i_new_tab_len = i_table_len + pcOther.iGetSize();
    CTable c_result(sGetName() + "_" + pcOther.sGetName(), i_table_len + pcOther.iGetSize());
    
    for(int i = 0; i < i_table_len; i++) {
        c_result.vSetValueAt(i, pi_table[i]);
    }
    
    for(int i = i_table_len; i < i_new_tab_len; i++) {
        c_result.vSetValueAt(i, pcOther.piGetTable()[i - i_table_len]);
    }
    return move(c_result);
}

CTable CTable::operator=(const CTable &pcOther)
{
    cout << "\nOperator=\n";
    vSetName(pcOther.s_name+"_operator=");
    bSetNewSize(pcOther.i_table_len);
    for (int i = 0; i < i_table_len; i++) {
        pi_table[i] = pcOther.pi_table[i];
    }
    return *this;
}


CTable& CTable::operator=(CTable &&pcOther)
{
    if (pi_table != NULL) {
        delete[] pi_table;
    }
    std::cout << "\n\n\nOperator=(move)";
    vSetName(pcOther.s_name+"_operator=(move)");
    pi_table = pcOther.pi_table;
    i_table_len = pcOther.i_table_len;
    pcOther.pi_table = NULL;
    pcOther.i_table_len = 0;
    return *this;
}
