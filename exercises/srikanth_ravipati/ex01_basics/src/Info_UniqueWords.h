#include <iostream>
#include <vector>

class infoUniqueWords{

    // Data Members
    int size;
    std::vector<std::string> element;
    std::vector<int>    count;

    // Declaration of member functions
    public: // Access specifier
    
    infoUniqueWords();
    ~infoUniqueWords();
    int getSize(void);
    std::string getElementValue(int);
    int getElementIdx(std::string);
    int getElementCount(std::string);
    void incrElementCount(std::string);
    void appendElement(std::string);
    void accountForElement(std::string);
    void print(void);


};