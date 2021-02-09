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
    int getElementCount(int);
    void incrElementCount(int);
    void swap(int, int);
    void reorder(int);
    void appendElement(std::string);
    void accountForElement(std::string);
    void print(void);


};