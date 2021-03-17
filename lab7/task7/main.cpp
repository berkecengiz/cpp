//
//  main.cpp
//  lab7
//

#include "CTest.h"
#include "CMySmartPointer.h"
#include "CRefCounter.h"
#include <iostream>

using namespace std;

int main()
{
    CMySmartPointer<CTest> c_mySmartPointer1(new CTest(1));
    CMySmartPointer<CTest> c_mySmartPointer2(new CTest(2));
    CMySmartPointer<CTest> c_mySmartPointer3(new CTest(3));

    cout << "\nAssigining the Pointers\n";
    c_mySmartPointer3 = c_mySmartPointer2 = c_mySmartPointer1;
    cout << "\nAfter Assigning\n";
    
    return 0;
    
}
