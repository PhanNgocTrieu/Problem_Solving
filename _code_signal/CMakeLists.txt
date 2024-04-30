include_directories(_include)

set(CODESIGNAL_HDR  _include/Intro.h
                    _include/Core.h
                    _include/supportedFunction.h
)

set(CODESIGNAL_SRC  _src/Core.cpp
)

# After setting we need to generate the library by this below command
add_library(codeSignal STATIC ${CODESIGNAL_HDR} ${CODESIGNAL_SRC})

target_compile_options(codeSignal PRIVATE -std=c++14 -Wall)

# add_subdirectory(Intro)
# add_subdirectory(TheCore)
add_subdirectory(_examples)