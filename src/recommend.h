#ifndef RECOMMEND_H_
#define RECOMMEND_H_

#include <string>
#include <vector>

std::vector<std::string> recommend(std::string input,
                                   std::vector<std::string> words,
                                   int number_of_recommendations = 5);

#endif // RECOMMEND_H_
