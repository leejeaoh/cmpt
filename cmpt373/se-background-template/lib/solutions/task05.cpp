// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task05.h"

Task05::Task05(ex0::HotPotato& potato) noexcept : potato_(potato) {};

void Task05::butterExcessively() noexcept {
    for(int i = 0; i < 5; i++) {
        potato_.addButter();
    }
}