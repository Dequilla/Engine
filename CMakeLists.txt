# CMakeList.txt : CMake project for Games Engine, include source and define
# project specific logic here.
cmake_minimum_required (VERSION 3.8)

project(Engine)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # 64 bits
    set(ARCHITECTURE x64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    # 32 bits
    set(ARCHITECTURE x86)
endif()
message("Architecture: " ${ARCHITECTURE})

# Enable c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Paths
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(EXTERNALS "${ROOT_DIR}/External")

if(WIN32)
    set(PLATFORM "Win32")

    ################
    # SDL2
    set(TEMP_FOLDER ${EXTERNALS}/SDL2-2.0.14/lib/${ARCHITECTURE}/)
    set(SDL2_LIBRARY ${TEMP_FOLDER}/SDL2.lib ${TEMP_FOLDER}/SDL2main.lib)
    set(EXTERNAL_DLLS ${EXTERNAL_DLLS} "${TEMP_FOLDER}/SDL2.dll")
    include_directories(${EXTERNALS}/SDL2-2.0.14/include)

elseif(UNIX)
    set(PLATFORM "Unix")
    message("WARNING: Unix is not yet implemented in CMake")
endif()
message("Platform: " ${PLATFORM})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# External libraries
set(EXTERNAL_LIBRARIES 
        ${SDL2_LIBRARY}
        ${OPENGL_LIBRARIES}
)

# Include sub-projects.
add_subdirectory ("Games Engine")
