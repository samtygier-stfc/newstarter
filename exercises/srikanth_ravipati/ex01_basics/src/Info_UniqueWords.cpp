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