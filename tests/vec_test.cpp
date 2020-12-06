#include <gtest/gtest.h>
#include <vec.h>

TEST(Vec, construct) {
  render::Vec vec1;
  render::Vec vec2(3, 1, 4);
}

TEST(Vec, operator) {
  {
    render::Vec vec1(3, 1, 4);
    ASSERT_FLOAT_EQ(vec1.x(), 3.F);
    ASSERT_FLOAT_EQ(vec1.y(), 1.F);
    ASSERT_FLOAT_EQ(vec1.z(), 4.F);
    ASSERT_FLOAT_EQ(vec1.norm(), 5.0990195135F);

    vec1.x() = 10.F;
    ASSERT_FLOAT_EQ(vec1.x(), 10.F);
    ASSERT_FLOAT_EQ(vec1.y(), 1.F);
    ASSERT_FLOAT_EQ(vec1.z(), 4.F);
  }

  render::Vec vec2;
  ASSERT_FLOAT_EQ(vec2.x(), 0.F);
  ASSERT_FLOAT_EQ(vec2.y(), 0.F);
  ASSERT_FLOAT_EQ(vec2.z(), 0.F);
  ASSERT_FLOAT_EQ(vec2.norm(), 0.F);
}

TEST(Vec, plus) {
  render::Vec vec1(3, 1, 4);
  render::Vec vec2(1, 5, 4);
  const auto vec = vec1 + vec2;

  ASSERT_FLOAT_EQ(vec.x(), 4.F);
  ASSERT_FLOAT_EQ(vec.y(), 6.F);
  ASSERT_FLOAT_EQ(vec.z(), 8.F);
}

TEST(Vec, minus) {
  render::Vec vec1(3, 1, 4);
  render::Vec vec2(1, 5, 4);
  const auto vec = vec1 - vec2;

  ASSERT_FLOAT_EQ(vec.x(), 2.F);
  ASSERT_FLOAT_EQ(vec.y(), -4.F);
  ASSERT_FLOAT_EQ(vec.z(), 0.F);
}

TEST(Vec, mult) {
  render::Vec vec1(3, 1, 4);
  const auto vec = vec1 * 10;

  ASSERT_FLOAT_EQ(vec.x(), 30.F);
  ASSERT_FLOAT_EQ(vec.y(), 10.F);
  ASSERT_FLOAT_EQ(vec.z(), 40.F);
}

TEST(Vec, dev) {
  render::Vec vec1(3, 1, 4);
  const auto vec = vec1 / 10;

  ASSERT_FLOAT_EQ(vec.x(), .3F);
  ASSERT_FLOAT_EQ(vec.y(), .1F);
  ASSERT_FLOAT_EQ(vec.z(), .4F);
}

TEST(Vec, dot) {
  render::Vec vec1(3, 1, 4);
  render::Vec vec2(1, 5, 4);
  ASSERT_FLOAT_EQ(vec1.dot(vec2), 24.F);
  ASSERT_FLOAT_EQ(vec2.dot(vec1), 24.F);
}
