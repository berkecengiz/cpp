//
//  CMscnProblem.cpp
//  lab9
//
//  Copyright © 2020 Berke Cengiz. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include "CMscnProblem.hpp"
#include <iostream>

using namespace std;

CMscnProblem::CMscnProblem()
{
    iSupp = 1;
    iFact = 1;
    iWare = 1;
    iShop = 1;
    
    // Productive Power
    pp_supp = new double[iSupp];
    pp_fact = new double[iFact];
    pp_ware = new double[iWare];
    pp_shop = new double[iShop];
    
    // cost transportation
    cost_supp = new double* [iSupp];
    for(int i = 0; i < iSupp; i++){
        cost_supp[i] = new double[iFact];
    }
    cost_fact = new double* [iFact];
    for(int i = 0; i < iFact; i++){
        cost_fact[i] = new double[iWare];
    }
    cost_ware = new double* [iWare];
    for(int i = 0; i < iWare; i++){
        cost_ware[i] = new double[iShop];
    }
    
    // price of deal
    pd_supp = new double[iSupp];
    pd_fact = new double[iFact];
    pd_ware = new double[iWare];
    
    price_shop = new double[iShop];  // income
    
    //max min
    xmm_sup = new double* [2 * iShop];
    for(int i = 0; i < 2 * iShop; i++){
        xmm_sup[i] = new double[iFact];
    }
    xmm_fact = new double* [2 * iFact];
    for(int i = 0; i < 2 * iFact; i++){
        xmm_fact[i] = new double[iWare];
    }
    xmm_ware = new double* [2 * iWare];
    for(int i = 0; i < 2 * iWare; i++){
        xmm_ware[i] = new double[iShop];
    }
    
    //amount of products
    x_sup = new double* [iSupp];
    for(int i = 0; i < iSupp; i++){
        x_sup[i] = new double[iFact];
    }
    x_fact = new double* [iFact];
    for(int i = 0; i < iFact; i++){
        x_fact[i] = new double[iWare];
    }
    x_ware = new double* [iWare];
    for(int i = 0; i < iWare; i++){
        x_ware[i] = new double[iShop];
    }
    
}

CMscnProblem::~CMscnProblem()
{
    delete [] pp_supp;
    delete [] pp_fact;
    delete [] pp_ware;
    delete [] pp_shop;
    
    for(int i = 0; i < iSupp; i++){
        delete[] cost_supp[i];
    }
    delete [] cost_supp;

    for(int i = 0; i < iFact; i++){
        delete[] cost_fact[i];
    }
    delete [] cost_fact;


    for(int i = 0; i < iWare; i++){
        delete[] cost_ware[i];
    }
    delete [] cost_ware;
    
    delete [] pd_supp;
    delete [] pd_fact;
    delete [] pd_ware;
    delete [] price_shop;
    
    for(int i = 0; i < iSupp; i++){
        delete [] xmm_sup[i];
    }
    delete [] xmm_sup;

    for(int i = 0; i < iFact; i++){
        delete [] xmm_fact[i];
    }
    delete [] xmm_fact;

    for(int i = 0; i < iWare; i++){
        delete [] xmm_ware[i];
    }
    delete [] xmm_ware;
    
    for(int i = 0; i < iSupp; i++){
        delete [] x_sup[i];
    }
    delete [] x_sup;

    for(int i = 0; i < iFact; i++){
        delete [] x_fact[i];
    }
    delete [] x_fact;

    for(int i = 0; i < iWare; i++){
        delete [] x_ware[i];
    }
    delete [] x_ware;
}

