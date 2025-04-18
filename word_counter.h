#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, int> count_words(const std::vector<std::string>& words);
void print_word_stats(const std::unordered_map<std::string, int>& freq, int top_n = 10);

#endif
