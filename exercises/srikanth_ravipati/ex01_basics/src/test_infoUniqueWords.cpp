#include <iostream>
#include <assert.h>
#include "infoUniqueWords.h"

int main(){
    infoUniqueWords uniqueWords;
    uniqueWords.appendElement("Test");

    assert (uniqueWords.getSize() == 1);
    assert (uniqueWords.getElementValue(0) == "Test");
    assert (uniqueWords.getElementIdx("Test") == 0);
    assert (uniqueWords.getElementCount("Test") == 1);
    assert (uniqueWords.getElementIdx("Random") == -1);

    uniqueWords.accountForElement("Test");
    assert (uniqueWords.getElementCount("Test") == 2);

    return 0;
}