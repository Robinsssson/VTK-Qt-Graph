cmake_minimum_required(VERSION 3.15)
project(test)
add_subdirectory(include/DP_Lib)
add_subdirectory(include/DS_Lib)
add_executable(${PROJECT_NAME}  TEST/test.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC DP_Lib DS_Lib)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR} )