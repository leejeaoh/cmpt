// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task04.h"

/* Create a copy of obj so no pass by reference*/
ex0::ButterPats task04(ex0::HotPotato potato) {
    potato.addButter(); //incrementing butter count using method from support.h
    return potato.getButterCount(); //return a copy of modified obj's count by calling get method
}