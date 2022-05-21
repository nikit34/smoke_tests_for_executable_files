#include <iostream>
#include <algorithm>


int main() {
    std::string s[2];
    std::cin >> s[0] >> s[1];

    std::string r[2];

    for(int i = 0; i < 2; ++i) {
        while (!s[i].empty()) {
            if (s[i].substr(s[i].size() - 3, 3) == "one") {
                s[i].pop_back();
                s[i].pop_back();
                s[i].pop_back();
                r[i] += "1";
            } else {
                s[i].pop_back();
                s[i].pop_back();
                s[i].pop_back();
                s[i].pop_back();
                r[i] += "0";
            }
        }
    }

    for(auto & s : r) {
        std::reverse(s.begin(), s.end());
    }

    if (r[0].size() > r[1].size()) {
        std::cout << ">";
    } else if (r[1].size() > r[0].size()) {
        std::cout << "<";
    } else if (r[0] > r[1]) {
        std::cout << ">";
    } else if (r[0] == r[1]) {
        std::cout << "=";
    } else {
        std::cout << "<";
    }

    return 0;
}
