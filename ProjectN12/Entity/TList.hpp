//
//  TFile.hpp
//  ProjectN10
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifndef TFile_hpp
#define TFile_hpp

#include <stdio.h>

namespace TListSystem
{
    template <class T>
    class TList
    {
        
    public:
        TList();
        TList(const TList &list);
        ~TList();
        
        unsigned int Size();
        unsigned int Push(T psz);
        static TList GetReverseList(TList lstSrc);
        
        const T First();
        const T Last();
        const T Next();
        const T Previous();
        const T Pop();
        
        void Reset();
        
    private:
        unsigned int m_size;
        class TNode
        {
        public:
            T tlistData;
            TNode *nextNode, *previousNode;
        } *firstNode, *lastNode, *selectedNode;
        
        void InitNodes();
        void DeleteNodes();
    };
}

#include "TList.tpp"
#endif /* TFile_hpp */
