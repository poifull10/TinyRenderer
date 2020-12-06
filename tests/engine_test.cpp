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
  ASSERT_NE(images.front()(0, 0), render::RGB(0, 0, 0));
  ASSERT_EQ(images.front()(50, 50), render::RGB(0, 0, 0));
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
  renderEngine.add(std::make_unique<render::ParallelLight>(render::RGB{255, 255, 255}, render::Ray({0, 0, 100}, render::Vec(0, 0, 1).normalize())));
  renderEngine.add(std::make_unique<render::Sphere>(3.F, render::Vec(0, 0, 10)));
  renderEngine.addCamera(std::move(render::Camera(1001, 1001)));
  std::vector<render::Image> images = renderEngine.render();
  ASSERT_EQ(images.size(), 1);
  ASSERT_NE(images.front()(0, 0), render::RGB(0, 0, 0));
  ASSERT_EQ(images.front()(50, 50), render::RGB(255, 255, 255));
}
