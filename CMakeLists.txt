cmake_minimum_required(VERSION 3.15)

project(Snake)

file(GLOB file_SRC
      CONFIGURE_DEPENDS
     "include/*.h"
     "src/*.cpp"
)

add_executable(main ${file_SRC})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 17)
endif()