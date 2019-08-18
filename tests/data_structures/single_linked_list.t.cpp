//
// Created by philipp on 8/17/19.
//

#include <catch2/catch.hpp>

#include <Node.h>
#include <SingleLinkedList.h>
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
TEST_CASE("remove", "[single_linked_list]")
{
  auto list = SingleLinkedList({ 10, 20, 30, 40 });
  REQUIRE(list.size() == 4);
  SECTION("front")
  {
    list.remove(10);
    REQUIRE(list[0] == 20);
  }
  SECTION("middle")
  {
    list.remove(20);
    REQUIRE(list.size() == 3);
    REQUIRE(list[1] == 30);
  }
  SECTION("back")
  {
    list.remove(40);
    REQUIRE(list.size() == 3);
    REQUIRE(list[2] == 30);
  }
}
TEST_CASE("Equality", "[single_linked_list]")
{
  auto values = std::initializer_list({ 10, 10, 20, 5, 20 });
  auto list = SingleLinkedList(values);
  auto vector = std::vector(values);
  REQUIRE(list == vector);
}
TEST_CASE("remove_duplicates_from_unsorted", "[single_linked_list]")
{
  auto values = std::initializer_list({ 10, 20, 5, 3, 10, 20, 50, 5, 20 });
  auto unique_list = std::vector { 10, 20, 5, 3, 50 };
  auto list = SingleLinkedList(values);

  auto unique_vector = std::vector(values);
  sort(begin(unique_vector), end(unique_vector));
  unique_vector.erase(unique(begin(unique_vector), end(unique_vector)), end(unique_vector));

  SECTION("with_buffer")
  {
    list.removeDuplicates();
    REQUIRE(list.size() == unique_vector.size());
    REQUIRE(list == unique_list);
  }
  SECTION("without_buffer")
  {
    list.removeDuplicateWithoutBuffer();
    REQUIRE(list.size() == unique_vector.size());
    REQUIRE(list == unique_list);
  }
}

TEST_CASE("kTh last element", "[single_linked_list]")
{
  auto values = std::initializer_list { 2, 5, 2, 1, 3, 10 };
  auto list = SingleLinkedList(values);

  SECTION("kTh last element")
  {
    REQUIRE(**list.kThLast(0) == 10);
    REQUIRE(**list.kThLast(2) == 1);
    REQUIRE(**list.kThLast(4) == 5);
  }

  SECTION("Remove middle node")
  {
  }
}
