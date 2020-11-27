#include <gtest/gtest.h>
#include <ray.h>
#include <sphere.h>

TEST(Sphere, construct) {
  render::Sphere sphere(10.F, render::Vec());
}

TEST(Sphere, interact) {
  using namespace render;
  Sphere sphere(5.F, Vec(0, 0, 10));
  Ray hitRay(Vec(), Vec(0, 0, 1));
  ASSERT_TRUE(sphere.interact(hitRay).has_value());
  Ray nonHitRay(Vec(10, 0, 0), Vec(0, 0, 1));
  ASSERT_FALSE(sphere.interact(nonHitRay).has_value());
}
