#include "plotter.h"
#include <Python.h>
#include <iostream>

void run_python_plot() {
    FILE* fp = fopen("plot.py", "r");
    if (!fp) {
        std::cerr << "无法打开 plot.py 文件。\n";
        return;
    }

    Py_Initialize();
    PyRun_SimpleFile(fp, "plot.py");
    Py_Finalize();
    fclose(fp);
}
