#pragma once
#include <cmath>

#include "image.h"
#include "ray.h"

namespace render {
class Camera {
 public:
  Camera(std::size_t width, std::size_t height) : image_(width, height) {}

  Image image() const { return image_; }

  Ray ray(std::size_t w, std::size_t h) const {
    constexpr auto pixelSize = 1e-3F;
    constexpr auto focalLength = 1.F;
    Vec origin;

    const auto center_x = image_.width() / 2;
    const auto center_y = image_.height() / 2;

    const auto x = (w - center_x) * pixelSize;
    const auto y = (h - center_y) * pixelSize;
    Vec direction(x, y, focalLength);

    return Ray(origin, direction.normalize());
  }

 private:
  Image image_;
};
}  // namespace render
