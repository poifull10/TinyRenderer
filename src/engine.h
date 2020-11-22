#pragma once
#include "camera.h"
#include "image.h"
#include "sphere.h"
#include "vec.h"

namespace render {
class RenderEngine {
 public:
  RenderEngine() = default;

  void add(Camera&& camera) {
    cameras_.emplace_back(camera);
  }

  void add(Sphere&& object) {
    objects_.emplace_back(object);
  }

  std::vector<Image> render() const {
    std::vector<Image> images;
    for (auto camera : cameras_) {
      for (auto h = 0; h < camera.height(); h++) {
        for (auto w = 0; w < camera.width(); w++) {
          const auto ray = camera.ray(w, h);
          if (objects_.front().hit(ray)) {
            camera.image(w, h) = RGB(255, 0, 255);
          }
        }
      }
      images.emplace_back(camera.image());
    }
    return images;
  }

 private:
  std::vector<Sphere> objects_;
  std::vector<Camera> cameras_;
};

}  // namespace render
