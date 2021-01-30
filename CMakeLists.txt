cmake_minimum_required(VERSION 3.17)
project(untitledc C)

#set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Os -s -fno-math-errno -fno-exceptions -fno-stack-protector -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-unroll-loops -fmerge-all-constants -fno-ident -mfpmath=387 -ffunction-sections -fdata-sections")

add_executable(untitledc main.c ObjectIO.c fridgeInventory.c)
