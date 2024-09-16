// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task02.h"

/*
    Caller/callee shares the argument value and modifying in value task02 should change
    the value that caller observes. 

    "out of parameter" basically means pass arguments by reference

    Side note: pass by reference allows function to modify a variable without having to create
    aa copy of it.

    in modern c++ discouraged due to difficult code to understand (non-obvious)
*/
int task02(int& value) {
    value += 1;
    return value;
}