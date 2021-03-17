//
//  CFileLastError.hpp
//  lab4
//
//  Created by Adriana Wilkowska on 27/11/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CFileLastError_hpp
#define CFileLastError_hpp

#include <stdio.h>
#include <string> 
using namespace std;

class CFileLastError
{
private:
    static bool b_last_error;
    FILE *pf_file;
    
public:

    CFileLastError();
    CFileLastError(string sFileName);
    ~CFileLastError();
    

    void vOpenFile(string sFileName);
    void vCloseFile();
    void vPrintLine(string sText);
    void vPrintManyLines(vector<string> sText);

    static bool bGetLastError() { return(b_last_error); }
};                 //class CFileLastError


#endif /* CFileLastError_hpp */
