#include "utils.h"
#include <assert.h>

int main(){
    std::string delimiters = "'\".,?!():}";

    std::string str1 = "test";
    std::string str2 = "H";
    appendLowerCaseChar(str1, str2[0]);

    str2 = "'";
    assert(isInputCharDelimiter(str2[0], delimiters) == true);

    // Space and hyphen are not considered as delimiters
    str2 = "";
    assert(isInputCharDelimiter(str2[0], delimiters) == false);

    str2 = "-";
    assert(isInputCharDelimiter(str2[0], delimiters) == false);

    return 0;
}