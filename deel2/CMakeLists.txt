cmake_minimum_required(VERSION 3.0.0)
project(Opdracht4-website VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Opdracht4-website http_server.c)

target_link_libraries(Opdracht4-website gpiod)