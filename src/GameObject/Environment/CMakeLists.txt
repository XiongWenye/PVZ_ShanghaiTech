cmake_minimum_required(VERSION 3.16)

add_library(
  Environment
  STATIC
  Environment.cpp
)

target_link_libraries(
  GameObject
  Framework
)

