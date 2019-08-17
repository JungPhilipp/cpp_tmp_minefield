//
// Created by philipp on 8/17/19.
//

#include <catch2/catch.hpp>

#include <Node.h>
#include <print.h>

using namespace data_structures;

TEST_CASE("Node", "[single_linked_list]")
{
  const auto value = 10.;
  auto node = Node { value };
  REQUIRE(*node == value);
  REQUIRE(node.next == nullptr);
}
TEST_CASE("SingleLinkedList", "[single_linked_list]")
{
  auto list = SingleLinkedList({ 10., 20., 30. });
  REQUIRE(list.size() == 3);
  list.append(40);
  REQUIRE(list.size() == 4);
  REQUIRE(list[0] == 10.);
  REQUIRE(list[3] == 40);
}

TEST_CASE("SingleLinkedList_append_to_empty", "[single_linked_list]")
{
  auto list = SingleLinkedList<double> {};
  REQUIRE(list.size() == 0);
  list.append(10);
  REQUIRE(list.size() == 1);
  REQUIRE(list[0] == 10);
}
