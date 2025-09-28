cmake_minimum_required(VERSION 3.10)

set(PROJECT skyline)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(${PROJECT} VERSION 1.0)

set(SRCDIR src)
set(INCDIRS include)
set(SOURCES
  ${SRCDIR}/main.c
  ${SRCDIR}/engine/physics.c
  ${SRCDIR}/engine/time.c
)

include_directories(${INCDIRS})
link_libraries(SDL2 m)

add_executable(${PROJECT} ${SOURCES})
