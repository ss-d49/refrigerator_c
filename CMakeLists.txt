cmake_minimum_required(VERSION 3.17)
project(untitledc C)

set(CMAKE_C_STANDARD 11)

add_executable(untitledc main.c ObjectIO.c fridgeInventory.c)