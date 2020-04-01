cmake_minimum_required(VERSION 3.10)
project(datastruct)
#the version number
# no use

#set build model
SET(CMAKE_BUILD_TYPE Debug)
#set project name
SET(PROJECT_NAME DataStruct)

#set execute path
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set library path
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME}
    src/datastruct.cpp 
)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/utils.cpp
    test/queue_test.cpp test/tree_test.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/test/include
)
target_compile_options(${PROJECT_NAME}
    PRIVATE
    -ggdb
    -Wall
    -O0
    -std=c++11
)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
)


