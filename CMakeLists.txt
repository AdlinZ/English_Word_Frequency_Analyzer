cmake_minimum_required(VERSION 3.10)
project(English_Word_Frequency_Analyzer)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)

# 查找Python库
find_package(Python3 COMPONENTS Development REQUIRED)

# 添加可执行文件
add_executable(English_Word_Frequency_Analyzer
        main.cpp
        file_reader.cpp
        word_processor.cpp
        word_counter.cpp
        plotter.cpp)

# 链接Python库
target_include_directories(English_Word_Frequency_Analyzer PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(English_Word_Frequency_Analyzer PRIVATE ${Python3_LIBRARIES})