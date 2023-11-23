cmake_minimum_required(VERSION 3.26)
project(Clang_socket C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Clang_socket
        udp/client.c
        udp/server.c
        tcp/client.c
        tcp/server.c
        http/server.c)
