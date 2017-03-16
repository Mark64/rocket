# by Mark Hill
# using tutorial from https://www.johnlamp.net/cmake-tutorial-4-libraries-and-subdirectories.html

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# flight controller test section
project("Rocket Value Calculator")

# stop the stupid insource builds
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
	message(FATAL_ERROR "In-source builds not allowed, use the Makefile wrapper")
endif()


set(ExectuableName LOL)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/rocketCalc")

add_subdirectory(rocketCalc)

add_executable(${ExectuableName} rocketCalc/rocketCalc.cpp)
target_link_libraries(${ExectuableName} rocketCalc)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL "Apparently this shows CMake has been configured once ????")
