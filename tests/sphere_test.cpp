#include <gtest/gtest.h>
#include <ray.h>
#include <sphere.h>

TEST(Sphere, construct) {
  render::Sphere sphere(10.F, render::Vec());
}

TEST(Sphere, hit) {
  using namespace render;
  Sphere sphere(5.F, Vec(0, 0, 10));
  Ray hitRay(Vec(), Vec(0, 0, 1));
  ASSERT_TRUE(sphere.hit(hitRay));
  Ray nonHitRay(Vec(10, 0, 0), Vec(0, 0, 1));
  ASSERT_FALSE(sphere.hit(nonHitRay));
}
