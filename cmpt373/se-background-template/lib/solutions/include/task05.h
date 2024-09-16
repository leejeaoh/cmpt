// ID 9c8e9a75094246cdd2d9884e896a9b8d
#pragma once

#include "Support.h"

class Task05{
    public:
        explicit Task05 (ex0::HotPotato &potato) noexcept;
        void butterExcessively() noexcept;

    private:
        ex0::HotPotato& potato_; 
};

