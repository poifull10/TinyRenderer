#include <engine.h>
#include <gtest/gtest.h>
#include <image.h>
#include <sphere.h>

TEST(RenderEngine, render) {
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::Sphere>(5.F, render::Vec(0, 0, 10)));
  renderEngine.addCamera(std::move(render::Camera(1001, 1001)));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_EQ(images.front()(0, 0), render::RGB(0, 0, 0));
  ASSERT_NE(images.front()(500, 500), render::RGB(0, 0, 0));
}
