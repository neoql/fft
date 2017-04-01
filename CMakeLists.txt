cmake_minimum_required(VERSION 3.6)
project(fft)

if(UNIX)
    LINK_LIBRARIES("m")
endif()

set(EXE_SRC main.c)
set(LIB_SRC fft.c complex.c fft.h complex.h)

add_library(libfft SHARED ${LIB_SRC})
set_target_properties(libfft PROPERTIES OUTPUT_NAME "fft")

add_executable(fft ${EXE_SRC})
target_link_libraries(fft libfft)
