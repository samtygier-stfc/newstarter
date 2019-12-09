/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(int argc, char **argv)
{
    map<string, int> word_count;

    if (argc < 2){
        cerr << "No file provided";
        return -1;
    }

    // the input file
    char *file_name = argv[1];

    string out_name;
    // Name of the file in which the output will be written
    if (argc > 2){
        // catch the second argument if one is provided
        out_name = string(argv[2]);
    } else {
        // else create a new file
        out_name = "./out.txt";
    }

    ifstream in;
    in.open(file_name);

    if (!in){
        cerr << "Error when reading the file" << endl;
        return -1;
    }

    string block;
    int max_length = 4; // size of "Word", which we systematically write
    size_t block_size;
    bool should_split;

    // the delimiters of words
    string delimiters = ".,?'\"!():";

    while (in >> block){
        // iterate on each space or endofline separated block in the text
        block_size = block.size();
        size_t start = 0;
        should_split = false;

        // iterate on each character of the block to further parse it
        for (size_t i = 0; i != block_size; ++i){
            // convert to lowercase so it is case insensitive
            block[i] = tolower(block[i]);

            // iterate on every delimiter to check if the current character is a letter
            for (int j = 0; j != delimiters.size(); j++){
                if (delimiters[j] == block[i]){
                    should_split = true;
                    break;
                }
            }
            // if the last character was invalid, we reached the end of a word
            if (should_split){
                int length_of_word = i - start;
                if (length_of_word >= 5){
                    // if long enough, the word is added to the map
                    word_count[block.substr(start, length_of_word)]++;

                    // check if it is the new longest word
                    if (length_of_word > max_length){
                        max_length = length_of_word;
                    }
                }
                should_split = false;
                start = i + 1;
            }
        }
        // if the last character was valid, the last part of the block is checked for adding
        if (!should_split){
            if (block_size - start >= 5){
                word_count[block.substr(start, block_size - start)]++;
                if (block_size - start > max_length){
                    max_length = block_size - start;
                }
            }
        }
    }
    in.close();

    // we store the elements of word_counts in a vector so they can be sorted
    vector<tuple<int, string>> vec_count;
    for (map<string, int>::iterator it = word_count.begin(); it != word_count.end(); ++it){
        vec_count.push_back(tuple<int, string>(it->second, it->first));
    }

    // sort the vector's elements in increasing order, by the first value of the tuple (ie the number of occurences)
    sort(vec_count.begin(), vec_count.end());

    ofstream out;
    int spaces;
    out.open(out_name);
    out << "Word     Usage" << endl;
    // we go through the elements of the vector in reverse order so that they are sorted decreasingly in the output
    for (vector<tuple<int, string>>::iterator it = vec_count.end(); it != vec_count.begin(); --it){
        spaces = max_length + 2 - get<1>(*it).size();
        out << get<1>(*it);
        for (int i = 0; i < spaces; i++){
            out << " ";
        }
        out << get<0>(*it) << endl;
    }

    out.close();

    return 0;
}

