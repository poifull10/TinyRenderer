add_executable(
  TRendererTest
  main.cpp
  image_test.cpp
  camera_test.cpp
  vec_test.cpp
  ray_test.cpp
)

target_include_directories(TRendererTest
  PUBLIC
  $<INSTALL_INTERFACE:src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(TRendererTest gtest TinyRenderer::TinyRenderer)
