/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <map>

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
    int max_length = 6; // size of "Usage", which we systematically write
    size_t word_size;

    while (in >> word){
        word_size = word.size();
        if (word_size >= 4){
            word_count[word]++;
            if (word_size > max_length){
                max_length = word_size;
            }
        }
    }
    in.close();

    ofstream out;
    out.open(out_name);

    for (map<string, int>::iterator it = word_count.begin(); it != word_count.end(); ++it){
        out << it->first << "   "  << it->second << endl;
    }
    out.close();

    return 0;
}

