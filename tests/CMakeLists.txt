add_executable(
  TRendererTest
  main.cpp
)

target_include_directories(TRendererTest
  PUBLIC
  $<INSTALL_INTERFACE:src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(TRendererTest gtest TinyRenderer::TinyRenderer)
