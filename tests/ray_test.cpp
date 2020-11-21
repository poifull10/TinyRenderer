#include <gtest/gtest.h>
#include <ray.h>

TEST(Ray, construct) {
  using namespace render;
  Ray ray(Vec(), Vec(0, 0, 1));
  EXPECT_THROW(Ray(Vec(), Vec()), std::invalid_argument);
}

TEST(Ray, get) {
  using namespace render;
  Ray ray(Vec(), Vec(0, 0, 1));
  ASSERT_FLOAT_EQ(ray.origin().x(), 0.F);
  ASSERT_FLOAT_EQ(ray.origin().y(), 0.F);
  ASSERT_FLOAT_EQ(ray.origin().z(), 0.F);
  ASSERT_EQ(ray.direction().norm(), 1.F);
  ASSERT_FLOAT_EQ(ray.direction().x(), 0.F);
  ASSERT_FLOAT_EQ(ray.direction().y(), 0.F);
  ASSERT_FLOAT_EQ(ray.direction().z(), 1.F);
}
