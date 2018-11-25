//
//  StringUtils.cpp
//  ProjectN6
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include "StringUtils.h"
#include "FileUtils.h"

#include <iostream>
#include <numeric>

std::vector<int> GetNumbersFromFile(const char fileName[])
{
    std::vector<int> numbers;
    
    int length = FileSystemStringUtils::CharacterLength(fileName);
    char *pCharacter = new char[length + 1];
    
    FileSystemUtils::FileOperationRead(fileName, pCharacter, length);
    
    pCharacter[length + 1] = '\0';
    
    const char *pIni = pCharacter;
    char *pFound = strstr(pCharacter, ",");
    while (pFound)
    {
        *pFound = '\0';
        numbers.push_back(atoi(pIni));
        pFound++;
        pIni = pFound;
        pFound = strstr(pFound, ",");
    }
    
    //get the last character
    numbers.push_back(atoi(pIni));
    
    return numbers;
}

int FileSystemStringUtils::GetNumberRepeatString(const char fileName[], const char searchChar[])
{
    int numberOfCharacterFound = 0;
    
    int length = FileSystemStringUtils::CharacterLength(fileName);
    char *pCharacter = new char[length];
    
    FileSystemUtils::FileOperationRead(fileName, pCharacter, length);

    if (pCharacter != nullptr)
    {
        const char *pFound = strstr(pCharacter, searchChar);
        while (pFound)
        {
            numberOfCharacterFound++;
            pFound++;
            pFound = strstr(pFound, searchChar);
        }
    }
    
    delete [] pCharacter;
    
    return numberOfCharacterFound;
}

int FileSystemStringUtils::CharacterLength(const char fileName[])
{
    int length = 0;
    FileSystem::FileObject fileID = FileSystem::OpenFile(fileName, FileSystem::FileTypeRead);
    char character = '\0';
    while (character != EOF)
    {
        character = (char)fgetc(FileSystemUtils::GetFileObject(fileID));
        length++;
    }
    FileSystem::CloseFile(fileID);
    return length;
}

int FileSystemStringUtils::SumNumberFromFile(const char fileName[])
{
    std::vector<int> elements = GetNumbersFromFile(fileName);
    int result = std::accumulate(elements.begin(), elements.end(), 0);
    
    return result;
}

TListSystem::TList<int> FileSystemStringUtils::LoadListFromFile(const char fileName[])
{
    TListSystem::TList<int> list;
    std::vector<int> numbers = GetNumbersFromFile(fileName);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        list.Push(numbers[i]);
    }
    
    return list;
}
