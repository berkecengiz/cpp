//
//  CRefCounter.hpp
//  lab7
//

#ifndef CRefCounter_h
#define CRefCounter_h

#include <stdio.h>

class CRefCounter
{
public:
    
    CRefCounter();
    int iAdd();
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
    int iGetMax() { return max_count; };
    
private:
    
    int i_count;
    int max_count;
    void check_max();
};

#endif /* CRefCounter_h */
