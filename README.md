# English_Word_Frequency_Analyzer

## 项目概述
一个用于分析英文文本中单词频率的工具。支持读取文本文件、提取英文单词、统计词频，并生成前10高频词的柱状统计图。

---

## 项目结构
```text
English_Word_Frequency_Analyzer/
├── CMakeLists.txt               # CMake 构建脚本  
├── word_processor.h             # 单词处理头文件  
├── word_counter.h               # 词频统计头文件  
├── file_reader.h                # 文件读取头文件  
├── plotter.h                    # 绘图模块头文件  
├── word_processor.cpp           # 单词处理实现  
├── word_counter.cpp             # 词频统计实现  
├── file_reader.cpp              # 文件读取实现  
├── plotter.cpp                  # 绘图模块实现  
├── main.cpp                     # 程序入口  
└── cmake-build-debug/           # 编译输出目录  
    ├── plot.py                  # Python 绘图脚本  
    └── test.txt                 # 测试文本文件  
```

---

## 核心功能
```text
✅ 文件读取：从文本文件读取内容

✅ 单词提取：过滤非英文单词（统一小写）

✅ 词频统计：计算单词出现频率

📊 可视化：生成前10高频词柱状图
```

---
## 必须安装的库
```Python
pip install matplotlib
```

Python 版本: ≥3.13

### 使用指南
1. 克隆仓库
```bash
git clone https://github.com/xxx/English_Word_Frequency_Analyzer.git
cd English_Word_Frequency_Analyzer
```
2. 构建项目
```bash
mkdir build && cd build
cmake ..
make
```

3. 准备测试文件
在build目录创建test.txt：

```text
This is a sample text.
Hello world! Hello analyzer!
```

4. 运行程序
```bash
./EnglishWordFrequencyAnalyzer
```
输出示例
控制台输出
```text
hello     : 2
world     : 1
analyzer  : 1
this      : 1
...
```
可视化效果
词频柱状图

模块文档
文件读取模块
```cpp
/**
 * @brief 读取文本文件内容
 * @param path 文件路径
 * @return 文件内容字符串
 * @throws std::runtime_error 文件不存在时抛出
 */
std::string read_file(const std::string& path);
词频统计模块
cpp
// 统计单词频率
std::unordered_map<std::string, int> count_words(
    const std::vector<std::string>& words
);

// 打印统计结果（按频率降序）
void print_word_stats(
    const std::unordered_map<std::string, int>& freq
);
```

## 注意事项
输入文件必须命名为test.txt并放在可执行文件同级目录

若绘图失败请检查：

Python是否安装matplotlib

系统PATH是否包含Python路径

贡献方式
提交PR至develop分支

问题反馈请提交Issue

许可证
MIT License © 2023