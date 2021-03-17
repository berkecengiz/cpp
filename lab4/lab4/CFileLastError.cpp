//
//  CFileLastError.cpp
//  lab4
//
//  Created by Adriana Wilkowska on 27/11/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include "CFileLastError.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CFileLastError::b_last_error;

CFileLastError::CFileLastError()
{
    b_last_error = false;
}

CFileLastError::CFileLastError(string sFileName)
{
    b_last_error = false;
    vOpenFile(sFileName);
}

CFileLastError::~CFileLastError()
{
    if (pf_file != NULL) vCloseFile();
}

void CFileLastError::vOpenFile(string sFileName)
{
    b_last_error = false;
    if(pf_file != NULL){
        b_last_error = true;
    }
    else{
        pf_file = fopen(sFileName.c_str(), "w+");
        
        if (pf_file == NULL) {
            b_last_error = true;
            return;
        }
    }
}

void CFileLastError::vCloseFile()
{
    b_last_error = false;
    if (pf_file != NULL) {
        fclose(pf_file);
        pf_file = NULL;
    } else b_last_error = true;
}

void CFileLastError::vPrintLine(string sText)
{
    b_last_error = false;
    if (pf_file == NULL) {
        b_last_error = true;
        return;
    }
    fprintf(pf_file, "%s", sText.c_str());
}

void CFileLastError::vPrintManyLines(vector<string> sText)
{
    for (string s : sText) {
        vPrintLine(s);
    }
    
}
