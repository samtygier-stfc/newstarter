#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Info_UniqueWords.h"

int main(){
    Info_UniqueWords UniqueWords;
    UniqueWords.AppendElement("Test");

    assert (UniqueWords.GetSize() == 1);
    assert (UniqueWords.GetElementValue(0) == "Test");
    assert (UniqueWords.GetElementIdx("Test") == 0);
    assert (UniqueWords.GetElementCount("Test") == 1);
    assert (UniqueWords.GetElementIdx("Random") == -1);


    return 0;
}