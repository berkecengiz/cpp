//
//  CTab.cpp
//  lab8
//
//

#include "CTab.hpp"
#include <iostream>

using namespace std;

CTab::CTab(const CTab &cOther)
{
    v_copy(cOther);
    cout<< "Copied\n" ;
}

CTab::CTab(CTab &&cOther)
{
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    cOther.i_size = 0 ;
    cout<< "Moved\n" ;
}

CTab::~CTab()
{
    if(pi_tab != NULL){
        delete pi_tab;
    }
    cout<< "Destructed_task1\n" ;
}

bool CTab::bSetSize(int iNewSize)
{
    if (iNewSize > 0 && iNewSize != i_size) {
        int *pi_temp_tab = new int[iNewSize];
        for(int i = 0; i < iNewSize && i < i_size; i++) {
            pi_temp_tab[i] = pi_tab[i];
        }
        delete pi_tab;
        pi_tab = pi_temp_tab;
        i_size = iNewSize;
        return true;
    }
    return false;
}

CTab CTab::operator=(const CTab &cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    cout << "operator= \n";
    return (*this);
}

CTab& CTab::operator=(CTab && cOther)
{
    if (pi_tab != NULL) delete pi_tab;
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    cOther.i_size = 0;
    cout << "operator=(move)\n";
    return *this;
}

void CTab::v_copy(const CTab &cOther)
{
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for(int i = 0; i < cOther.i_size; i++) {
        pi_tab[i] = cOther.pi_tab[i];
    }
}
    


