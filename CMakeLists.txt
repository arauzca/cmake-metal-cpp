# Enable Metal-cpp for macOS13.
option(ENABLE_BETA "Target macOS13." OFF)

# Use the MakeSingleHeader.py script to generate a single-header file.
option(MAKE_METAL_SINGLE_HEADER
       "Use metal-cpp as a single-header include in your project." OFF)

option(INCLUDE_APPKIT_EXTENSION "Include the AppKit extension from metal-cpp-extensions."
       ON)

option(INCLUDE_METALKIT_EXTENSION
       "Include the MetalKit extension from metal-cpp-extensions." ON)

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(
    cmake-metal-cpp
    VERSION 1.0.0
    DESCRIPTION ""
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if(APPLE)
    set(CMAKE_MACOSX_RPATH OFF)
endif()

if(ENABLE_BETA)
    set(METAL_CPP_DIR "${CMAKE_CURRENT_LIST_DIR}/metal-cpp-beta")
else()
    set(METAL_CPP_DIR "${CMAKE_CURRENT_LIST_DIR}/metal-cpp")
endif()

set(METAL_CPP_EXTENSIONS_DIR "${CMAKE_CURRENT_LIST_DIR}/metal-cpp-extensions")

if(MAKE_METAL_SINGLE_HEADER)
    add_compile_definitions(SINGLE_METAL_HEADER)

    # Python required to run the metal-cpp/SingleHeader/MakeSingleHeader.py
    find_package(Python3 REQUIRED COMPONENTS Interpreter)

    set(MAKE_SINGLE_HEADER_SCRIPT_PY "${METAL_CPP_DIR}/SingleHeader/MakeSingleHeader.py")
    if(EXISTS ${MAKE_SINGLE_HEADER_SCRIPT_PY})
        list(APPEND HEADERS "${METAL_CPP_DIR}/Foundation/Foundation.hpp"
             "${METAL_CPP_DIR}/QuartzCore/QuartzCore.hpp"
             "${METAL_CPP_DIR}/Metal/Metal.hpp")

        if(INCLUDE_APPKIT_EXTENSION)
            file(COPY "${METAL_CPP_EXTENSIONS_DIR}/AppKit"
                 DESTINATION "${METAL_CPP_DIR}/")
            list(APPEND HEADERS "${METAL_CPP_DIR}/AppKit/AppKit.hpp")
        endif()

        if(INCLUDE_METALKIT_EXTENSION)
            file(COPY "${METAL_CPP_EXTENSIONS_DIR}/MetalKit"
                 DESTINATION "${METAL_CPP_DIR}/")
            list(APPEND HEADERS "${METAL_CPP_DIR}/MetalKit/MetalKit.hpp")
        endif()

        # Run the python script.
        execute_process(
            COMMAND python3 ${MAKE_SINGLE_HEADER_SCRIPT_PY} ${HEADERS}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            RESULT_VARIABLE EXIT_CODE
            OUTPUT_QUIET)
    endif()
endif()

add_library(metal-cpp "${CMAKE_CURRENT_LIST_DIR}/metal.cpp")

list(APPEND TARGET_LINK_LIBRARIES "-framework Metal" "-framework Foundation"
     "-framework QuartzCore")

if(INCLUDE_APPKIT_EXTENSION)
    add_compile_definitions(INCLUDE_APPKIT_EXTENSION)
    list(APPEND INCLUDE_EXTENSION INCLUDE_APPKIT_EXTENSION)
    list(APPEND TARGET_LINK_LIBRARIES "-framework AppKit")
endif()

if(INCLUDE_METALKIT_EXTENSION)
    add_compile_definitions(INCLUDE_METALKIT_EXTENSION)
    list(APPEND INCLUDE_EXTENSION INCLUDE_METALKIT_EXTENSION)
    list(APPEND TARGET_LINK_LIBRARIES "-framework MetalKit")
endif()

if(${MAKE_METAL_SINGLE_HEADER} AND EXISTS "${METAL_CPP_DIR}/SingleHeader/Metal.hpp")
    set(METAL_CPP_INCLUDE_DIRS "${METAL_CPP_DIR}/SingleHeader")

    # Remove unnecessary  headers.
    execute_process(
        COMMAND python3 "${CMAKE_CURRENT_LIST_DIR}/scripts/RemoveUselessImports.py"
                "${METAL_CPP_DIR}/SingleHeader/Metal.hpp"
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        RESULT_VARIABLE EXIT_CODE2
        OUTPUT_QUIET)

    if(NOT ${EXIT_CODE1} EQUAL 0 OR NOT ${EXIT_CODE2} EQUAL 0)
        message(
            FATAL_ERROR "An error has ocurred: the script did not successfully complete.")
    else()
        message(STATUS "Single header created: ${METAL_CPP_DIR}/SingleHeader/Metal.hpp")
    endif()

else(NOT ${MAKE_METAL_SINGLE_HEADER})
    list(APPEND METAL_CPP_INCLUDE_DIRS ${METAL_CPP_DIR})
    if(INCLUDE_APPKIT_EXTENSION OR INCLUDE_METALKIT_EXTENSION)
        list(APPEND METAL_CPP_INCLUDE_DIRS ${METAL_CPP_EXTENSIONS_DIR})
    endif()

endif()

if(EXISTS "${METAL_CPP_DIR}/AppKit")
    file(REMOVE_RECURSE "${METAL_CPP_DIR}/AppKit")
endif()

if(EXISTS "${METAL_CPP_DIR}/MetalKit")
    file(REMOVE_RECURSE "${METAL_CPP_DIR}/MetalKit")
endif()

target_include_directories(metal-cpp PUBLIC ${METAL_CPP_INCLUDE_DIRS})
target_link_libraries(metal-cpp ${TARGET_LINK_LIBRARIES})
