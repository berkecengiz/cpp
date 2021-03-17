//
//  CFileThrowEx.hpp
//  lab4
//
//  Created by Adriana Wilkowska on 27/11/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CFileThrowEx_hpp
#define CFileThrowEx_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class CFileThrowEx
{
public:
    CFileThrowEx();
    CFileThrowEx(string sFileName);
    ~CFileThrowEx();
    
    void vOpenFile(string sFileName);
    void vCloseFile();
    void vPrintLine(string sText);
    void vPrintManyLines(vector<string> sText);
private:
    FILE *pf_file;
}; //class CFileThrowEx

#endif /* CFileThrowEx_hpp */
