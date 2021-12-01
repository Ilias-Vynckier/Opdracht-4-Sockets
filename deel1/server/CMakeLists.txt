cmake_minimum_required(VERSION 3.0.0)
project(Opdracht4-server VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Opdracht4-server main.c)
include_directories(../../tlpi-dist/sockets)

#make absolute path
get_filename_component(TLPI_LIB "/home/pi/embed2/tlpi-dist/libtlpi.a" ABSOLUTE)
#add the libraries
target_link_libraries(Opdracht4-server ${TLPI_LIB} gpiod)
target_link_libraries(Opdracht4-server gpiod)
#make absolute path
get_filename_component(TLPI_INCLUDE "/home/pi/embed2/tlpi-dist/lib/" ABSOLUTE)
#add include directories
target_include_directories(Opdracht4-server PRIVATE ${TLPI_INCLUDE})

#target_link_libraries(Opdracht4-client tlpi-dist)
