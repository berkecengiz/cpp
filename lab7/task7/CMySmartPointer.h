//
//  CMySmartPointer.h
//  lab7
//

#ifndef CMySmartPointer_h
#define CMySmartPointer_h

#include "CRefCounter.h"
#include <iostream>

using namespace std;

template <typename T> class CMySmartPointer
{
public:
    
    CMySmartPointer(T *pcPointer)
    {
        //cout << "Constructor\n";
        pc_pointer = pcPointer;
        pc_counter = new(CRefCounter);
        pc_counter->iAdd();
    }
    
    CMySmartPointer(const CMySmartPointer &pcOther)
    {
        //cout << "Copy Constructor\n";
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }
    
    ~CMySmartPointer()
    {
        //cout << "Destructor\n";
        if ((pc_counter->iDec()) == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
    }
    
    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }
    
    CMySmartPointer& operator=(const CMySmartPointer* copy);

private:
    
    CRefCounter *pc_counter;
    T *pc_pointer;
};

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer *copy)
{
    if(!(this == copy && this->pc_pointer == copy->pc_pointer)) {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
        this->pc_counter = copy->pc_counter;
        this->pc_pointer = copy->pc_pointer;
        this->pc_counter->iAdd();
    }
    return *this;
}

#endif /* CMySmartPointer_h */
