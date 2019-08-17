//
// Created by philipp on 8/17/19.
//

#include <catch2/catch.hpp>

#include <print.h>

TEST_CASE("Print")
{
  print("test", 3.2,1);
  print("\n");
  println("test");
  print("\n");
  printls("test");
}

