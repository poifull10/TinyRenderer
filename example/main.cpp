#include <camera.h>
#include <engine.h>
#include <image.h>
#include <light.h>
#include <ray.h>
#include <sphere.h>
#include <vec.h>

#include <memory>

int main(int argc, char** argv) {
  std::cout << "rendering ... " << std::endl;
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::Sphere>(1.F, render::Vec(0, 0, 10)));
  renderEngine.add(std::make_unique<render::Sphere>(0.5F, render::Vec(.3F, .3F, 1.5F)));
  renderEngine.add(std::make_unique<render::ParallelLight>(render::RGB{255, 255, 255}, render::Ray({0, 0, -10}, render::Vec(0, 0, 1).normalize())));
  renderEngine.addCamera(std::move(render::Camera(300, 300)));
  const auto images = renderEngine.render();
  images.front().save("sphere.png");
  std::cout << "rendering is done! " << std::endl;
}
