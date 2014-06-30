include_directories(${PROJECT_SOURCE_DIR}/include)
set(SRCS 
    badray.cpp
)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(badray ${SRCS})

