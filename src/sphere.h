#pragma once
#include <cmath>
#include <iostream>

#include "ray.h"
#include "vec.h"

namespace render {
class Sphere {
 public:
  Sphere(float r, const Vec& origin) : r_(r), origin_(origin) {}

  bool hit(const Ray& ray) const {
    const auto o = ray.origin();
    const auto d = ray.direction();
    const auto s = origin_;
    const auto D = std::pow(d.x() * (s.x() - o.x()) + d.y() * (s.y() - o.y()) + d.z() * (s.z() - o.z()), 2.F) -
                   (std::pow((s - o).norm(), 2) - std::pow(r_, 2));
    return D >= 0;
  }

 private:
  float r_;
  Vec origin_;
};
}  // namespace render