bool CMscnProblem::bSetSupp(int iVal)
{
    if(iVal <= 0){
        cout << "Incorrect value!" <<endl;
        return false;
    }
    else if(iVal == iSupp){
        cout << "Nothing changed!" <<endl;
        return false;
    }
    else {
        double* pp_new_sup = new double[iVal];
        double* pd_new_sup = new double[iVal];
        double** cost_new_supp = new double*[iVal];
        double** x_new_sup = new double*[iVal];
        double** xmm_new_sup = new double*[2 * iVal];
        
        for(int i = 0; (i < iVal) && (i < iSupp); i++){
            pp_new_sup[i] = pp_supp[i];
            pd_new_sup[i] = pd_supp[i];
            cost_new_supp[i] = cost_supp[i];
            x_new_sup[i] = x_sup[i];
        }
        
        for(int i = 0; (i < 2 * iVal) && (i < 2 * iSupp); i++) {
            xmm_new_sup[i] = xmm_sup[i];
        }
        
        if(iSupp < iVal) {
            for(int i = iSupp; i < iVal; i++) {
                cost_new_supp[i] = new double[iFact];
                x_new_sup[i] = new double[iFact];
            }
            for(int i = 2 * iSupp; i < 2 * iVal; i++) {
                xmm_new_sup[i] = new double[iFact];
            }
        }
        
        delete [] pp_supp;
        pp_supp = pp_new_sup;

        delete [] pd_supp;
        pd_supp = pd_new_sup;

        delete [] cost_supp;
        cost_supp = cost_new_supp;

        delete [] x_sup;
        x_sup = x_new_sup;

        delete [] xmm_sup;
        xmm_sup = xmm_new_sup;

        iSupp = iVal;
        return true;
    }
}

bool CMscnProblem::bSetFact(int iVal)
{
    if(iVal < 0) {
        cout << "Incorrect Value!" <<endl;
        return false;
    }
    else if(iVal == iFact){
        cout << "Nothing Changed!" <<endl;
        return false;
    }
    else {
        double* pp_new_fact = new double[iVal];
        double* pd_new_fact = new double[iVal];
        double** cost_new_fact = new double*[iVal];
        double** cost_new_supp = new double*[iSupp];
        double** x_new_fact = new double*[iVal];
        double** x_new_sup = new double*[iSupp];
        double** xmm_new_fact = new double*[2*iVal];
        double** xmm_new_sup = new double*[2*iSupp];
        
        for(int i = 0; i < iSupp; i++){
            cost_new_supp[i] = new double[iVal];
            x_new_sup[i] = new double[iVal];
        }
        for(int i = 0; i < 2 * iSupp; i++) {
            xmm_new_sup[i] = new double[iVal];
        }
        
        for(int i = 0 ; i < iSupp; i++) {
            for(int j = 0; j < iVal; j++) {
                cost_new_supp[i][j] = cost_supp[i][j];
                x_new_sup[i][j] = x_sup[i][j];
            }
        }
        
        for(int i = 0; i < 2 * iSupp; i++) {
            for(int j = 0; j < 2 * iVal; j++) {
                xmm_new_sup[i][j] = xmm_sup[i][j];
            }
        }
        
        for(int i = 0; (i < iVal) && (i < iFact); i++){
            cost_new_fact[i] = new double[iWare];
            x_new_fact[i] = new double[iWare];
            cost_new_fact[i] = cost_fact[i];
            x_new_fact[i] = x_fact[i];
            pp_new_fact[i] = pp_fact[i];
            pd_new_fact[i] = pd_fact[i];
        }
        
        for(int i = 0; (i < 2 * iFact) && (i< 2 * iVal); i++){
            xmm_new_fact[i] = new double[iWare];
            xmm_new_fact[i] = xmm_fact[i];
        }
        
        for(int i = 0 ; i < iSupp; i++) {
            delete cost_supp[i];
            delete x_sup[i];
        }
        
        for(int i = iVal; i < iFact; i++) {
            delete cost_supp[i];
            delete x_fact[i];
        }
        
        delete [] pp_fact;
        delete [] pd_fact;
        delete [] cost_supp;
        delete [] x_sup;
        delete [] cost_fact;
        delete [] x_fact;
        delete [] xmm_sup;
        delete [] xmm_fact;
        
        pp_fact = pp_new_fact;
        pd_fact = pd_new_fact;
        cost_supp = cost_new_supp;
        x_sup = x_new_sup;
        cost_fact = cost_new_fact;
        x_fact = x_new_fact;
        xmm_sup = xmm_new_sup;
        xmm_fact = xmm_new_fact;
        
        for(int i = 0; i < 2 * iSupp; i++){
            delete [] xmm_sup[i];
        }
        for(int i = 2 * iVal; i < 2 * iFact; i++){
            delete[] xmm_fact[i];
        }
        
        iFact = iVal;
        return true;
    }
}

