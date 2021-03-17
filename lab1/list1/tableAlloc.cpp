#pragma once
#include <iostream>

#include "tableAlloc.hpp"

using namespace std;

void v_alloc_table_add_5(int iSize)
{
    if (iSize <= 0) {
        cout << "Size should be bigger than 0" << endl;
        return;
    }

    // allocate memory
    int* A ;
    A = new int[iSize];

    // assign values
    for (int i = 0; i < iSize; i++)
        A[i] = i + 5;

    //print
    for (int i = 0; i < iSize; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    //dellocate memory
    delete[] A;
}

bool b_alloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0)
        return false;
    
    //  create array of pointers
    *piTable = new int[iSizeX];

    //  allocate memory for each row
    for (int i = 0; i < iSizeX; i++)
        piTable[i] = new int[iSizeY];

    // assign
    for (int i = 0; i < iSizeX; i++)
        for (int j = 0; j < iSizeY; j++)
            piTable[i][j] = rand() % 10;
    return true;

}

// print
void print_tab(int **piTable, int iSizeX, int iSizeY) {
    cout << "\nShow the array:\n";
    for (int i = 0; i < iSizeX; i++) {
        for (int j = 0; j < iSizeY; j++){
            cout << piTable[i][j] << " ";
        }
        cout << "\n";
    }
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
    if (iSizeX <= 0 || iSizeY <= 0)
        return false;
    
    for (int i = 0; i < iSizeX; i++)
        delete(piTable[i]);
    
    delete piTable;
    
    return true;
}

//Additional tasks
void showArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

int *v_alloc(int size) {
    if (size < 1 || size > 1000)
        return NULL;

    int *array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = i + 5;

    return array;
}

bool v_alloc2(int **ptr, int size) {
    if (size < 1 || size > 1000)
        return false;

    *ptr = new int[size];

    for (int i = 0; i < size; i++)
        (*ptr)[i] = i + 10;

    return true;
}

void de_alloc(int **ptr) {
    delete(*ptr);
    *ptr = NULL;
}
