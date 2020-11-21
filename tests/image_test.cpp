#include <gtest/gtest.h>
#include <image.h>

TEST(Image, construct) {
  render::Image image(10, 11);
  ASSERT_EQ(image.width(), 10);
  ASSERT_EQ(image.height(), 11);
}

TEST(Image, get_set) {
  render::Image image(10, 10);
  ASSERT_EQ(image(0, 0), render::RGB(0, 0, 0));
  ASSERT_EQ(image(1, 1), render::RGB(0, 0, 0));
  image(0, 0) = render::RGB(2, 3, 4);
  image(1, 1) = render::RGB(5, 6, 7);
  ASSERT_EQ(image(0, 0), render::RGB(2, 3, 4));
  ASSERT_EQ(image(1, 1), render::RGB(5, 6, 7));
}

TEST(Image, load_save) {
  using RGB = render::RGB;
  render::Image image(2, 2);
  image(0, 0) = RGB(0, 0, 0);
  image(1, 0) = RGB(255, 255, 255);
  image(0, 1) = RGB(255, 0, 0);
  image(1, 1) = RGB(0, 255, 0);
  image.save("test.png");

  render::Image loadedImage = render::Image::load("test.png");
  ASSERT_EQ(loadedImage(0, 0), RGB(0, 0, 0));
  ASSERT_EQ(loadedImage(1, 0), RGB(255, 255, 255));
  ASSERT_EQ(loadedImage(0, 1), RGB(255, 0, 0));
  ASSERT_EQ(loadedImage(1, 1), RGB(0, 255, 0));
}
