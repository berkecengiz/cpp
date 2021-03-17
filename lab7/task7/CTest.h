//
//  CTest.h
//  lab7
//
//  Created by Adriana Wilkowska on 18/12/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include <iostream>
#ifndef CTest_h
#define CTest_h

using namespace std;

class CTest
{
public:
    CTest(int iVal)
    {
        i_val = iVal; cout << "Constructor CTest: " << i_val << "\n";
    }
    
    ~CTest()
    {
        cout << "Destructor CTest " << i_val << "\n";
    }

    void vPrint()
    {
        cout << i_val;
    };

private:
    int i_val;
};

#endif /* CTest_h */
