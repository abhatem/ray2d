cmake_minimum_required(VERSION 2.8)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


option(buildtest "build executable" ON)

file(GLOB RAY2D_SRC 
  "include/*.h"
  "src/*.cpp"
  )

list(REMOVE_ITEM RAY2D_SRC "src/main.cpp")

file(GLOB TEST_SRC
  "include/*.h"
  "src/*.cpp"
  )

include_directories(include)

if(buildtest)

  add_executable (prog ${TEST_SRC})  
endif(buildtest)



option(sharedbuild "shared build" ON)
if(sharedbuild)
  add_library(ray2d SHARED ${RAY2D_SRC})
else(sharedbuild)
  add_library(ray2d STATIC ${RAY2D_SRC})
endif(sharedbuild)
# add_library(ray2d STATIC ${RAY2D_SRC})
