cmake_minimum_required(VERSION 3.0.0)
project(Opdracht4-client VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Opdracht4-client main.c)
include_directories(../tlpi-dist/sockets)

#make absolute path
get_filename_component(TLPI_LIB "/home/pi/embed2/tlpi-dist/libtlpi.a" ABSOLUTE)
#add the libraries
target_link_libraries(Opdracht4-client ${TLPI_LIB})
#make absolute path
get_filename_component(TLPI_INCLUDE "/home/pi/embed2/tlpi-dist/lib/" ABSOLUTE)
#add include directories
target_include_directories(Opdracht4-client PRIVATE ${TLPI_INCLUDE})

#target_link_libraries(Opdracht4-client tlpi-dist)
