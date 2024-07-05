cmake_minimum_required(VERSION 3.16)

add_library(
    Projectile
    STATIC
    Projectile.cpp
)

target_link_libraries(
  GameObject
  Framework
)