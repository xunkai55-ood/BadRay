include_directories(include)

set(SRC_LIST
    badray.cpp
    scene.cpp
    shape/sphere.cpp
)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(badray ${SRC_LIST})

