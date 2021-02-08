#include <iostream>
#include <vector>
#include "Info_UniqueWords.h"

Info_UniqueWords :: Info_UniqueWords(){
    Size = 0;
    Element;
    Count;
}

Info_UniqueWords :: ~Info_UniqueWords(){
    Size = 0;
    Element.clear();
    Element.shrink_to_fit();
    Count.clear();
    Count.shrink_to_fit();
}

int Info_UniqueWords :: GetSize(){
    return Size;
}

std::string Info_UniqueWords :: GetElementValue(int Idx){
    return Element[Idx];
}

int Info_UniqueWords :: GetElementIdx(std::string InputElement){
   int Idx = -1;
   for (int i=0; i < Size; i++){
       if (Element[i] == InputElement){
          Idx = i;
          break;
       }
   }
   return Idx;
}

int Info_UniqueWords :: GetElementCount(std::string InputElement){
    return Count[GetElementIdx(InputElement)];
}

void Info_UniqueWords :: IncrElementCount(std::string InputElement){
    Count[GetElementIdx(InputElement)] += 1;
}

void Info_UniqueWords :: AppendElement(std::string NewElement){
    Size += 1;
    Element.push_back(NewElement);
    Count.push_back(1);
}

void Info_UniqueWords :: AccountForElement(std::string InputElement){
    int Idx = GetElementIdx(InputElement);
    if (Idx == -1){
       AppendElement(InputElement);
    } else{
       IncrElementCount(InputElement);
   }
}

void Info_UniqueWords :: Print(){
    std::cout << "Size " << "\t" << Size << "\n";
    for (int i=0; i < Size; i++){
        std::cout << "Word: " << Element[i] << "\t" << "Count: " << Count[i] << "\n";
    }
}