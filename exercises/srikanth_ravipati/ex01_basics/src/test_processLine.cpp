#include <assert.h>
#include "processLine.h"

int main(){
    std::string delimiters = "'\".,?!(): -}";
    infoUniqueWords uniqueWords;

    std::string x = "Hello, World. I am a new-born(child)";

    processLine(x, delimiters, uniqueWords);

    assert (uniqueWords.getElementValue(0) == "hello");
    assert (uniqueWords.getElementCount("hello") == 1);
    assert (uniqueWords.getElementValue(1) == "world");
    assert (uniqueWords.getElementCount("world") == 1);
    assert (uniqueWords.getElementValue(2) == "born");
    assert (uniqueWords.getElementCount("born") == 1);
    assert (uniqueWords.getElementValue(3) == "child");
    assert (uniqueWords.getElementCount("child") == 1);

    return 0;
}