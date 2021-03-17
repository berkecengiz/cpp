//
//  CFileMain.cpp
//  lab4
//
//  Created by Adriana Wilkowska on 27/11/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#include "CFileLastError.hpp"
#include "CFileThrowEx.hpp"
#include "CFileErrCode.hpp"
#include <iostream>
#include <vector>


const int NUMBER_OF_OPENINGS = 10;

void v_open_file_throw_ex() {
    CFileThrowEx cFileThrowEx;
    for (int i = 0; i < NUMBER_OF_OPENINGS; i++) {
        cFileThrowEx.vOpenFile("abc.txt");
    }
    cFileThrowEx.vPrintLine("CFileThrowEx");
}

void v_open_file_err_code() {
    CFileErrCode cFileErrCode;
    for (int i = 0; i < NUMBER_OF_OPENINGS; i++) {
        cFileErrCode.bOpenFile("abc1.txt");
    }
    cFileErrCode.bPrintLine("CFileErrCode");
}

void v_open_file_last_err() {
    CFileLastError cFileLastError;
    for (int i = 0; i < NUMBER_OF_OPENINGS; i++) {
        cFileLastError.vOpenFile("abc2.txt");
    }
    cFileLastError.vPrintLine("CFileLastError");
    cFileLastError.vCloseFile();
}

int main() {
    v_open_file_throw_ex();
    v_open_file_err_code();
    v_open_file_last_err();
}

