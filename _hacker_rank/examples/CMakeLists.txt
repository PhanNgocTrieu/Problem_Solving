add_executable(arrayProblems main.cpp)

target_compile_options(arrayProblems PRIVATE -std=c++11 -Wall)

target_link_libraries(arrayProblems hackerRank ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(arrayProblems PRIVATE ../include)
