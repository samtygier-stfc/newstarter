/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include "processLine.h"

int main(int argc, char** argv)
{
    if (argc < 2){
       std::cout << "Atleast one argument (filename) should be passed." << "\n";
       return 1;
    } else {
    std::cout << "File to be processed: "  << argv[1] << "\n";
    }

    return 0;
}
