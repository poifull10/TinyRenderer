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
  ~RenderEngine() = default;

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
          auto ray = camera.ray(w, h);
          RGB rgb;
          Albedo albedo;
          while (true) {
            float previousDistance = std::numeric_limits<float>::max();
            std::optional<Ray> tmpRay;
            for (const auto& object : objects_) {
              const auto interactionResult = object->interact(ray);
              if (!interactionResult.has_value()) {
                continue;
              }
              const auto [interactedRay, reflection] = interactionResult.value();
              const auto currentDistance = (interactedRay.origin() - ray.origin()).norm();
              if (currentDistance < previousDistance) {
                previousDistance = currentDistance;
                tmpRay = interactedRay;
                if (std::holds_alternative<Albedo>(reflection)) {
                  albedo = albedo * std::get<Albedo>(reflection);
                } else if (std::holds_alternative<RGB>(reflection)) {
                  rgb = std::get<RGB>(reflection);
                  tmpRay = std::nullopt;
                }
              }
            }
            if (!tmpRay.has_value()) {
              break;
            }
            ray = std::move(tmpRay.value());
          }
          camera.image(w, h) = rgb * albedo;
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
