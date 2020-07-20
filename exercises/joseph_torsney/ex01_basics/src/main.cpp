#include <iostream> 
#include <fstream>
#include <vector>

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
    if (ispunct(str[i])) {
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

}

int main(int argc, char** argv)
{
  std::string text = readFile(argv[1]);
  std::cout << removePunct(text);
}