#include <iostream> 
#include <fstream>

std::string readFile(const char* filename)
{
  std::ifstream ifs(filename);
  std::string text(
    (std::istreambuf_iterator<char>(ifs)),
    (std::istreambuf_iterator<char>())
  );
  return(text);
}

int main(int argc, char** argv)
{
  std::cout << readFile(argv[1]);
}