#include <iostream>
#include <assert.h>
#include "Info_UniqueWords.h"

int main(){
    infoUniqueWords uniqueWords;
    uniqueWords.appendElement("Test");

    assert (uniqueWords.getSize() == 1);
    assert (uniqueWords.getElementValue(0) == "Test");
    assert (uniqueWords.getElementIdx("Test") == 0);
    assert (uniqueWords.getElementCount("Test") == 1);
    assert (uniqueWords.getElementIdx("Random") == -1);

    uniqueWords.incrElementCount("Test");
    assert (uniqueWords.getElementCount("Test") == 2);

    return 0;
}