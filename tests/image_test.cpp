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