bool CMscnProblem::bSetWare(int iVal)
{
    if(iVal < 0) {
        cout << "Incorrect Value!" <<endl;
        return false;
    }
    else if(iVal == iWare){
        cout << "Nothing Changed!" <<endl;
        return false;
    }
    else {
        double* pp_new_ware = new double[iVal];
        double* pd_new_ware = new double[iVal];
        double** cost_new_ware = new double*[iVal];
        double** cost_new_fact = new double*[iFact];
        double** x_new_ware = new double*[iVal];
        double** x_new_fact = new double*[iFact];
        double** xmm_new_ware = new double*[2 * iVal];
        double** xmm_new_fact = new double*[2 * iFact];
        
        for(int i = 0; i < iFact; i++){
            cost_new_fact[i] = new double[iVal];
            x_new_fact[i] = new double[iVal];
        }
        for(int i = 0; i < 2 * iFact; i++) {
            xmm_new_fact[i] = new double[iVal];
        }
        
        for(int i = 0 ; i < iFact; i++) {
            for(int j = 0; j < iVal; j++) {
                cost_new_fact[i][j] = cost_fact[i][j];
                x_new_fact[i][j] = x_fact[i][j];
            }
        }
        
        for(int i = 0 ; i < 2 * iFact; i++) {
            for(int j = 0; (j < 2 * iVal) && (j < 2 * iWare); j++) {
                xmm_new_fact[i][j] = xmm_fact[i][j];
            }
        }
        
        for(int i = 0; (i < iVal) && (i < iWare); i++){
            pp_new_ware[i] = pp_ware[i];
            pd_new_ware[i] = pd_ware[i];
            cost_new_ware[i] = cost_ware[i];
            x_new_ware[i] = x_ware[i];
        }
        for(int i = 0; (i < 2 * iVal) && (i < 2 * iWare); i++) {
            xmm_new_ware[i] = xmm_ware[i];
        }
        
        if(iWare < iVal){
            for(int i = iWare; i < iVal; i++){
                cost_new_fact[i] = new double[iShop];
                x_new_ware[i] = new double[iShop];
            }
            for(int i = iWare; i< 2 * iVal; i++){
                xmm_new_ware[i] = new double[iShop];
            }
        }
        
        for(int i = 0 ; i < iFact; i++) {
            delete cost_fact[i];
            delete x_fact[i];
        }
        
        for(int i = iVal; i < iWare; i++) {
            delete cost_fact[i];
            delete x_ware[i];
        }
        

        delete [] pp_ware;
        delete [] pd_ware;
        delete [] cost_fact;
        delete [] x_fact;
        delete [] cost_ware;
        delete [] x_ware;
        delete [] xmm_fact;
        delete [] xmm_ware;
        
        pp_ware = pp_new_ware;
        pd_ware = pd_new_ware;
        cost_fact = cost_new_fact;
        x_fact = x_new_fact;
        cost_ware = cost_new_ware;
        x_ware = x_new_ware;
        xmm_fact = xmm_new_fact;
        xmm_ware = xmm_new_ware;
        
        for(int i = 0; i < iFact; i++) {
            delete xmm_ware[i];
        }
        for(int i = 2 * iVal; i < 2 * iWare; i++){
            delete xmm_ware[i];
        }
        
        iWare = iVal;
        return true;
    }
}

