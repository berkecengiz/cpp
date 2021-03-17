//
//  main.cpp
//  task2
//
//  Created by Adriana Wilkowska on 30/10/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include <iostream>
#include "CTable.hpp"

int main()
{
    CTable c_tab_0, c_tab_1;
    c_tab_0.setSize(6);
    c_tab_1.setSize(4);
    c_tab_0.display();
    c_tab_1.display();
    
    int tab0Length = c_tab_0.getLength();
    int tab1Length = c_tab_1.getLength();
    
    for (int i = 0; i < tab0Length; i++) {
      c_tab_0.vSetValueAt(i, i+1);
    }
    for (int i = 0; i < tab1Length; i++) {
      c_tab_1.vSetValueAt(i, i+1);
    }
    
    c_tab_1.vSetValueAt(2,123);
    c_tab_0.display();
    c_tab_1.display();
    
    CTable *c_result = c_tab_0 + c_tab_1;
    c_result->display();


    cout << "Finishing the program\n";
    return 0;
}
