cmake_minimum_required(VERSION 3.23)
project(openGLPlayground)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)
find_package(glfw3 3.3 REQUIRED)



include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
include_directories("include")



add_executable(openGLPlayground simple-window.cpp)
target_link_libraries(openGLPlayground ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} OpenGL::GL glfw)

add_executable(openGLPlayground-triangle-opengles triangle-opengles.cpp)
target_link_libraries(openGLPlayground-triangle-opengles ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} OpenGL::GL glfw )


add_custom_target(copy_shaders ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/shaders
        ${PROJECT_BINARY_DIR}/shaders
        COMMENT "Copying shaders into binary directory")

add_dependencies(openGLPlayground copy_shaders)
add_dependencies(openGLPlayground-triangle-opengles copy_shaders)


