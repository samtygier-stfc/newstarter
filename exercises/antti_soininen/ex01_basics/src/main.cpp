#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

bool is_punctuation(char c)
{
    const static std::array<char, 9> punctuation{
        '.', ',', '?', '\'', '\"', '!', '(', ')', ':'
    };
    return std::any_of(punctuation.begin(), punctuation.end(), [c](char p) {
        return p == c;
    });
}

int main(int argc, char **argv)
{
    std::ifstream in(argv[1]);
    std::map<std::string, unsigned> wordCount;
    std::string w;
    while(!in.eof()) {
        char c;
        in.get(c);
        c = std::tolower(c);
        if(!std::isspace(c) && !is_punctuation(c)) {
            w.push_back(c);
        }
        else {
            if(w.size() > 4) ++wordCount[w];
            w.clear();
        }
    }
    using countPair = std::pair<const std::string*, unsigned>;
    std::vector<countPair> resorted;
    for(const auto& item : wordCount) {
        resorted.push_back(countPair(&item.first, item.second));
    }
    std::sort(resorted.begin(), resorted.end(), [](const countPair& lhs, const countPair& rhs) {
        return lhs.second > rhs.second;
    });
    for(const auto& item : resorted) {
        std::cout << *item.first << " " << item.second << std::endl;
    }
    return EXIT_SUCCESS;
}
