#pragma once
#include <array>
#include <cmath>

namespace render {
class Vec {
 public:
  Vec() : data_{} {}
  Vec(float x, float y, float z) : data_{x, y, z} {}

  float& x() { return data_[0]; }
  float& y() { return data_[1]; }
  float& z() { return data_[2]; }

  float x() const { return data_[0]; }
  float y() const { return data_[1]; }
  float z() const { return data_[2]; }

  float norm() const {
    return std::sqrt(data_[0] * data_[0] +
                     data_[1] * data_[1] +
                     data_[2] * data_[2]);
  }

  Vec normalize() const {
    return Vec(x() / norm(),
               y() / norm(),
               z() / norm());
  }

  Vec operator-(const Vec& vec) const {
    return Vec(x() - vec.x(), y() - vec.y(), z() - vec.z());
  }

 private:
  std::array<float, 3> data_;
};

}  // namespace render
