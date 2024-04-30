# find_package(Boost 1.69 REQUIRED COMPONENTS log thread)
include_directories(include)

set(LEETCD_HDR  include/easyLevel.h
                include/common.h
                include/data.h
                include/hardLevel.h
                include/mediumLevel.h
)

set(LEETCD_SRC  src/easyLevel.cpp
                src/hardLevel.cpp
                src/mediumLevel.cpp
)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
# After setting we need to generate the library by this below command
add_library(leetcode STATIC ${LEETCD_HDR} ${LEETCD_SRC})

target_compile_options(leetcode PRIVATE -std=c++11 -Wall)
# target_link_libraries(Boost::log Boost::thread ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(examples)
