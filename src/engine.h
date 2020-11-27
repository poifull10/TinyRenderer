#pragma once
#include <memory>

#include "camera.h"
#include "image.h"
#include "object.h"
#include "vec.h"

namespace render {
class RenderEngine {
 public:
  RenderEngine() = default;

  void addCamera(Camera&& camera) {
    cameras_.emplace_back(camera);
  }

  void add(std::unique_ptr<RenderObject>&& object) {
    objects_.emplace_back(std::move(object));
  }

  std::vector<Image> render() {
    std::vector<Image> images;
    for (auto& camera : cameras_) {
      for (auto h = 0; h < camera.height(); h++) {
        for (auto w = 0; w < camera.width(); w++) {
          std::optional<Ray> ray = camera.ray(w, h);
          RGB rgb;
          while (ray.has_value()) {
            float previousDistance = std::numeric_limits<float>::max();
            RGB tmpRGB;
            std::optional<Ray> tmpRay;
            for (const auto& object : objects_) {
              const auto interactionResult = object->interact(ray.value());
              if (!interactionResult.has_value()) {
                continue;
              }
              const auto [interactedRay, interactedRGB, interactedDecay] = *interactionResult;
              const auto currentDistance = (interactedRay.origin() - ray.value().origin()).norm();
              if (currentDistance < previousDistance) {
                previousDistance = currentDistance;
                tmpRGB = interactedDecay * interactedRGB;
                tmpRay = interactedRay;
              }
            }
            rgb += tmpRGB;
            if (!tmpRay.has_value()) {
              break;
            }
            ray = std::move(tmpRay.value());
            continue;
          }
          camera.image(w, h) = rgb;
        }
      }
      images.emplace_back(camera.image());
    }
    return images;
  }

 private:
  std::vector<std::unique_ptr<RenderObject>> objects_;
  std::vector<Camera> cameras_;
};

}  // namespace render
