#include "levenshtein_distance.h"

#include <algorithm>
#include <numeric>
#include <vector>

// Taken from
// https://en.wikipedia.org/wiki/Levenshtein_distance#Iterative_with_two_matrix_rows
int levenshtein_distance(std::string first, std::string second) {
  int m = first.size();
  int n = second.size();

  std::vector<uint8_t> v0(n + 1);
  std::vector<uint8_t> v1(n + 1);

  std::iota(v0.begin(), v0.end(), 0);

  for (int i = 0; i < m; i++) {
    v1[0] = i + 1;
    for (int j = 0; j < n; j++) {
      int deletion_cost = v0[j + 1] + 1;
      int insertion_cost = v1[j] + 1;
      int substitution_cost = v0[j] + (first[i] != second[j]);
      v1[j + 1] = std::min({deletion_cost, insertion_cost, substitution_cost});
    }
    v0.swap(v1);
  }

  return v0.back();
}
