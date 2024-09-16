// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include <cassert>
#include <cstdio>
#include "Support.h"

using ex0::HotPotato;
using ex0::ButterPats;


////////////////////////////////////////////////////////////////////////////////
//  HotPotato special member definitions
////////////////////////////////////////////////////////////////////////////////

HotPotato::HotPotato(ButterPats pats) noexcept
  : butterCount{pats} {
  printf("Create\n");
}

HotPotato::~HotPotato() noexcept {
  printf("Destroy\n");
}

HotPotato::HotPotato(const HotPotato& other) noexcept
  : butterCount{other.butterCount} {
  printf("Copy\n");
}

HotPotato::HotPotato(HotPotato&& other) noexcept
  : butterCount{other.butterCount} {
  printf("Move\n");
}

HotPotato&
HotPotato::operator=(const HotPotato&) noexcept {
  printf("Assign\n");
  return *this;
}

HotPotato&
HotPotato::operator=(HotPotato&&) noexcept {
  printf("Move Assign\n");
  return *this;
}
