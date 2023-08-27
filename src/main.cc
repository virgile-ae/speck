#include <iostream>

#include "recommend.h"
#include "words.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Usage: speck <word1> <word2> ...\n";
    return 0;
  }
  std::vector<std::string> words(read_words());
  for (int i = 1; i < argc; i++) {
    char *word = argv[i];
    std::vector<std::string> recommendations = recommend(word, words);
    for (std::string recommendation : recommendations) {
      std::cout << recommendation << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}
