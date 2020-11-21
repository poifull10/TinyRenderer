#include <camera.h>
#include <gtest/gtest.h>

TEST(Camera, construct) {
  render::Camera camera(11, 13);
  ASSERT_EQ(camera.image().width(), 11);
  ASSERT_EQ(camera.image().height(), 13);
}  // namespace render

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
