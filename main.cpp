#include "file_reader.h"
#include "word_processor.h"
#include "word_counter.h"
#include "plotter.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        const std::string file_path = "test.txt";
        const std::string content = read_file(file_path);

        std::vector<std::string> words;
        words = extract_words(content);
        if (words.empty()) {
            std::cerr << "错误: 文件中未找到有效英文单词\n";
            return 1;
        }

        std::unordered_map<std::string, int> freq;
        freq = count_words(words);
        print_word_stats(freq);
        run_python_plot();

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\033[31m致命错误: " << e.what() << "\033[0m\n";
        return 1;
    }
}
