#ifndef WORD_PROCESSOR_H
#define WORD_PROCESSOR_H

#include <string>
#include <vector>

std::string clean_word(const std::string& word);
std::vector<std::string> extract_words(const std::string& text);

#endif
