cmake_minimum_required(VERSION 3.21)
project(PathVisualizer LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(PathVisualizer 
src/main.cpp
src/Grid.cpp
src/Grid.hpp
src/GridBox.cpp
src/GridBox.hpp
src/GridBoxBehaviour.hpp
src/GridBoxBehaviour.cpp
)
target_link_libraries(PathVisualizer PRIVATE sfml-graphics)
target_compile_features(PathVisualizer PRIVATE cxx_std_17)

if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET PathVisualizer POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PathVisualizer> $<TARGET_FILE_DIR:PathVisualizer> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS PathVisualizer)