//
//  CTreeDynamic.h
//  lab6
//
//  Created by Adriana Wilkowska on 04/12/2019.
//  Copyright © 2019 Berke Cengiz. All rights reserved.
//

#ifndef CTreeDynamic_h
#define CTreeDynamic_h

#include "CNodeDynamic.h"

template < typename T > class CTreeDynamic
{
private:
    
    CNodeDynamic<T> *pc_root;

public:
    CTreeDynamic();
    ~CTreeDynamic();
    
    CNodeDynamic<T> *pcGetRoot();
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
};//class CTreeDynamic


template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
    pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
    delete pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
    pc_root->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode)
{
        if (pcParentNode == pcNewChildNode || pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->pcGetParent() == NULL) {
            return false;
        }

        pcNewChildNode->pcGetParent()->vRemoveChild(pcNewChildNode);
        pcParentNode->vAddNewChild(pcNewChildNode);
        return true;
    }

template <typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot()
{
    return pc_root;
}


#endif /* CTreeDynamic_h */

