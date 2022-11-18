# CMakeList.txt : CMake project for Perception, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Perception")

# Add source to this project's executable.
add_executable (Perception "Perception.cpp" "Perception.h" "Headers/Perception_Elements/Neural_Node.h" "CPP/Perception_Elements/Neural_Node.cpp" "Headers/Utilities/Root.h" "CPP/Utilities/Root.cpp" "CPP/Perception_Elements/Layer.cpp" "Headers/Perception_Elements/Layer.h" "CPP/Perception_Elements/Weight.cpp" "CPP/Perception_Elements/Input.cpp" "Headers/Perception_Elements/Weight.h" "Headers/Perception_Elements/Input.h")

target_include_directories(${PROJECT_NAME} PUBLIC 
      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Perception_Elements
      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Utilities
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Perception PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
