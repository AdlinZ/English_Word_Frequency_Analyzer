#include "word_processor.h"
#include <regex>
#include <cctype>

std::string clean_word(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (std::isalpha(c)) {
            cleaned += static_cast<char>(std::tolower(c));
        }
    }
    return cleaned;
}

std::vector<std::string> extract_words(const std::string& text) {
    std::vector<std::string> words;
    std::regex word_regex(R"(\b[a-zA-Z]+\b)");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();
    for (auto it = words_begin; it != words_end; ++it) {
        if (std::string word = clean_word(it->str()); !word.empty()) {
            words.push_back(word);
        }
    }
    return words;
}
