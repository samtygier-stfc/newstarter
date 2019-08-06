#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

/* Replaces the hyphens in a string with a whitespace character
 *
 * @param word reference to a word of type string
 * @return bool as to whether the word contained a hyphen
 *
 */
bool replaceHyphens(std::string &word);

/* Determines if a character is punctuation
 *
 * @param c a character which needs to be checked
 * @return bool as to whether the character was punctuation
 *
 */
bool isPunc(char &const c);

/* Removes the punctuation
 *
 * @param word a reference to a word as a string
 *
 */
void cleanWord(std::string &word);

/* Cleans the word using the cleanWord function, adds word to a map and stores
the no. of instances of the word if the word is longer than the minimum word
length and caluclates the longest word
*
* @param word reference to a word as a string
* @param counter Reference to an empty map to hold the unique words and the no.
of instances
* @param maxlen Reference to a variable which will store the longest word length
* @param minWordLength length of the smallest word allowed to be stored in the
map
*
*/
void processWord(std::string &word, std::map<std::string, int> &counter,
                 std::string::size_type &maxlen,
                 std::string::size_type const minWordLength);

/* Converts a map to a vector of pairs to contain the unique words and their
 * number of usages
 *
 * @param map A reference to a map containing the words and their usages
 * @return The vector containing the words and their usages as pairs
 *
 */
std::vector<std::pair<std::string, int>> const
mapToVector(const std::map<std::string, int> &map);

/* Determines which word has more usages
 *
 * @param pair1 A word and its usage
 * @param pair2 Another word and its usage
 * @return a bool as to whether pair1 was used more than pair2
 *
 */
bool pairValueIsGreater(std::pair<std::string, int> const pair1,
                        std::pair<std::string, int> const pair2);

/* Prints the vector into a file
 *
 * @param counter A vector conatining the unique words and their usages
 * @param pad the length of the longest word plus 1 to detemine the width of the
 * column
 *
 */
void vectortoFile(std::vector<std::pair<std::string, int>> const counter,
                  std::string::size_type const pad);

/* Caluclates the number of instances of unique words and prints it into a file
 *
 * @param minWordLength the minimum length of word to be classed as a unique
 * word
 *
 */
void uniqueWordCounter(std::string::size_type const minWordLength);
