#pragma once
#include <cctype>
#include <string>
#include <vector>

namespace render {
#define CRAMP_RGB(x) static_cast<std::uint8_t>(std::clamp(static_cast<int>(x), 0, 255))

struct RGB {
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;
  RGB() : r(), g(), b() {}
  RGB(std::uint8_t r, std::uint8_t g, std::uint8_t b) : r(r), g(g), b(b) {}
};

inline bool operator==(const RGB& rgb1, const RGB& rgb2) {
  return rgb1.r == rgb2.r && rgb1.g == rgb2.g && rgb1.b == rgb2.b;
}

inline bool operator!=(const RGB& rgb1, const RGB& rgb2) {
  return rgb1.r != rgb2.r || rgb1.g != rgb2.g || rgb1.b != rgb2.b;
}

inline RGB operator*(float decay, const RGB& rgb) {
  return RGB(rgb.r * decay, rgb.g * decay, rgb.b * decay);
}

inline RGB operator+(const RGB& rgb1, const RGB& rgb2) {
  int r = static_cast<int>(rgb1.r) + static_cast<int>(rgb2.r);
  int g = static_cast<int>(rgb1.g) + static_cast<int>(rgb2.g);
  int b = static_cast<int>(rgb1.b) + static_cast<int>(rgb2.b);
  auto clampCast = [](const int val) {
    return static_cast<std::uint8_t>(std::clamp(val, 0, 255));
  };
  return RGB(clampCast(r), clampCast(g), clampCast(b));
}

class Image {
 public:
  Image(std::size_t width, std::size_t height) : width_(width), height_(height), data_(width * height) {
  }

  std::size_t width() const { return width_; }
  std::size_t height() const { return height_; }

  RGB& operator()(std::size_t w, std::size_t h);
  RGB operator()(std::size_t w, std::size_t h) const;

  void save(const std::string& path) const;
  static Image load(const std::string& path);
  const RGB* data() { return data_.data(); }

 private:
  std::size_t width_;
  std::size_t height_;
  std::vector<RGB> data_;

  std::size_t reIndex(std::size_t w, std::size_t h) const;
};

}  // namespace render
