//
//  main.cpp
//  lab8
//
//  Created by Adriana Wilkowska on 05/01/2020.
//  Copyright © 2020 Berke Cengiz. All rights reserved.
//

#include "CTab.hpp"
#include "CTable.hpp"
#include <iostream>

using namespace std;

CTable cCreateTab()
{
    CTable c_result;
    c_result.bSetNewSize(5);
    return(move(c_result));
}

int main() {
    
    //Test for task 1
    
    cout << "Task 1\n";
    CTab c_tab;
    CTab c_other;

    c_tab = move(c_other);
    
    //Test for task 2
    
    std::cout << "\nMyTest: \n";
    CTable t1("1", 1);
    t1.piGetTable()[0] = 1;
    CTable t2("2", 2);
    t2.piGetTable()[0] = 2;
    t2.piGetTable()[1] = 2;
    CTable t3("3", 3);
    t3.piGetTable()[0] = 3;
    t3.piGetTable()[1] = 3;
    t3.piGetTable()[2] = 3;
    
    t1.vPrint();
    t2.vPrint();
    t3.vPrint();
    
    t1 = t2+t3;

    t1.vPrint();
    t2.vPrint();
    t3.vPrint();
    
    cout << "\nMyTest2: \n";
    CTable tab("tab", 1);
    CTable tab1("tab1", 3);
    CTable tab2("tab2", 2);
    tab1.piGetTable()[0] = 11;
    tab1.piGetTable()[1] = 12;
    tab1.piGetTable()[2] = 13;

    tab2.piGetTable()[0] = 21;
    tab2.piGetTable()[1] = 22;

    tab = tab1 + tab2 + 77;
    
    cout << "Results: /n";
    tab1.vPrint();
    tab2.vPrint();
    tab.vPrint();
    cout << "\nEnd\n";

    
    
    return 0;
}
