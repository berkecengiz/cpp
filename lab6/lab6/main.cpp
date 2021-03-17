//
//  main.cpp
//  lab6
//
//  Created by Adriana Wilkowska on 04/12/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include <iostream>
#include "CTreeDynamic.h"
#include <string>

using namespace std;

int main()
{
    
    cout << "Tree 1:" ;
    
    CTreeDynamic<string> *c_tree = new CTreeDynamic<string>();
    CNodeDynamic<string> *c_root = c_tree->pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue("1");
    c_root->pcGetChild(1)->vSetValue("2");
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue("11");
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue("12");
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue("21");
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue("22");
    c_tree->vPrintTree();
    
    cout << "\n" ;

    cout << "Tree 2:" ;

    CTreeDynamic<string> *c_tree2 = new CTreeDynamic<string>();
    CNodeDynamic<string> *c_root2 = c_tree2->pcGetRoot();
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue("1");
    c_root2->pcGetChild(1)->vSetValue("9");
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue("0");
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue("5");
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->vAddNewChild();
    c_root2->pcGetChild(1)->pcGetChild(0)->vSetValue("94");
    c_root2->pcGetChild(1)->pcGetChild(1)->vSetValue("06");
    c_tree2->vPrintTree();
    
    
    cout << "\n" ;
    
    cout << "\nTrees after moving: \n";
    c_tree2->bMoveSubtree(c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1), c_tree2->pcGetRoot()->pcGetChild(0));
    cout << "Tree 1:" ;
    c_tree->vPrintTree();
    cout << "\n" ;
    cout << "Tree 2:" ;
    c_tree2->vPrintTree();
    cout << "\n" ;

    return 0;
}

