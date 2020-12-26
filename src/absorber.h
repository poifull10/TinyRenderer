#pragma once
#include "image.h"
#include "ray.h"

namespace render {

struct Absorber {
  virtual RGB operator()(const RGB& rgb, float distance) const {
    return rgb;
  }
};
struct LinearAbsorber : public Absorber {
  float lambda;
  RGB operator()(const RGB& rgb, float distance) const override {
    return RGB(CRAMP_RGB(rgb.r - distance * lambda),
               CRAMP_RGB(rgb.g - distance * lambda),
               CRAMP_RGB(rgb.b - distance * lambda));
  }
};

struct StandardAbsorber : public Absorber {
  constexpr float pi = 3.141592653F;
  RGB operator()(const RGB& rgb, float distance) const override {
    return RGB(CRAMP_RGB(rgb.r / (4 * pi * distance * distance)),
               CRAMP_RGB(rgb.g / (4 * pi * distance * distance)),
               CRAMP_RGB(rgb.b / (4 * pi * distance * distance)));
  }
};

}  // namespace render
