#include <camera.h>
#include <image.h>
#include <ray.h>
#include <sphere.h>
#include <vec.h>

int main(int argc, char** argv) {
  render::Camera camera(1001, 1001);
  render::Sphere sphere(3.F, render::Vec(0, 0, 10));
  std::cout << "rendering ... " << std::endl;
  for (auto h = 0; h < camera.height(); h++) {
    for (auto w = 0; w < camera.width(); w++) {
      const auto ray = camera.ray(w, h);
      if (sphere.hit(ray)) {
        camera.image(w, h) = render::RGB(255, 0, 255);
      }
    }
  }
  camera.save("sphere.png");
  std::cout << "rendering is done! " << std::endl;
}
