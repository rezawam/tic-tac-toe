cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(tic-tac-toe main.cpp test.cpp)
link_directories(/usr/include/)
target_link_libraries(tic-tac-toe ${CURSES_LIBRARIES})