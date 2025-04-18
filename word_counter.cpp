#include "word_counter.h"
#include <iostream>
#include <fstream>
#include <algorithm>

std::unordered_map<std::string, int> count_words(const std::vector<std::string>& words) {
    std::unordered_map<std::string, int> freq;
    for (const auto& word : words) {
        freq[word]++;
    }
    return freq;
}

bool compare_freq(const std::pair<std::string, int>& a,
                  const std::pair<std::string, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void print_word_stats(const std::unordered_map<std::string, int>& freq, const int top_n) {
    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(), compare_freq);

    std::cout << "Top " << top_n << " Words:\n";
    std::cout << "====================\n";
    for (int i = 0; i < std::min(top_n, static_cast<int>(sorted.size())); ++i) {
        printf("%-15s %5d\n", sorted[i].first.c_str(), sorted[i].second);
    }

    std::cout << "\n词频直方图:\n";
    constexpr int max_bar_length = 30;
    if (!sorted.empty()) {
        int max_count;
        max_count = sorted[0].second;
        for (int i = 0; i < std::min(top_n, static_cast<int>(sorted.size())); ++i) {
            int bar_length = static_cast<float>(sorted[i].second) / max_count * max_bar_length;
            std::cout << sorted[i].first << " | "
                      << std::string(bar_length, '#')
                      << " (" << sorted[i].second << ")\n";
        }
    }

    std::ofstream csv_file("word_freq.csv");
    if (csv_file.is_open()) {
        csv_file << "Word,Frequency\n";
        for (const auto& pair : sorted) {
            csv_file << pair.first << "," << pair.second << "\n";
        }
    } else {
        std::cerr << "无法打开 word_freq.csv 文件进行写入。" << std::endl;
    }
}
