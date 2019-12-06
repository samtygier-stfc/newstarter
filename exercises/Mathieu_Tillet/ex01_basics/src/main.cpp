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

    char *file_name = argv[1];

    string out_name;
    if (argc > 2){
        out_name = string(argv[2]);
    } else {
        out_name = "./out.txt";
    }

    ifstream in;
    in.open(file_name);

    if (!in){
        cerr << "Error when reading the file" << endl;
        return -1;
    }

    string word;
    int max_length = 4; // size of "Word", which we systematically write
    size_t word_size;

    while (in >> word){
        word_size = word.size();
        if (word_size >= 5){
            word_count[word]++;
            if (word_size > max_length){
                max_length = word_size;
            }
        }
    }
    in.close();

    // we store the elements of word_counts in a vector so they can be sorted
    vector<tuple<int, string>> vec_count;
    for (map<string, int>::iterator it = word_count.begin(); it != word_count.end(); ++it){
        vec_count.push_back(tuple<int, string>(it->second, it->first));
    }
    sort(vec_count.begin(), vec_count.end());

    ofstream out;
    out.open(out_name);
    out << "Word     Usage" << endl;
    for (vector<tuple<int, string>>::iterator it = vec_count.end(); it != vec_count.begin(); --it){
        out << get<1>(*it) << "  " << get<0>(*it) << endl;
    }

    out.close();

    return 0;
}

