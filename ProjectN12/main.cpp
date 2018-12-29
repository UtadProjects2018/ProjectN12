//
//  main.cpp
//  ProjectN10
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>

#include "FileUtils.h"
#include "StringUtils.h"

int main(int argc, const char * argv[])
{
    TListSystem::TList<int> *numberList = new TListSystem::TList<int>();
    numberList->Push(10);
    numberList->Push(20);
    numberList->Push(30);
    numberList->Push(40);
    numberList->Push(50);
    
    TListSystem::TList<int> reverseNumbersList = TListSystem::TList<int>::GetReverseList(*numberList);
    for (int i = 0; i < reverseNumbersList.Size() ; i++)
    {
        printf("TList int Value %d\n", i == 0 ? reverseNumbersList.First() : reverseNumbersList.Next());
    }
    
    printf("============================\n");
    
    TListSystem::TList<std::string> *stringList = new TListSystem::TList<std::string>();
    stringList->Push("10");
    stringList->Push("20");
    stringList->Push("30");
    stringList->Push("40");
    stringList->Push("50");
    
    TListSystem::TList<std::string> reverseStringList = TListSystem::TList<std::string>::GetReverseList(*stringList);
    for (int i = 0; i < reverseStringList.Size(); i ++)
    {
        printf("TList string Value %s\n", i == 0 ? reverseStringList.First().c_str() : reverseStringList.Next().c_str());
    }
    
    printf("============================\n");
    
    TListSystem::TList<int> *numberSecondList = new TListSystem::TList<int>();
    numberSecondList->Push(10);
    numberSecondList->Push(20);
    numberSecondList->Push(30);
    numberSecondList->Push(40);
    numberSecondList->Push(50);
    
    TListSystem::TList<int> betterReverseNumbersList = TListSystem::TList<int>::GetBetterReverseList(*numberList);
    for (int i = 0; i < betterReverseNumbersList.Size() ; i++)
    {
        printf("TList int Value %d\n", i == 0 ? betterReverseNumbersList.First() : betterReverseNumbersList.Next());
    }
    
    return 0;
}
