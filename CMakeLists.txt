cmake_minimum_required(VERSION 3.22)

project(LIB_H743_FC
    VERSION 0.1.0
    LANGUAGES C
)

# Chi bat warning mac dinh khi build thu vien doc lap,
# khong ep len project cha khi dung add_subdirectory().
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(LIB_H743_FC_IS_TOP_LEVEL ON)
else()
    set(LIB_H743_FC_IS_TOP_LEVEL OFF)
endif()

option(LIB_H743_FC_WARNINGS "Enable extra compiler warnings" ${LIB_H743_FC_IS_TOP_LEVEL})

# ---------------------------------------------------------------------------
# Library
# ---------------------------------------------------------------------------
add_library(lib_h743_fc STATIC
    Src/led.c
)
add_library(LIB_H743_FC::lib ALIAS lib_h743_fc)

target_include_directories(lib_h743_fc
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

target_compile_features(lib_h743_fc PUBLIC c_std_11)
set_target_properties(lib_h743_fc PROPERTIES
    C_EXTENSIONS ON
)

if(LIB_H743_FC_WARNINGS)
    target_compile_options(lib_h743_fc PRIVATE
        $<$<C_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wshadow -Wdouble-promotion>
    )
endif()
