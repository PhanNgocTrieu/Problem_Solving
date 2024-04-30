add_executable(leetCode main.cpp)

target_compile_options(leetCode PRIVATE -std=c++11 -Wall)

target_link_libraries(leetCode leetcode ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(leetCode PRIVATE ../include)
