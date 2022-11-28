# CMakeList.txt : CMake project for Perception, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(Project_Test_Name "Perception_Test")

project ("Perception")

# Add source to this project's executable.
add_executable (Perception "Perception.cpp" "Testing/Testing_Layer.cpp" "Perception.h" "Headers/Perception_Elements/Neural_Node.h" "CPP/Perception_Elements/Neural_Node.cpp" "Headers/Utilities/Root.h" "CPP/Utilities/Root.cpp" "CPP/Perception_Elements/Layer.cpp" "Headers/Perception_Elements/Layer.h" "CPP/Perception_Elements/Weight.cpp" "CPP/Perception_Elements/Input.cpp" "Headers/Perception_Elements/Weight.h" "Headers/Perception_Elements/Input.h" "Headers/Utilities/Perception_Element_Display.h" "CPP/Utilities/Perception_Element_Display.cpp" "CPP/Perception_Elements/Perception_Element.cpp" "Headers/Perception_Elements/Perception_Element.h" "CPP/Utilities/Enums.cpp" "Headers/Utilities/Enums.h")

target_include_directories(${PROJECT_NAME} PUBLIC 
      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Perception_Elements
      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Utilities
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Perception PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(${Project_Test_Name} "Testing/Testing_Layer.cpp" "Perception.cpp" "Perception.h" "Headers/Perception_Elements/Neural_Node.h" "CPP/Perception_Elements/Neural_Node.cpp" "Headers/Utilities/Root.h" "CPP/Utilities/Root.cpp" "CPP/Perception_Elements/Layer.cpp" "Headers/Perception_Elements/Layer.h" "CPP/Perception_Elements/Weight.cpp" "CPP/Perception_Elements/Input.cpp" "Headers/Perception_Elements/Weight.h" "Headers/Perception_Elements/Input.h" "Headers/Utilities/Perception_Element_Display.h" "CPP/Utilities/Perception_Element_Display.cpp" "CPP/Perception_Elements/Perception_Element.cpp" "Headers/Perception_Elements/Perception_Element.h" "CPP/Utilities/Enums.cpp" "Headers/Utilities/Enums.h")

#target_include_directories(${Project_Test_Name} PUBLIC 
#      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Perception_Elements
#      ${CMAKE_CURRENT_SOURCE_DIR}/Headers/Utilities
#)


target_link_libraries(${PROJECT_NAME} gtest_main)

enable_testing()
# TODO: Add tests and install targets if needed.


#include(GoogleTest)
#gtest_discover_tests(${Project_Test_Name} ) 


add_test(NAME ${Project_Test_Name} COMMAND ${Project_Test_Name} )
