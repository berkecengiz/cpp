#include <iostream>
#include "CTreeDynamic.hpp"
#include "CTreeStatic.hpp"


void v_tree_static_test()
{
    CTreeStatic c_tree_static;
    c_tree_static.pcGetRoot()->vAddNewChild();
    c_tree_static.pcGetRoot()->vAddNewChild();
    c_tree_static.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_static.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_static.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_static.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_static.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree_static.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree_static.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_static.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_static.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree_static.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "Tree1_static: ";
    c_tree_static.vPrintTree();

    cout << "\n";
    CTreeStatic c_tree_2;
    c_tree_2.pcGetRoot()->vAddNewChild();
    c_tree_2.pcGetRoot()->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(9);
    c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(0);
    c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(5);
    c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(94);
    c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(06);

    cout << "Tree2_static: ";
    c_tree_2.vPrintTree();
    cout <<"\nMoved subtree :";
    c_tree_2.pcGetRoot()->pcGetChild(0)->vPrintAllBelow();
    c_tree_static.bMoveSubtree(c_tree_static.pcGetRoot()->pcGetChild(1)->pcGetChild(1),
                               c_tree_2.pcGetRoot()->pcGetChild(0));

    cout << "\nTree1_static after moving: ";
    c_tree_static.pcGetRoot()->vPrintAllBelow();
    cout << "\nTree2_static without moved subtree: ";
    c_tree_2.pcGetRoot()->vPrintAllBelow();
}

void v_tree_dynamic_test()
{
    CTreeDynamic c_tree_dynamic;
    c_tree_dynamic.pcGetRoot()->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dynamic.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_dynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree_dynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree_dynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree_dynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "Tree1_dynamic: ";
    c_tree_dynamic.vPrintTree();

    CTreeDynamic c_tree_dynamic_2;
    c_tree_dynamic_2.pcGetRoot()->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(1)->vSetValue(9);
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(0);
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(5);
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(94);
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(06);

    cout << "\nTree2_dynamic: ";
    c_tree_dynamic_2.vPrintTree();
    cout << "\nMoved subtree: ";
    c_tree_dynamic_2.pcGetRoot()->pcGetChild(0)->vPrintAllBelow();
    c_tree_dynamic.bMoveSubtree(c_tree_dynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1),
                               c_tree_dynamic_2.pcGetRoot()->pcGetChild(0));
    cout << "\nTree1_dynamic after moving: ";
    c_tree_dynamic.pcGetRoot()->vPrintAllBelow();
    cout << "\nTree2_dynamic without moved subtree: ";
    c_tree_dynamic_2.vPrintTree();
}

int main()
{
    cout << "STATIC TREE" <<endl;
    v_tree_static_test();
    cout << "\n";
    cout << "\nDYNAMIC TREE: \n";
    v_tree_dynamic_test();
    cout << "\n";
    return 0;
}
