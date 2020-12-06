#pragma once
#include <optional>
#include <tuple>

#include "object.h"

namespace render {
class ParallelLight : public RenderObject {
 public:
  ParallelLight(const RGB& rgb, const Ray& ray) : source_(rgb), ray_(ray) {}
  virtual ~ParallelLight() = default;
  std::optional<RayInteractionResult> interact(const Ray& ray) const override {
    if (ray.direction().dot(ray_.direction()) < 0.F) {
      return RayInteractionResult{
          ray_,
          source_};
    }
    return std::nullopt;
  }

 private:
  RGB source_;
  Ray ray_;
};
}  // namespace render
