#pragma once

#include <stdexcept>

#include "image.h"
#include "ray.h"

namespace render {
#define THROW_IN_RANGE_ALBEDO(x)                                                                  \
  if (x < 0 || 1 < x) {                                                                           \
    throw std::out_of_range("Out of range: " #x " = " + std::to_string(x) + " is not in [0, 1]"); \
  }

struct Albedo {
  float r;
  float g;
  float b;

  Albedo() : Albedo(1.F, 1.F, 1.F) {}
  Albedo(float r, float g, float b) : r(r), g(g), b(b) {
    THROW_IN_RANGE_ALBEDO(r);
    THROW_IN_RANGE_ALBEDO(g);
    THROW_IN_RANGE_ALBEDO(b);
  }
};

inline RGB operator*(const RGB& rgb, const Albedo& albedo) {
  return RGB(rgb.r * albedo.r,
             rgb.g * albedo.g,
             rgb.b * albedo.b);
}

inline Albedo operator*(const Albedo& albedo1, const Albedo& albedo2) {
  return Albedo(albedo1.r * albedo2.r,
                albedo1.g * albedo2.g,
                albedo1.b * albedo2.b);
}

struct Material {
  virtual Albedo operator()(const Ray& ray) = 0;
};
}  // namespace render
