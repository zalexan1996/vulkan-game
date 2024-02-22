cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi)


include_directories(src)
project(vulkan-game)

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost REQUIRED COMPONENTS system)

file (GLOB_RECURSE vg_sources CONFIGURE_DEPENDS "src/*.cc")

add_executable(vulkan-game
    ${vg_sources}
)

target_include_directories(vulkan-game PUBLIC
    ${Boost_INCLUDE_DIRS}
)
target_link_libraries(vulkan-game glfw Vulkan::Vulkan ${Boost_LIBRARIES})