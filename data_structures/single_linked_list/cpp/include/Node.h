//
// Created by philipp on 8/17/19.
//
#pragma once

#include <cassert>
#include <cstddef>
#include <export.h>
#include <initializer_list>

namespace data_structures {

template <class T>
class SingleLinkedList;

template <class T>
class EXPORT Node {
  T data;

  public:
  Node(T const& v)
      : data(v)
  {
  }

  ~Node()
  {
    if (next)
      delete next;
  }
  T operator*()
  {
    return data;
  }

  Node<T>* next { nullptr };

  auto hasNext() const -> bool { return next != nullptr; };

  auto append(T const& v) -> void
  {
    auto current = this;
    while (current->hasNext())
      current = current->next;
    current->next = new Node { v };
  }
  friend class SingleLinkedList<T>;
};

template <class T>
class EXPORT SingleLinkedList {
  Node<T>* head { nullptr };

  public:
  auto append(T const& v) -> void
  {
    if (!head)
      head = new Node { v };
    else {
      head->append(v);
    }
  }
  auto size() const -> size_t
  {
    size_t size = 0;
    auto next = head;
    while (next) {
      size++;
      next = next->next;
    }
    return size;
  }
  SingleLinkedList(std::initializer_list<T> const& values)
  {
    auto last = head;
    for (const auto& v : values) {
      auto newNode = new Node<T> { v };
      if (!last) {
        last = newNode;
        head = last;
      } else {
        last->next = newNode;
        last = last->next;
      }
    }
  }

  auto operator[](size_t index) -> T&
  {
    auto current = head;
    size_t i = 0;
    while (current) {
      if (index == i)
        return current->data;

      current = current->next;
      i++;
    }
  }

  auto remove(T const& data) -> void
  {
    if (!head)
      return;
    if (head->data == data) {
      auto tmp = head;
      head = head->next;
      tmp->next = nullptr;
      delete tmp;
      return;
    }
  }
};

} // namespace data_structures