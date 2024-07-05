cmake_minimum_required(VERSION 3.16)

add_library(
  Seeds
  STATIC
  Seeds.cpp
)

target_link_libraries(
  GameObject
  Framework
)