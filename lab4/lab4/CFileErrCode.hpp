//
//  CFileErrCode.hpp
//  lab4
//
//  Created by Adriana Wilkowska on 27/11/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CFileErrCode_hpp
#define CFileErrCode_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class CFileErrCode
{
public:
    CFileErrCode();
    CFileErrCode(string sFileName);
    ~CFileErrCode();
    
    bool bOpenFile(string sFileName);
    bool bCloseFile();
    bool bPrintLine(string sText);
    bool bPrintManyLines(vector<string> sText);
private:
    FILE *pf_file;
}; //class CFileErrCode

#endif /* CFileErrCode_hpp */
