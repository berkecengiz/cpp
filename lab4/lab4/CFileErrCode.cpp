//
//  CFileErrCode.cpp
//  lab4
//
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include "CFileErrCode.hpp"
using namespace std;

CFileErrCode::CFileErrCode()
{
}

CFileErrCode::CFileErrCode(string sFileName)
{
    bOpenFile(sFileName);
}


CFileErrCode::~CFileErrCode()
{
    if (pf_file != NULL) bCloseFile();
}

bool CFileErrCode::bOpenFile(string sFileName)
{
    pf_file = fopen(sFileName.c_str(), "w+");
    if(pf_file != NULL)
        return true;
    return false;
}
bool CFileErrCode::bCloseFile()
{
    if (pf_file != NULL) {
        fclose(pf_file);
        pf_file = NULL;
        return true;
    } else return false;
}

bool CFileErrCode::bPrintLine(string sText)
{
    if (pf_file != NULL){
        fprintf(pf_file, "%s", sText.c_str());
        return true;
    } return false;
}

bool CFileErrCode::bPrintManyLines(vector<string> sText)
{
    for (int i = 0; i < sText.size(); i++) {
        bPrintLine(sText[i]);
    }
    return true;
}
