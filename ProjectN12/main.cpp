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
        if (i == 0)
        {
            printf("TList Value %d\n", reverseNumbersList.First());
        }
        else
        {
            printf("TList Value %d\n", reverseNumbersList.Next());
        }
    }
    
    return 0;
}
