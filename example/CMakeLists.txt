add_executable(
  example
  main.cpp
)

target_include_directories(example
  PUBLIC
  $<INSTALL_INTERFACE:src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(example TinyRenderer::TinyRenderer)
