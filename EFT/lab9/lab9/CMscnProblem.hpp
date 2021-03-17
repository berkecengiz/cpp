//
//  CMscnProblem.hpp
//  lab9
//
//  Copyright © 2020 Berke Cengiz. All rights reserved.
//

#ifndef CMscnProblem_hpp
#define CMscnProblem_hpp

#pragma once
#include <stdio.h>


class CMscnProblem
{
public:
    CMscnProblem();
    ~CMscnProblem();
    
    bool bSetSupp(int iVal);
    bool bSetFact(int iVal);
    bool bSetWare(int iVal);
    bool bSetShop(int iVal);
    
    bool bSetCostSupp(int iRow, int iColumn, double dVal);
    bool bSetCostFact(int iRow, int iColumn, double dVal);
    bool bSetCostWare(int iRow, int iColumn, double dVal);
    
    bool bSetPpSupp(int iIndex, double dVal);
    bool bSetPpFact(int iIndex, double dVal);
    bool bSetPpWare(int iIndex, double dVal);
    bool bSetPpShop(int iIndex, double dVal);
    
    bool bSetPdSupp(int iIndex, double dVal);
    bool bSetPdFact(int iIndex, double dVal);
    bool bSetPdWare(int iIndex, double dVal);
    
    bool bSetPriceShop(int iIndex, double dVal);
    
    bool bSetXmmSupp(int iRow, int iColumn, double dVal);
    bool bSetXmmFact(int iRow, int iColumn, double dVal);
    bool bSetXmmWare(int iRow, int iColumn, double dVal);
    
    double dGetMin(int iId, bool &bIsSuccess);
    double dGetMax(int iId, bool &bIsSuccess);
    
    double dCalculateTransportCost();
    double dCalculateContractCost();
    double dCalculateIncome();
    double dCalculateProfit();
    
    double dGetQuality(double *pdSolution, bool &bIsSuccess);
    
    bool bConstraintSatisfied(double *pdSolution, bool &bIsSuccess);

private:
    int iSupp; //supplier
    int iFact; //factories
    int iWare; //warehouses
    int iShop; //shop
    
    double *pp_supp;  //productive power
    double *pp_fact;
    double *pp_ware;
    double *pp_shop;
    
    double **cost_supp;   //Price of transportation
    double **cost_fact;
    double **cost_ware;
    
    double *pd_supp;       //price of deal
    double *pd_fact;
    double *pd_ware;
    
    double *price_shop;    //income
    
    double **xmm_sup;     //min-max
    double **xmm_fact;
    double **xmm_ware;
    
    double **x_sup;  //amount of product
    double **x_fact;
    double **x_ware;
    
    
};
#endif /* CMscnProblem_hpp */
