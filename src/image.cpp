#include "image.h"

namespace render {

std::size_t Image::reIndex(std::size_t w, std::size_t h) const {
  return w + h * width_;
}

RGB& Image::operator()(std::size_t w, std::size_t h) {
  return data_[reIndex(w, h)];
}
RGB Image::operator()(std::size_t w, std::size_t h) const {
  return data_[reIndex(w, h)];
}

}  // namespace render
