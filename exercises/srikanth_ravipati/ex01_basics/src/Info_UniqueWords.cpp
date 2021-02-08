#include <iostream>
#include <vector>
#include "Info_UniqueWords.h"

infoUniqueWords :: infoUniqueWords(){
    size = 0;
    element;
    count;
}

infoUniqueWords :: ~infoUniqueWords(){
    size = 0;
    element.clear();
    element.shrink_to_fit();
    count.clear();
    count.shrink_to_fit();
}

int infoUniqueWords :: getSize(){
    return size;
}

std::string infoUniqueWords :: getElementValue(int idx){
    return element[idx];
}

int infoUniqueWords :: getElementIdx(std::string inputElement){
   int idx = -1;
   for (int i=0; i < size; i++){
       if (element[i] == inputElement){
          idx = i;
          break;
       }
   }
   return idx;
}

int infoUniqueWords :: getElementCount(std::string inputElement){
    return count[getElementIdx(inputElement)];
}

int infoUniqueWords :: getElementCount(int idx){
    return count[idx];
}

void infoUniqueWords :: incrElementCount(int idx){
    count[idx] += 1;
}

void infoUniqueWords :: appendElement(std::string newElement){
    size += 1;
    element.push_back(newElement);
    count.push_back(1);
}

void infoUniqueWords :: accountForElement(std::string inputElement){
    int idx = getElementIdx(inputElement);
    if (idx == -1){
       appendElement(inputElement);
    } else{
       incrElementCount(idx);
   }
}

void infoUniqueWords :: print(){
    std::cout << "size " << "\t" << size << "\n";
    for (int i=0; i < size; i++){
        std::cout << "word: " << element[i] << "\t" << "count: " << count[i] << "\n";
    }
}