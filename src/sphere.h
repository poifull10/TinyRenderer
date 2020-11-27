#pragma once
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
    const auto b = d.dot(s - o);
    const auto c = (std::pow((s - o).norm(), 2) - std::pow(r_, 2));
    const auto D = 4 * b * b - 4 * a * c;
    if (D < 0) {
      return std::nullopt;
    }
    const auto k = (-b - std::sqrt(D)) / a;
    const auto reflectedPoint = ray.at(k);
    auto n = reflectedPoint - origin_;
    n = n / n.norm();
    const auto reflectedDirection = d + n * (-d.dot(n));
    return RayInteractionResult{
        Ray(reflectedPoint, reflectedDirection / reflectedDirection.norm()),
        RGB(255, 255, 255),
        0.5F};
  }

 private:
  float r_;
  Vec origin_;
};
}  // namespace render
