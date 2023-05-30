cmake_minimum_required(VERSION 3.5)

project("Film JSON" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(nlohmann_json)

add_subdirectory(src)

install(TARGETS film
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
