//
//  TFile.cpp
//  ProjectN10
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "TList.hpp"
#include <iostream>

template <class T>
TListSystem::TList<T>::TList()
{
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
    m_size = 0;
}

template <class T>
TListSystem::TList<T>::TList(const TList &list)
{
    firstNode = nullptr;
    lastNode  = nullptr;
    selectedNode = nullptr;
    m_size = 0;

    this->firstNode = list.firstNode;
    this->lastNode = list.lastNode;
    this->selectedNode = list.selectedNode;
    m_size = list.m_size;
}

template <class T>
TListSystem::TList<T>::~TList()
{
    delete firstNode;
    delete lastNode;

    firstNode = nullptr;
    lastNode  = nullptr;

    selectedNode = nullptr;
    delete selectedNode;

}

template <class T>
unsigned int TListSystem::TList<T>::Size()
{
    return m_size;
}

template <class T>
unsigned int TListSystem::TList<T>::Push(T psz)
{
    TNode *node;
    node = TListSystem::TList<T>::Node();
    node->tlistData = psz;
    
    if(!lastNode)
    {
        firstNode = node;
        lastNode = node;
    }
    else
    {
        lastNode->nextNode = node;
        node->previousNode = lastNode;
        lastNode = node;
    }
    
    if (!selectedNode)
    {
        selectedNode = firstNode;
    }
    
    m_size++;
    
    return m_size;
}

template <class T>
const T TListSystem::TList<T>::First()
{
    selectedNode = firstNode;
    return firstNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Last()
{
    selectedNode = lastNode;
    return lastNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Next()
{
    if (selectedNode != lastNode)
    {
        selectedNode = selectedNode->nextNode;
    }
    return selectedNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Previous()
{
    if (selectedNode != firstNode)
    {
        selectedNode = selectedNode->previousNode;
    }
    return selectedNode->tlistData;
}

template <class T>
const T TListSystem::TList<T>::Pop()
{
    if (m_size == 0)
    {
        firstNode = nullptr;
        lastNode  = nullptr;
        selectedNode = nullptr;
    }
    else if (m_size == 1)
    {
        firstNode = nullptr;
        lastNode  = nullptr;
        selectedNode = nullptr;
        m_size --;
    }
    else
    {
        lastNode = lastNode->previousNode;
        m_size --;
    }
    
    if (!lastNode)
    {
        return 0;
    }
    else
    {
        return lastNode->tlistData;
    }
}

template <class T>
void TListSystem::TList<T>::Reset()
{
    for (int i = m_size; i > 0; i --)
    {
        Pop();
    }
}

template <class T>
TListSystem::TList<T> TListSystem::TList<T>::GetReverseList(TList lstSrc)
{
    TListSystem::TList<int> list;
    lstSrc.Last();
    for (int i = lstSrc.Size(); i > 0; i--)
    {
        list.Push(lstSrc.selectedNode->tlistData);
        lstSrc.Previous();
    }

    return list;
}
