cmake_minimum_required(VERSION 3.10)
project(Skyline C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Incluir headers
include_directories(include)

# Archivos fuente
file(GLOB SOURCES
    src/main.c
    src/engine/collision.c
    src/engine/physics.c
    src/engine/time.c
)

add_executable(skyline ${SOURCES})

# Buscar SDL2
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(skyline mingw32 SDL2main ${SDL2_LIBRARIES})
else()
    message(FATAL_ERROR "SDL2 not found!")
endif()

