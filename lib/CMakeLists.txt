add_library(mortonizinglib SHARED
    voxel_grid.cpp
)

target_link_libraries(mortonizinglib PRIVATE libmorton::libmorton)
target_include_directories(mortonizinglib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

#add_subdirectory(test)
#add_subdirectory(bin)
