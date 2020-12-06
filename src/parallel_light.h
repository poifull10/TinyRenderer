#pragma once
#include <optional>
#include <tuple>

#include "object.h"

namespace render {
class ParallelLight : public RenderObject {
 public:
  ParallelLight(const RGB& rgb, const Vec& direction) : source_(rgb), direction_(direction) {}
  virtual ~ParallelLight() = default;
  std::optional<RayInteractionResult> interact(const Ray& ray) const override {
    return RayInteractionResult{
        RayInteractionResult::InteractionType::LIGHT,
        Ray(Vec(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max()), direction_),
        source_,
        1.F};
  }

 private:
  RGB source_;
  Vec direction_;
};
}  // namespace render
