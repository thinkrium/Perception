# CMakeList.txt : CMake project for Cognition, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Cognition")

# Add source to this project's executable.
add_executable (Cognition "Cognition.cpp" "Cognition.h" "Headers/Neural_Node.h" "CPP/Neural_Node.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Headers)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cognition PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
