#include <iostream>
#include <string>
#include <vector>
#include "Info_UniqueWords.h"

using namespace std;

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

string Info_UniqueWords :: GetElementValue(int Idx){
    return Element[Idx];
}

int Info_UniqueWords :: GetElementIdx(string InputElement){
   int Idx = -1;
   for (int i=0; i < Size; i++){
       if (Element[i] == InputElement){
          Idx = i;
          break;
       }
   }
   return Idx;
}

int Info_UniqueWords :: GetElementCount(string InputElement){
    return Count[GetElementIdx(InputElement)];
}