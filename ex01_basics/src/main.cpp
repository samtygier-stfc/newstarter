#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

int main(int argc, char* argv[])
{
    // check if there was exactly one input parameter
    if (argc != 2)
    {
        std::cerr << "Provide name for one file" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);

    // check if text file is open
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, unsigned int> wordcount;
    std::string word;

    while (inputFile >> word)
    {

        // transform everything to lower case
        transform(word.begin(), word.end(), word.begin(), tolower);

        // remove special characters
        auto isSpecialCharacter{ [](char c)
            {
                if (c == '.' || c == ',' || c == '?' || c == '\'' || c == '\"' || c == '!' || c == '(' || c == ')' || c == ':')
                    return true;
                else
                    return false;
        } };
        word.erase(std::remove_if(word.begin(), word.end(), isSpecialCharacter), word.end());
        //@TODO with C++ 20 use erase_if instead of erase and remove_if

        // split if one or more hyphen found
        auto pos = word.find("-");
        if (pos != std::string::npos)
        {
            auto beforeHyphen = word.substr(0, pos - 1);
            auto afterHyphen = word.substr(word.find_last_of("-") + 1);

            // only count if longer than 4 characters
            if (beforeHyphen.length() > 4) ++wordcount[beforeHyphen];

            // only count if longer than 4 characters
            if (afterHyphen.length() > 4) ++wordcount[afterHyphen];
        }
        else
        {
            // only count if longer than 4 characters
            if (word.length() > 4) ++wordcount[word];
        }
    }
    inputFile.close();

    // sort in descending order of usage
    std::vector<std::pair<std::string, int>> sortedWordcount{ std::make_move_iterator(begin(wordcount)), std::make_move_iterator(end(wordcount)) };
    sort(begin(sortedWordcount), end(sortedWordcount), [](auto w1, auto w2) {return w1.second > w2.second; });

    // output word count
    std::cout << std::setw(30) << std::left << "Word " << "Usage" << std::endl;
    for (auto it = sortedWordcount.begin(); it != sortedWordcount.end(); ++it)
        std::cout << std::setw(30) << std::left << it->first << " " << it->second << std::endl;
}