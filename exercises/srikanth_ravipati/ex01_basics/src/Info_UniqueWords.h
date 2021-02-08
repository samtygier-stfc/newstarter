#include <iostream>
#include <vector>

class Info_UniqueWords{

    // Data Members
    int Size;
    std::vector<std::string> Element;
    std::vector<int>    Count;

    // Declaration of member functions
    public: // Access specifier
    
    Info_UniqueWords();
    ~Info_UniqueWords();
    int GetSize(void);
    std::string GetElementValue(int);
    int GetElementIdx(std::string);
    int GetElementCount(std::string);
    void IncrElementCount(std::string);
    void AppendElement(std::string);
    void AccountForElement(std::string);
    void Print(void);


};