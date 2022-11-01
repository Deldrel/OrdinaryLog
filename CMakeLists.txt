cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME template)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
add_subdirectory(vendors/sfml)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES src/*.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE ${PROJECT_SOURCE_DIR}/vendors/sfml/include/
)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} glu32 opengl32)