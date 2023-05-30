cmake_minimum_required(VERSION 3.5)

add_executable(film main.cpp ${MY_INCLUDE_DIR}/film.h film.cpp)

target_include_directories(film PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(film PRIVATE nlohmann_json::nlohmann_json)
