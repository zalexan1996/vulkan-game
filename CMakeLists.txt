cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)

add_compile_options(-lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi)

project(vulkan-game)

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)


file (GLOB_RECURSE vg_sources CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE vg_headers CONFIGURE_DEPENDS "include/*.h")

set (vg_include_dirs "")
foreach (_headerFile ${vg_headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND vg_include_dirs ${_dir})
endforeach()
list (REMOVE_DUPLICATES vg_include_dirs)

add_executable(vulkan-game ${vg_sources})
target_include_directories(vulkan-game PRIVATE ${vg_include_dirs})

target_link_libraries(vulkan-game glfw Vulkan::Vulkan)