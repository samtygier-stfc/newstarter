#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Info_UniqueWords{

    // Data Members
    int Size;
    vector<string> Element;
    vector<int>    Count;

    // Declaration of member functions
    public: // Access specifier
    
    Info_UniqueWords();
    ~Info_UniqueWords();
    int GetSize(void);
    string GetElementValue(int);


};