cmake_minimum_required (VERSION 2.8.7)
project (herogrinder)

file(GLOB SRC_FILES "src/*.cpp")
file(GLOB MAIN_FILES "*.cpp")
set( ALL_SRC ${SRC_FILES} ${MAIN_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)


add_executable(herogrinder ${ALL_SRC})
target_link_libraries(herogrinder SDL2 SDL2_image)
