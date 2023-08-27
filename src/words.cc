#include "words.h"

#include <fstream>
#include <iostream>

// Assumes that the file is ASCII and that each word is on its own line, with no
// blank lines.
std::vector<std::string> read_words(std::string file_name) {
  std::ifstream file(file_name);
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(file, line)) {
    line.pop_back(); // Removes '\r' at end of line
    lines.push_back(line);
  }
  return lines;
}
