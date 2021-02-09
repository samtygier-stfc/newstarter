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

    uniqueWords.appendElement("Second");

    assert (uniqueWords.getElementValue(1) == "Second");
    assert (uniqueWords.getElementIdx("Second") == 1);
    assert (uniqueWords.getElementCount(1) == 1);
    assert (uniqueWords.getElementCount("Second") == 1);

    uniqueWords.swap(0,1);

    assert (uniqueWords.getElementValue(1) == "Test");
    assert (uniqueWords.getElementIdx("Test") == 1);
    assert (uniqueWords.getElementCount(1) == 2);
    assert (uniqueWords.getElementCount("Test") == 2);

    assert (uniqueWords.getElementValue(0) == "Second");
    assert (uniqueWords.getElementIdx("Second") == 0);
    assert (uniqueWords.getElementCount(0) == 1);
    assert (uniqueWords.getElementCount("Second") == 1);

    return 0;
}