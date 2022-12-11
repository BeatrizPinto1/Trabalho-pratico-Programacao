cmake_minimum_required(VERSION 3.19)
project(TrabPra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TrabPra
        jogo.c
        jogo.h
        main.c utils.c utils.h)
