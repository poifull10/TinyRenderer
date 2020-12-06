#pragma once
#include <optional>
#include <tuple>
#include <variant>

#include "image.h"
#include "material.h"
#include "ray.h"

namespace render {

struct RayInteractionResult {
  Ray interactedRay;
  std::variant<Albedo, RGB> color;  // Object or LightSource
};

class RenderObject {
 public:
  RenderObject() = default;
  virtual ~RenderObject() = default;
  virtual std::optional<RayInteractionResult> interact(const Ray& ray) const = 0;
};
}  // namespace render
