//
// Created by philipp on 8/17/19.
//
#pragma once

#include <cassert>
#include <cstddef>
#include <export.h>
#include <initializer_list>
#include <vector>

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

  auto operator==(Node<T> const& other) const -> bool
  {
    return other->data == data;
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

} // namespace data_structures