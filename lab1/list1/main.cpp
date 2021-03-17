
#include <stdio.h>
#include <iostream>

#include "tableAlloc.hpp"

using namespace std;

int main()
{
    cout << "Array size?" << endl;
    int input;
    cin >> input;
    const int iSize = input;

    v_alloc_table_add_5(iSize);

    int** piTable;
    cout << "Allocated: " << b_alloc_table_2_dim(piTable, 3, 5);
    print_tab(piTable, 3, 5);
    cout << "Deallocated: " << b_dealloc_table_2_dim(piTable, 3, 5);
    
    int* array;
    array = v_alloc(5);
    showArray(array, 5);
    de_alloc(&array);
    
    cout << "\nIs it working? " << v_alloc2(&array, 5);
    showArray(array, 5);
    de_alloc(&array);
    
    cout << "Yes\n";
        
    return 0;

}
