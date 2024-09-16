// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task06.h"

#include <numeric>

uint32_t task06(const std::string& str) {
    return std::accumulate(str.begin(),str.end(),static_cast<u_int32_t>(0));
}