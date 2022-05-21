#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <cassert>


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    std::ifstream file_data("task_onezero/test_data.txt");
    std::string data_line1, data_line2;

    std::string template_cmd = "g++ task_onezero/cpp/main.cpp; task_onezero/cpp/a.out <<EOF\n";
    std::string prep;
    const char *cmd;

    std::string output;

    std::ifstream file_results("task_onezero/test_results.txt");
    std::string result_line;

    while (file_data >> data_line1 && file_data >> data_line2 && file_results >> result_line) {
        prep = template_cmd + data_line1 + " " + data_line2 + "\nEOF";
        cmd = prep.c_str();
        output = exec(cmd);

        assert((output == result_line) && "output != result_line");
    }
    return 0;
}