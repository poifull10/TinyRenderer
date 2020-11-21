#include <camera.h>
#include <image.h>
#include <ray.h>
#include <sphere.h>
#include <vec.h>

int main(int argc, char** argv) {
  render::Camera camera(1001, 1001);
  render::Sphere sphere(3.F, render::Vec(0, 0, 10));

  std::cout << "rendering ... " << std::endl;
  for (auto h = 0; h < camera.image().height(); h++) {
    for (auto w = 0; w < camera.image().width(); w++) {
      const auto ray = camera.ray(w, h);
      if (sphere.hit(ray)) {
        camera.image()(w, h) = render::RGB(255, 0, 255);
      } else {
        camera.image()(w, h) = render::RGB(0, 0, 0);
      }
    }
  }

  camera.image().save("sphere.png");
  std::cout << "rendering is done! " << std::endl;
}
