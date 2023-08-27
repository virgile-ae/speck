#include "recommend.h"

#include <algorithm>
#include <iostream>
#include <ranges>
#include <set>

#include "levenshtein_distance.h"

struct Recommendation {
  std::string value;
  int score;

  Recommendation(std::string value, int score) : value(value), score(score) {}
  Recommendation(std::string value, std::string other) : value(value) {
    this->score = levenshtein_distance(value, other);
  }
  friend bool operator<(const Recommendation &a, const Recommendation &b) {
    return a.score < b.score;
  }
  friend bool operator==(const Recommendation &a, const Recommendation &b) {
    return a.score == b.score && a.value == b.value;
  }
};

std::ostream &operator<<(std::ostream &os, const Recommendation &r) {
  os << r.value << '(' << r.score << ')';
  return os;
}

std::vector<std::string> recommend(std::string input,
                                   std::vector<std::string> words,
                                   int recommendation_count) {
  std::vector<Recommendation> recommendations;
  for (std::string word : words) {
    Recommendation recommendation(word, input);
    recommendations.push_back(recommendation);
    if (int(recommendations.size()) > recommendation_count) {
      std::sort(recommendations.begin(), recommendations.end());
      recommendations.pop_back();
    }
  }

  auto view = recommendations |
              std::ranges::views::transform([](Recommendation recommendation) {
                return recommendation.value;
              });
  return {view.begin(), view.end()};
}