bool CMscnProblem::bSetShop(int iVal)
{
    if(iVal < 0) {
        cout << "Incorrect Value!" <<endl;
        return false;
    }
    else if(iVal == iShop){
        cout << "Nothing Changed!" <<endl;
        return false;
    }
    else {
        double* pp_new_shop = new double[iVal];
        double* price_new_shop = new double[iVal];
        double** cost_new_ware = new double*[iWare];
        double** x_new_ware = new double*[iWare];
        double** xmm_new_ware = new double*[2 * iWare];
        
        for(int i = 0; i < iWare; i++) {
            cost_new_ware[i] = new double[iVal];
            x_new_ware[i] = new double[iVal];
        }
        
        for(int i = 0; i < 2 * iWare; i++){
            xmm_new_ware[i] = new double[iVal];
        }
        
        for(int i = 0; i < iWare; i++){
            for(int j = 0 ; j < iVal; i++){
                cost_new_ware[i][j] = cost_ware[i][j];
                x_new_ware[i][j] = x_ware[i][j];
            }
        }
        
        for(int i = 0; i < 2 * iWare; i++){
            for(int j = 0 ; j < iVal; i++){
                xmm_new_ware[i][j] = xmm_ware[i][j];
            }
        }
        
        for(int i = 0 ; i < iVal; i++) {
            pp_new_shop[i] = pp_shop[i];
            price_new_shop[i] = price_shop[i];
        }
        
        for(int i = 0; i < iWare; i++) {
            delete cost_ware[i];
            delete x_ware[i];
        }
        
        for(int i = 0 ; i < 2 * iWare; i++){
            delete [] xmm_ware[i];
        }
        
        delete [] pp_shop;
        delete [] price_shop;
        delete [] cost_ware;
        delete [] x_ware;
        delete [] xmm_ware;
        
        pp_shop = pp_new_shop;
        price_shop = price_new_shop;
        cost_ware = cost_new_ware;
        x_ware = x_new_ware;
        xmm_ware = xmm_new_ware;
        
        iShop = iVal;
        return true;
    }
}

bool CMscnProblem::bSetCostSupp(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= iSupp || iColumn < 0 || iColumn >= iFact){
        cout << "Incorrect index!" << endl;
        return false;
    }
    cost_supp[iRow][iColumn] = dVal;
    return true;
}

bool CMscnProblem::bSetCostFact(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= iFact || iColumn < 0 || iColumn >= iWare){
        cout << "Incorrect index!" << endl;
        return false;
    }
    cost_fact[iRow][iColumn] = dVal;
    return true;
}

bool CMscnProblem::bSetCostWare(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= iWare || iColumn < 0 || iColumn >= iShop){
        cout << "Incorrect index!" << endl;
        return false;
    }
    cost_supp[iRow][iColumn] = dVal;
    return true;
}

