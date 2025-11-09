cmake_minimum_required(VERSION 3.16)

project(tetris LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE  
    SFML::Graphics 
    SFML::Window 
    SFML::System
)

add_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wreturn-type)