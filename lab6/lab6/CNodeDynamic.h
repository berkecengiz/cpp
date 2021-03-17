//
//  CNodeDynamic.h
//  lab6
//
//  Created by Adriana Wilkowska on 05/12/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CNodeDynamic_h
#define CNodeDynamic_h

#include <vector>
#include <iostream>

using namespace std;

template < typename T > class CNodeDynamic
{
public:
    CNodeDynamic();
    ~CNodeDynamic();
    
    void vSetValue(T iNewVal) { i_val = iNewVal; };
    void vSetParent(CNodeDynamic<T>* pcNewParent) { pc_parent_node = pcNewParent; };
    
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic<T> *cNewChild);
    void vRemoveChild(CNodeDynamic<T>* cChild);
    
    CNodeDynamic *pcGetParent() { return pc_parent_node; };
    CNodeDynamic *pcGetRoot(CNodeDynamic *cNodeDynamic);
    CNodeDynamic *pcGetChild(int iChildOffset);
    
    void vPrint() { cout << " " << i_val; };
    void vPrintAllBelow();
    void vPrintUp();
    
    int iGetChildrenNumber(){ return v_children.size(); };

private:
    
    vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    T i_val;
    
};

template <typename T>
CNodeDynamic<T>::CNodeDynamic()
{
    pc_parent_node = NULL;

}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
    for(int i = 0; i < v_children.size(); i++) {
        if (v_children[i] != NULL) {
            delete v_children[i];
        }
    }
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
    CNodeDynamic<T> *cNewNode = new CNodeDynamic;
    cNewNode->pc_parent_node = this;
    v_children.push_back(cNewNode);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *cNewChild) {
    cNewChild->pc_parent_node = this;
    v_children.push_back(cNewChild);
}

template <typename T>
void CNodeDynamic<T>::vRemoveChild(CNodeDynamic<T> * cChild)
{
    for (int i = 0; i < v_children.size(); i++) {
        if (v_children[i] == cChild) {
            v_children.erase(v_children.begin() + i);
            return;
        }
    }
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetRoot(CNodeDynamic<T>* cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL)
        pcGetRoot(cNodeDynamic->pc_parent_node);

    return cNodeDynamic;
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size() && iChildOffset >= 0)
        return v_children.at(iChildOffset);

    return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

template <typename T>
void CNodeDynamic<T>::vPrintUp()
{
    vPrint();

    if (pc_parent_node != NULL) {
        pc_parent_node->vPrintUp();
    }
}



#endif /* CNodeDynamic_h */
