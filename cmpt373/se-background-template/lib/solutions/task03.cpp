// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task03.h"

ex0::ButterPats task03(const ex0::HotPotato& potato) {
    return ex0::ButterPats(potato.getButterCount().count + 1);
}