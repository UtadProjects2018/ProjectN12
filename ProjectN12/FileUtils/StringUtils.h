//
//  StringUtils.hpp
//  ProjectN6
//
//  Created by pc-laptop on 10/29/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#ifndef StringUtils_h
#define StringUtils_h

#include "TList.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>

namespace FileSystemStringUtils
{
    int GetNumberRepeatString(const char fileName [], const char searchChar[]);
    int CharacterLength(const char fileName[]);
    int SumNumberFromFile(const char fileName[]);
    TListSystem::TList<int> LoadListFromFile(const char fileName[]);
}
#endif /* StringUtils_h */
