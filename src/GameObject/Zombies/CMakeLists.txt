cmake_minimum_required(VERSION 3.16)

add_library(
    Zombies
    STATIC
    Zombies.cpp
)

target_link_libraries(
  GameObject
  Framework
)