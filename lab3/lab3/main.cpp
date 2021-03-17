//
//  main.cpp
//  lab3
//
#include "CTable.hpp"

using namespace std;
int main()
{
    CTable ct;
    CTable ct2("Table2", 3);
    CTable ct3("Table3", 6);
    ct2.fill_array();
    ct3.fill_array();
    ct3.display();
    ct2.display();
    
    ct2 + ct3;
    ct2.display();
    ct3.display();
    
    v_mod_tab(&ct2, 12);
    v_mod_tab2(ct3, 13);
    
    CTable copy(ct2);
    CTable *pc_new_tab = copy.pcClone();
    pc_new_tab->display();
    
    int sizear = 10;
    CTable** cTab = new CTable*[sizear];
    
    for(int i=0;i<sizear;i++) {
        cTab[i] = new CTable;
    }
    
    v_fill_an_array(cTab, sizear);
    
    for(int i=0;i<sizear;i++) {
        (cTab)[i]->~CTable();
    }
    
    cout << "Finishing the program\n";
    return 0;
}
