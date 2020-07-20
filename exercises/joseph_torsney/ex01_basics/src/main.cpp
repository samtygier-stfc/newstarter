#include <iostream> 
#include <fstream>
#include <vector>

bool myIsPunct(char c) {
  return(
    c == '.' &&
    c == ',' &&
    c == '?' &&
    c == '\'' &&
    c == '\"' &&
    c == '!' &&
    c == ')' &&
    c == '('
  );
}

/*
* readFile takes a filename of a txt file and returns its contents as a string.
*/
std::string readFile(const std::string filename)
{
  std::ifstream ifs(filename);
  std::string text(
    (std::istreambuf_iterator<char>(ifs)),
    (std::istreambuf_iterator<char>())
  );
  return(text);
}

/*
* removePunct takes a string and returns that string with no punctuation.
*/
std::string removePunct(std::string str)
{
  for (int i = 0, len = str.size(); i < len; i++) {
    if (myIsPunct(str[i])) {
      // if this char is punctuation, reduce i by 1, remove it, and
      // reevaluate the string size.
      str.erase(i--, 1);
      len = str.size();
    }
  }
  return(str);
}

std::vector<std::string> split(const std::string& s)
{
  std::vector<std::string> ret;
  typedef std::string::size_type string_size;
  string_size i = 0;

  // process characters of s
  while (i != s.size()) {

    // ignore whitespace
    while(i != s.size() && (isspace(s[i]) || s[i] == '-')) {
      i++;
    }

    // otherwise, we are at the start of a word.
    string_size j = i;

    // find the position of the next space.
    while (j != s.size() && !(isspace(s[j]) || s[j] == '-')) {
      j++;
    }

    // If we have found a word
    if (i != j) {
      // copy substring from i, taking j - i chars.
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return(ret);
}

int main(int argc, char** argv)
{ 
  std::cout << "Reading file" << std::endl;
  std::string text = readFile(argv[1]);

  std::cout << "Removing punctuation" << std::endl;
  text = removePunct(text);

  std::cout << "Splitting string" << std::endl;
  std::vector<std::string> words = split(text);
  for (int i = 0; i < words.size(); i++) {
    std::cout << words[i];
  }
}