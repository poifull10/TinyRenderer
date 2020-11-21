#include <camera.h>
#include <gtest/gtest.h>

TEST(Camera, construct) {
  render::Camera camera(11, 13);
  ASSERT_EQ(camera.width(), 11);
  ASSERT_EQ(camera.height(), 13);
}

TEST(Camera, ray) {
  render::Camera camera(11, 11);
  const auto ray = camera.ray(5, 5);
  ASSERT_FLOAT_EQ(ray.origin().x(), 0.F);
  ASSERT_FLOAT_EQ(ray.origin().y(), 0.F);
  ASSERT_FLOAT_EQ(ray.origin().z(), 0.F);
  ASSERT_EQ(ray.direction().norm(), 1.F);
  ASSERT_FLOAT_EQ(ray.direction().x(), 0.F);
  ASSERT_FLOAT_EQ(ray.direction().y(), 0.F);
  ASSERT_FLOAT_EQ(ray.direction().z(), 1.F);
}

TEST(Camera, image) {
  render::Camera camera(11, 13);
  ASSERT_EQ(camera.width(), 11);
  ASSERT_EQ(camera.height(), 13);
}
