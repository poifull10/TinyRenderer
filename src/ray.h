#pragma once
#include "vec.h"
namespace render {
class Ray {
 public:
  Ray(const Vec& origin, const Vec& direction) : origin_(origin), direction_(direction) {
    if (std::abs(direction_.norm() - 1.F) > 1e-3F) {
      throw std::invalid_argument("Invalid direction: the norm must be 1.");
    }
  }

  Vec origin() const { return origin_; }
  Vec direction() const { return direction_; }
  Vec at(float k) const { return origin_ + direction_ * k; }

 private:
  Vec origin_;
  Vec direction_;
};
}  // namespace render
