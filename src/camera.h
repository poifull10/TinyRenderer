#pragma once
#include <cmath>

#include "image.h"
#include "ray.h"

namespace render {
class Camera {
 public:
  Camera(std::size_t width, std::size_t height) : image_(width, height) {}

  std::size_t width() const { return image_.width(); }
  std::size_t height() const { return image_.height(); }

  void save(const std::string& path) const { image_.save(path); }
  void load(const std::string& path) { image_ = Image::load(path); }

  RGB& image(std::size_t w, std::size_t h) { return image_(w, h); }

  Ray ray(std::size_t w, std::size_t h) const {
    constexpr auto pixelSize = 1e-3F;
    constexpr auto focalLength = 1.F;
    Vec origin;

    const int center_x = image_.width() / 2;
    const int center_y = image_.height() / 2;

    const auto x = (static_cast<int>(w) - center_x) * pixelSize;
    const auto y = (static_cast<int>(h) - center_y) * pixelSize;
    Vec direction(x, y, focalLength);

    return Ray(origin, direction.normalize());
  }

 private:
  Image image_;
};
}  // namespace render
