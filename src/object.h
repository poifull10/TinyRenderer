#pragma once
#include <optional>
#include <tuple>

#include "image.h"
#include "ray.h"

namespace render {
struct RayInteractionResult {
  enum class InteractionType {
    LIGHT = 0,
    OBJECT
  };
  InteractionType interactionType;
  Ray interactedRay;
  RGB color;
  float decay;
};

class RenderObject {
 public:
  RenderObject() = default;
  virtual ~RenderObject() = default;
  virtual std::optional<RayInteractionResult> interact(const Ray& ray) const = 0;
};
}  // namespace render
