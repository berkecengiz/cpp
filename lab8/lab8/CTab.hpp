//
//  CTab.hpp
//  lab8
//
//  Created by Adriana Wilkowska on 05/01/2020.
//  Copyright © 2020 Berke Cengiz. All rights reserved.
//

#ifndef CTab_hpp
#define CTab_hpp

#include <stdio.h>
#define DEF_TAB_SIZE 10

class CTab
{
public:
    CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
    CTab(int iSize) { pi_tab = new int[iSize]; i_size = iSize; }
    
    CTab(const CTab &cOther);
    CTab(CTab &&cOther);
    ~CTab();

    CTab operator=(const CTab &cOther);
    CTab& operator=(CTab &&cOther);
    
    bool bSetSize(int iNewSize);
    int iGetSize() { return(i_size); }
    int* getTab() { return pi_tab; }


private:
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;
};


#endif /* CTab_hpp */