bool CMscnProblem::bSetPpSupp(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iSupp) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pp_supp[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPpFact(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iFact) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pp_fact[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPpWare(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iWare) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pp_ware[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPpShop(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iShop) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pp_shop[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPdSupp(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iSupp) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pd_supp[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPdFact(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iFact) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pd_fact[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPdWare(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iWare) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    pd_ware[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetPriceShop(int iIndex, double dVal)
{
    if(iIndex < 0 || iIndex >= iShop) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    price_shop[iIndex] = dVal;
    return true;
}

bool CMscnProblem::bSetXmmSupp(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= 2 * iSupp || iColumn < 0 || iColumn >= iFact) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    xmm_sup[iRow][iColumn] = dVal;
    return true;
}

bool CMscnProblem::bSetXmmFact(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= 2 * iFact || iColumn < 0 || iColumn >= iWare) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    xmm_fact[iRow][iColumn] = dVal;
    return true;
}

bool CMscnProblem::bSetXmmWare(int iRow, int iColumn, double dVal)
{
    if(iRow < 0 || iRow >= 2 * iWare || iColumn < 0 || iColumn >= iShop) {
        cout << "Incorrect index!" << endl;
        return false;
    }
    xmm_ware[iRow][iColumn] = dVal;
    return true;
}

double CMscnProblem::dGetMax(int iId, bool &bIsSuccess)
{
    if(iId >= iSupp * iFact) {
        iId -= iSupp * iFact;
    }
    else {
        bIsSuccess = true;
        return xmm_sup[1 + 2 *(iId / iFact)][iId%iFact];
    }
    
    if(iId >= iFact * iWare) {
        iId -= iFact * iWare;
    }
    else {
        bIsSuccess = true;
        return xmm_fact[1 + 2 * (iId / iWare)][iId % iWare];
    }
    
    if(iId >= iWare * iShop) {
        iId -= iWare * iShop;
    }
    else {
        bIsSuccess = true;
        return xmm_ware[1 + 2 * (iId / iShop)][iId % iShop];
    }
    
    bIsSuccess = false;
    return -1;
}

double CMscnProblem::dGetMin(int iId, bool &bIsSuccess)
{
    if(iId >= iSupp * iFact) {
        iId -= iSupp * iFact;
    }
    else {
        bIsSuccess = true;
        return xmm_sup[2 *(iId / iFact)][iId%iFact];
    }
    
    if(iId >= iFact * iWare) {
        iId -= iFact * iWare;
    }
    else {
        bIsSuccess = true;
        return xmm_fact[2 * (iId / iWare)][iId % iWare];
    }
    
    if(iId >= iWare * iShop) {
        iId -= iWare * iShop;
    }
    else {
        bIsSuccess = true;
        return xmm_ware[2 * (iId / iShop)][iId % iShop];
    }
    
    bIsSuccess = false;
    return -1;
}

double CMscnProblem::dCalculateTransportCost()
{
    double d_sum = 0;
    
    for(int i = 0; i < iSupp; i++) {
        for(int j = 0; i < iFact; i++) {
            d_sum += cost_supp[i][j] * x_sup[i][j];
        }
    }
    
    for(int i = 0; i < iFact; i++) {
        for(int j = 0; i < iWare; i++) {
            d_sum += cost_fact[i][j] * x_fact[i][j];
        }
    }
    
    for(int i = 0; i < iWare; i++) {
        for(int j = 0; i < iShop; i++) {
            d_sum += cost_ware[i][j] * x_ware[i][j];
        }
    }
    
    return d_sum;
}

double CMscnProblem::dCalculateContractCost()
{
    double d_sum = 0;
    
    for(int i = 0; i < iSupp; i++) {
        double d_count_element = 0;
        for(int j = 0; j < iFact; i++) {
            d_count_element += x_sup[i][j];
        }
        d_sum += pp_supp[i] * d_count_element;
    }
    for(int i = 0; i < iFact; i++) {
        double d_count_element = 0;
        for(int j = 0; j < iWare; i++) {
            d_count_element += x_fact[i][j];
        }
        d_sum += pp_fact[i] * d_count_element;
    }
    for(int i = 0; i < iWare; i++) {
        double d_count_element = 0;
        for(int j = 0; j < iShop; i++) {
            d_count_element += x_ware[i][j];
        }
        d_sum += pp_ware[i] * d_count_element;
    }
    
    return d_sum;
}

double CMscnProblem::dCalculateIncome() {
    double d_sum = 0;
    
    for(int i = 0; i < iWare; i++) {
        for(int j = 0; j < iShop; i++) {
            d_sum += price_shop[i] * x_sup[i][j];
        }
    }
    return d_sum;
}

double CMscnProblem::dCalculateProfit() {
    return dCalculateIncome() - dCalculateTransportCost() - dCalculateContractCost();
}


double CMscnProblem::dGetQuality(double *pdSolution, bool &bIsSuccess)
{
    bIsSuccess = true;
    
    if(pdSolution == NULL) {
        bIsSuccess = false;
    }
        int count = 0;
        iSupp = pdSolution[count++];
        iFact = pdSolution[count++];
        iWare = pdSolution[count++];
        iShop = pdSolution[count++];
        
        

        for(int i=0; i < iSupp; i++) {
            for(int j = 0; j < iFact; j++) {
                if(pdSolution[count] >= 0) {
                    x_sup[i][j] = pdSolution[count];
                    count++;
                }
                else {
                    bIsSuccess = false;
                    i = iSupp; j = iWare;
                }
            }
        }
        
        for(int i=0; i < iFact; i++) {
            for(int j = 0; j < iWare; j++) {
                if(pdSolution[count] >= 0) {
                    x_fact[i][j] = pdSolution[count];
                    count++;
                }
                else {
                    bIsSuccess = false;
                    i = iFact; j = iWare;
                }
            }
        }
        
        for(int i=0; i < iWare; i++) {
            for(int j = 0; j < iShop; j++) {
                if(pdSolution[count] >= 0) {
                    x_ware[i][j] = pdSolution[count];
                    count++;
                }
                else {
                    bIsSuccess = false;
                    i = iWare; j = iShop;
                }
            }
        }
    return dCalculateIncome();
}

bool CMscnProblem::bConstraintSatisfied(double *pdSolution, bool &bIsSuccess)
{
    
    bIsSuccess = true;
    
    if (pdSolution == NULL) {
        bIsSuccess = false;
        return bIsSuccess;
    }
    
    int count = 0;
    iSupp = pdSolution[count++];
    iFact = pdSolution[count++];
    iWare = pdSolution[count++];
    iShop = pdSolution[count++];
    
    
    double d_sum_xsupp = 0;
    double d_sum_xfact = 0;
    double d_sum_xware = 0;
    
    for(int i = 0; i < iSupp; i++) {
        for(int j = 0; j < iFact; i++) {
            if(pdSolution[count] >= 0) {
                d_sum_xsupp += pdSolution[count];
                count++;
            }
            else {
                bIsSuccess = false;
                return bIsSuccess;
            }
        }
    }
    
    for(int i = 0; i < iFact; i++) {
        for(int j = 0; j < iWare; i++) {
            if(pdSolution[count] >= 0) {
                d_sum_xfact += pdSolution[count];
                count++;
            }
            else {
                bIsSuccess = false;
                return bIsSuccess;
            }
        }
    }
    
    for(int i = 0; i < iWare; i++) {
        for(int j = 0; j < iShop; i++) {
            if(pdSolution[count] >= 0) {
                d_sum_xware += pdSolution[count];
                count++;
            }
            else {
                bIsSuccess = false;
                return bIsSuccess;
            }
        }
    }
    
    if(d_sum_xsupp < d_sum_xfact || d_sum_xfact < d_sum_xware) {
        bIsSuccess = false;
        return bIsSuccess;
    }
    
    count = 4;
    for(int i = 0; i < 2 * iSupp; i++) {
        for(int j = 0; j < iFact; j++) {
            if(pdSolution[count] < xmm_sup[i][j] || pdSolution[count] > xmm_sup[i+1][j]) {
                bIsSuccess = false;
                return bIsSuccess;
            }
            count++;
        }
    }
    
    for(int i = 0; i < 2 * iFact; i++) {
        for(int j = 0; j < iWare; j++) {
            if(pdSolution[count] < xmm_fact[i][j] || pdSolution[count] > xmm_fact[i+1][j]) {
                bIsSuccess = false;
                return bIsSuccess;
            }
            count++;
        }
    }

    
    for(int i = 0; i < 2 * iWare; i++) {
        for(int j = 0; j < iShop; j++) {
            if(pdSolution[count] < xmm_ware[i][j] || pdSolution[count] > xmm_ware[i+1][j]) {
                bIsSuccess = false;
                return bIsSuccess;
            }
            count++;
        }
    }

    return bIsSuccess;
    
}



/*
https://github.com/zaxoavoki/pwr/blob/2f6c8c42ab4fe05165ba7ffac438ed50e9a2f023/TEP/Lab_9/CMscnProblem.cpp
https://github.com/zaxoavoki/pwr/blob/2f6c8c42ab4fe05165ba7ffac438ed50e9a2f023/TEP/Lab_9/CMscnProblem.h
https://github.com/AltiTorie/Tep_9/blob/master/Solution/Solution/CMscnProblem.cpp
https://github.com/kamilagalka/TEP9/blob/e0e358906bf3b2ef4e14029597d66074eefff7df/lista9/CMscnProblem.cpp
 */
