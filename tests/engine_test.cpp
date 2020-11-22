#include <engine.h>
#include <gtest/gtest.h>
#include <image.h>

TEST(RenderEngine, render) {
  render::RenderEngine renderEngine;
  renderEngine.add(render::Sphere(3.F, render::Vec(0, 0, 10)));
  renderEngine.add(render::Camera(1001, 1001));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_EQ(images.front()(0, 0), render::RGB(0, 0, 0));
  ASSERT_NE(images.front()(500, 500), render::RGB(0, 0, 0));
}
