//
//  CTable.cpp
//  task2
//
//  Created by Adriana Wilkowska on 30/10/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//


#include "CTable.hpp"
#include <iostream>
#include <string>


using namespace std;

void CTable::fill_array()
{
    for(int i=0; i<getLength(); i++){
        tab[i] = 0;
    }
}

CTable::CTable()
{
    tab = new int[DEFAULT_SIZE];
    length = DEFAULT_SIZE;
    s_name = DEFAULT_NAME;
    cout << "NO_ARGUMENTS " + s_name + "\n";
}

CTable::CTable(string s_name, int iTableLen)
{
    this->s_name = s_name;
    if (!(length<1)) {
        length = iTableLen;
        cout << "CTABLE_WITH_ARGUMENTS " + s_name + "\n";
        tab = new int[iTableLen];
    }
}

CTable::CTable(const CTable &other_ctable){
    tab = new int[other_ctable.length];

    if(!setSize(other_ctable.length)){
        cout << "Inizialization due to changing a size has failed\n";
    }
    s_name = other_ctable.s_name + "_clone";
    for(int i = 0; i <other_ctable.length; i++) {
        (tab)[i] = other_ctable.tab[i];
    }
    cout << "CTABLE_COPY" + s_name + "\n";
}

CTable* CTable::operator+(const CTable& rigth)
{
    CTable* newTable = new CTable(*this);
    int newSize = this->length + rigth.length;
    newTable->setSize(newSize);
    int j = 0;
    for(int i = this->length; i<newSize; i++) {
        newTable->vSetValueAt(i, rigth.tab[j]);
        j++;
    }
    return newTable;
}

//Destructor

CTable::~CTable()
{
    s_name = "";
    delete[] tab;
    cout << "CTABLE_DELETED" << endl;
}


//Methods
void CTable::setName(string new_name)
{
    this->s_name = new_name;
    cout << "CTABLE_NAME_CHANGED" + new_name << endl;
}

bool CTable::setSize(int size)
{
    if(size<0) return false;
    int *newTab = new int[size];

    for(int i=0;i<size;i++){
        newTab[i] = tab[i];
    }
    delete[] tab;
    tab = newTab;
    length = size;
    return true;
}

CTable* CTable::Clone()
{
    return new CTable(*this);
}


int CTable::getLength()
{
    return length;
}


void CTable::display()
{
    for(int i=0; i<getLength(); i++){
        cout << tab[i] << " " ;
    }
    cout << "" << endl;
}

void CTable::vSetValues(int iNewVal)
{
  for (int i = 0; i < getLength(); i++) {
    tab[i] = i + iNewVal;
    cout << tab[i] << " ";
  }
  cout << endl;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
  tab[iOffset] = iNewVal;
}

void v_fill_an_array(CTable **cTab, int ArrSize)
{
    for(int i=0; i<ArrSize; i++) {
        (cTab)[i]->fill_array();
    }
}

