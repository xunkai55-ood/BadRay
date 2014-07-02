include_directories(include)

set(SRC_LIST
    badray.cpp
    camera.cpp
    scene.cpp
    tracer.cpp
    shape/sphere.cpp
    surface/regular_surface.cpp
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(badray ${SRC_LIST})

