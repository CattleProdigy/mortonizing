cmake_minimum_required(VERSION 3.14)
project(mortonizing CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("-Wall" "-Wextra" "-march=native" "-mtune=native")

include(FetchContent)

FetchContent_Declare(
    libmorton
    GIT_REPOSITORY "https://github.com/Forceflow/libmorton"
    GIT_TAG "4629fcb68d3dd262d30fac51ea212a24eb74bada"
)

FetchContent_MakeAvailable(libmorton)

add_subdirectory(lib)
#add_subdirectory(bin)
