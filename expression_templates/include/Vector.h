#pragma once

#include <array>

namespace expression {

template <
    class T,
    int D>
class Vector {
  private:
  std::array<T, D> data;

  public:
  T& operator[](int index)
  {
    return &data[index];
  }
  const T& operator[](int index) const
  {
    return &data[index];
  }
  Vector<T, D> operator+(const Vector& rhs)
  {
    Vector<T, D> result;
    for (int i = 0; i < D; i++) {
      result[i] = operator[](i) + rhs[i];
    }
    return result;
  }
};
} // namespace expression
