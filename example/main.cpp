#include <camera.h>
#include <engine.h>
#include <image.h>
#include <ray.h>
#include <sphere.h>
#include <vec.h>

#include <memory>

int main(int argc, char** argv) {
  std::cout << "rendering ... " << std::endl;
  render::RenderEngine renderEngine;
  renderEngine.add(std::make_unique<render::Sphere>(3.F, render::Vec(0, 0, 10)));
  renderEngine.addCamera(std::move(render::Camera(1000, 1000)));
  std::vector<render::Image> images = renderEngine.render();
  images.front().save("sphere.png");
  std::cout << "rendering is done! " << std::endl;
}
