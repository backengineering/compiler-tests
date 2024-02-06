cmake_minimum_required(VERSION 3.12)
project(compiler-tests)

# Set the source files
file(GLOB SOURCES "src/*.c")

# Iterate over each source file and create an EXE
foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${FILE_NAME} ${SOURCE_FILE})
	target_include_directories(${FILE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)
    target_compile_options(${FILE_NAME} PRIVATE "/GL" "/GS")
    target_link_options(${FILE_NAME} PRIVATE "/DEBUG:FULL")
endforeach()

STRING (REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")