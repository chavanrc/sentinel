cmake_minimum_required(VERSION 3.19)
project(app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)
find_path(HIREDIS_HEADER hiredis)
find_path(REDIS_PLUS_PLUS_HEADER sw)
find_package(hiredis REQUIRED CONFIG)
find_package(hiredis_ssl REQUIRED CONFIG)
find_package(redis++ REQUIRED CONFIG)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${CMAKE_THREAD_LIBS_INIT}
        hiredis::hiredis
        hiredis::hiredis_ssl
        redis++::redis++
)