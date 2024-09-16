// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include <algorithm>
#include <numeric>
#include <ranges>
#include <string_view>
#include <vector>

#include "task07.h"

std::string task07(const std::string& input, const std::unordered_map<char,const std::string>& replace) {
    std::string output;
    for(const char& c : input) {
        if(const auto e = replace.find(c); e != replace.end()) {
            output += e->second;
        } else {
            output += c;
        }
    }
    return output;
}