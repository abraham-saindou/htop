cmake_minimum_required(VERSION 3.27)
project(htop C)

set(CMAKE_C_STANDARD 17)

add_executable(htop
        src/main.c
        src/memleak.c
        src/backend/Data_getter.h
        src/backend/Data_getter.c
        src/frontend/gui.c)
