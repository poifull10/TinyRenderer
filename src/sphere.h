#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>

#include "object.h"
#include "ray.h"
#include "vec.h"

namespace render {
class Sphere : public RenderObject {
 public:
  Sphere(float r, const Vec& origin) : r_(r), origin_(origin) {}

  std::optional<RayInteractionResult> interact(const Ray& ray) const override {
    const auto o = ray.origin();
    const auto d = ray.direction();
    const auto s = origin_;
    const auto a = 1.F;
    const auto b = -2.F * d.dot(s - o);
    const auto c = std::pow((s - o).norm(), 2) - std::pow(r_, 2);
    const auto D = b * b - 4 * a * c;
    if (D < 0) {
      return std::nullopt;
    }
    const auto k = (-b - std::sqrt(D)) / (2.F * a);
    if (k <= 0) {
      return std::nullopt;
    }
    const auto reflectedPoint = ray.at(k);
    const auto n = (reflectedPoint - origin_).normalize();
    const auto reflectedDirection = (d + n * (2 * -d.dot(n))).normalize();
    const auto decay = std::clamp(n.dot(reflectedDirection), 0.F, 1.F);
    return RayInteractionResult{
        Ray(reflectedPoint, reflectedDirection),
        Albedo(decay, decay, decay)};
  }

 private:
  float r_;
  Vec origin_;
};
}  // namespace render
