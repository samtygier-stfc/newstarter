#include <assert.h>
#include "processLine.h"

int main(){
    string delimiters = "'\".,?!():}";
    infoUniqueWords uniqueWords;

    string x = "Hello, World. I am a new-born(child)";

    processLine(x, delimiters, uniqueWords);

    assert (uniqueWords.getElementValue(0) == "hello");
    assert (uniqueWords.getElementCount("hello") == 1);
    assert (uniqueWords.getElementValue(1) == " world");
    assert (uniqueWords.getElementCount(" world") == 1);
    assert (uniqueWords.getElementValue(2) == " i am a new-born");
    assert (uniqueWords.getElementCount(" i am a new-born") == 1);
    assert (uniqueWords.getElementValue(3) == "child");
    assert (uniqueWords.getElementCount("child") == 1);

    return 0;
}