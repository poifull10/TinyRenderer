#include "image.h"

#include <boost/gil.hpp>
#include <boost/gil/extension/io/png.hpp>

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

void Image::save(const std::string& path) const {
  boost::gil::rgb8_image_t image(width_, height_);
  copy_pixels(interleaved_view(width_,
                               height_,
                               (const boost::gil::rgb8_pixel_t*)data_.data(),
                               width_ * 3),
              view(image));
  boost::gil::write_view(path, const_view(image), boost::gil::png_tag{});
}

Image Image::load(const std::string& path) {
  boost::gil::rgb8_image_t image;
  boost::gil::read_image(path, image, boost::gil::png_tag{});
  Image outputImage(const_view(image).width(), const_view(image).height());
  copy_pixels(const_view(image), interleaved_view(outputImage.width(),
                                                  outputImage.height(),
                                                  (boost::gil::rgb8_pixel_t*)outputImage.data(),
                                                  outputImage.width() * 3));
  return outputImage;
}

}  // namespace render
