add_library(DS_Lib DS_Graph.cpp DS_Read.cpp)
target_link_directories(DS_Lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})