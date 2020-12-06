#include <engine.h>
#include <gtest/gtest.h>
#include <image.h>
#include <parallel_light.h>
#include <sphere.h>

TEST(RenderEngine, renderObject) {
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::Sphere>(5.F, render::Vec(0, 0, 10)));
  renderEngine.addCamera(std::move(render::Camera(101, 101)));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_EQ(images.front()(0, 0), render::RGB());
  ASSERT_EQ(images.front()(50, 50), render::RGB());
}

TEST(RenderEngine, renderLight) {
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::ParallelLight>(render::RGB{255, 255, 255}, render::Ray({0, 0, 1}, {0, 0, -1})));
  renderEngine.addCamera(std::move(render::Camera(101, 101)));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_EQ(images.front()(0, 0), render::RGB(255, 255, 255));
}

TEST(RenderEngine, render) {
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::ParallelLight>(render::RGB{255, 255, 255}, render::Ray({0, 0, -10}, render::Vec(0, 0, 1).normalize())));
  renderEngine.add(std::make_unique<render::Sphere>(1.F, render::Vec(0, 0, 10)));
  renderEngine.addCamera(std::move(render::Camera(300, 300)));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_EQ(images.front()(0, 0), render::RGB());
  ASSERT_NE(images.front()(150, 150), render::RGB());
}
