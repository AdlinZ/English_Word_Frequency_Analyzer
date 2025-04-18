#include "file_reader.h"
#include <fstream>
#include <stdexcept>

std::string read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("无法打开文件: " + path + " (请确认文件存在且路径正确)");
    }
    return std::string(std::istreambuf_iterator(file),
                       std::istreambuf_iterator<char>());
}
