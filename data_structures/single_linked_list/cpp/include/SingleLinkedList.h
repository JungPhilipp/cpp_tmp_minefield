//
// Created by philipp on 8/18/19.
//

#pragma once
#include <Node.h>

#include <unordered_set>

namespace data_structures {
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
    assert(false);
  }

  template <class IterableContainer>
  auto operator==(IterableContainer const& container) const -> bool
  {
    auto current = head;
    for (const auto& v : container) {
      if (not current)
        return false;
      if (v != current->data)
        return false;
      current = current->next;
    }
    return true;
  }

  auto removeNext(Node<T>* node) -> void
  {
    if (not node->hasNext())
      return;
    auto tmp = node->next;
    node->next = node->next->next;
    tmp->next = nullptr;
    delete tmp;
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

    auto current = head;
    while (current->hasNext()) {
      if (current->next->data == data) {
        removeNext(current);
        return;
      }
      current = current->next;
    }
  }

  auto removeDuplicates() -> void
  {
    if (not head)
      return;

    auto unique = std::unordered_set<T> { head->data };
    auto current = head;
    while (current->hasNext()) {
      auto found = unique.find(current->next->data) != end(unique);
      if (not found) {
        unique.insert(current->data);
        current = current->next;
      } else
        removeNext(current);
    }
  }

  auto removeDuplicateWithoutBuffer() -> void
  {
    auto current = head;
    while (current->hasNext()) {
      auto next = current->next;
      auto last = current;

      while (next) {
        if (next->data == current->data)
          removeNext(last);
        else
          last = next;
        next = last->next;
      }

      current = current->next;
    }
  }

  auto kThLast(size_t k) -> Node<T>*
  {
    auto current = head;
    auto element = current;
    auto distance = 0;
    while (distance <= k) {
      if (not element)
        return nullptr;
      element = element->next;
      distance++;
    }
    while (element) {
      element = element->next;
      current = current->next;
    }
    return current;
  }
};
} // namespace data_structures