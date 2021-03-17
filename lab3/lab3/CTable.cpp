#pragma once
#include "cTable.hpp"

using namespace std;

void CTable::fill_array()
{
    for(int i=0;i<getTabSize();i++){
        tab[i] = i;
    }
}

CTable::CTable()
{
    tab = new int[default_size];
    tableLength = default_size;
    s_name = default_name;
    cout << "without: '"<< s_name <<  "'\n";
}

CTable::CTable(string sName, int iTableLen)
{
    if(!(iTableLen<1)){
        s_name = sName;
        tableLength = iTableLen;
        cout << "parameter: '"<< s_name << "'\n";
        tab = new int[iTableLen];}
}

int CTable::getTabSize()
{
    return tableLength;
}

void CTable::display()
{
    cout << "\n Tab " << s_name << "\n";
    for(int i=0; i<getTabSize(); i++){
        cout << tab[i] << " ";
    }
    cout << "\n";
}

CTable::CTable(CTable &pcOther)
{
    tab = new int[pcOther.getTabSize()];
    if(!bSetSize(pcOther.getTabSize())){
        cout << "Inizialization due to changing a size has failed\n";
    }
    vSetName(pcOther.s_name+"_copy");
    for(int i=0; i<pcOther.getTabSize();i++){
        tab[i] = pcOther.tab[i];
    }
    cout << "copy: '" << s_name << "'\n";
}


CTable::~CTable()
{
    cout << "removing '" << s_name << "'\n";
    s_name = "";
    delete [] tab;
}


void CTable::vSetName(string name)
{
    s_name = name.c_str();
}

string CTable::vGetName()
{
    return s_name;
}


bool CTable::bSetSize(int iTableLen)
{
    if(iTableLen<1){
        return false;
    }
    
    int* newArray = new int[iTableLen];
    for(int i = 0; i<iTableLen;i++){
        newArray[i] = tab[i];
    }
    
    delete[] tab;
    tab = newArray;
    tableLength = iTableLen;
    
    return true;
}


CTable* CTable::pcClone(){
    return new CTable(*this);
}

int * CTable::operator + (CTable &pcOther)
{
    int i_new_table_size = this->getTabSize() + pcOther.getTabSize();
    int* i_new_table = new int[i_new_table_size];
    
    for (int i = 0; i < this->getTabSize(); i++){
        i_new_table[i] = this->tab[i];
    }
    for (int j = 0; j < pcOther.getTabSize(); j++){
        i_new_table[j] = pcOther.tab[j];
    }
    
    delete [] this->tab;
    this->tab = i_new_table;
    
    return i_new_table;
}

void v_mod_tab(CTable *pcTab, int iNewSize){
    (pcTab)->bSetSize(iNewSize);
}

void v_mod_tab2(CTable cTab, int iNewSize){
    cTab.bSetSize(iNewSize);
}

void v_fill_an_array(CTable **cTab, int ArrSize){
    for(int i=0; i<ArrSize; i++){
        (cTab)[i]->fill_array();
    }
}
