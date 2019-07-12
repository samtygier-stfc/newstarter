#include "main.h"

int main(int argc, char* argv[])
{
    std::string filename{};
    std::map<std::string, int> wordCounter{};
    std::vector<std::pair<int, std::string>> sorted{};
    const int correctNumberArguments{ 2 };

    // checks that the user has provided only one filename
    if (argc != correctNumberArguments) {
        std::cerr << "Wrong number of arguments provided. "
            "Provide only one filename.";
        return 0;
    }
    else {
        filename = argv[1];
    }

    countWords(filename, wordCounter);

    sorted = orderByUsage(wordCounter);

    writeToFile(sorted);

    return 0;
}

// opens file with the provided filename
// populates a map with each word in the file
// and the number of occurences
void countWords(std::string filename,
    std::map<std::string, int>& wordCounter) {

    std::ifstream file{ filename };

    // checks the file has been opened
    if (!file.is_open()) {
        std::cerr << "Unable to open file.";
        return;
    }

    // goes through each word in the file
    std::string word;
    while (file >> word) {
        const int minWordLength{ 5 };

        word = cleanUpWord(word);

        // only words of length at least 5 are added to the map
        if (word.length() >= minWordLength) {
            ++wordCounter[word];
        }
    }

    file.close();
}

// given a word, removes punctuation and converts to lowercase
// returns the changed word
std::string cleanUpWord(std::string word) {
    std::string newWord{};
    std::string punctuation{ ".,?'\"!():" };

    // iterates through each character in the word
    for (char c : word) {
        // increase uppercase ascii value by 32 to make it lowercase
        const int upperToLower{ 32 };

        // if the character is uppercase, it is converted to lowercase
        if (c >= 'A' && c <= 'Z') {
            c += upperToLower;
        }
        // punctuation characters are discarded
        else if (punctuation.find(c) != std::string::npos) {
            continue;
        }

        newWord += c;
    }

    return newWord;
}

// converts the map to a vector of pairs so it can be sorted
std::vector<std::pair<int, std::string>>
orderByUsage(std::map<std::string, int>& wordCounter) {

    std::vector<std::pair<int, std::string>> pairs{};

    // each word-usage pair in the map is added to the vector
    // as a usage-word pair (swapped for easy sorting)
    for (auto word : wordCounter) {
        std::pair<int, std::string> pair;
        pair.second = word.first;
        pair.first = word.second;

        pairs.push_back(pair);
    }

    // sorted in descending order of word usage
    std::sort(pairs.begin(), pairs.end(),
        std::greater<std::pair<int, std::string>>());

    return pairs;
}

// writes each word-usage pair to a file
void writeToFile(std::vector<std::pair<int, std::string>> wordCounter) {
    std::ofstream outputFile{ "output.txt" };

    // checks the file has been opened
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file.";
        return;
    }

    // headings are written to the file
    outputFile << "Word\t\t\t\tUsage\n\n";

    // iterates through the vector of pairs
    for (std::pair<int, std::string> wordAndUsage : wordCounter) {
        const int paddedWordLength{ 32 };
        std::string word{ wordAndUsage.second };

        // each word is padded with spaces to make the file look neat
        word.append(paddedWordLength - word.length(), ' ');

        outputFile << word << wordAndUsage.first << "\n";
    }

    std::cout << "output.txt successfully created.";

    outputFile.close();
}