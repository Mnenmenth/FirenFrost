cmake_minimum_required(VERSION 3.7)
project(FirenFrost)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_DIR src/com/mnenmenth/firenfrost)

set(CORE_DIR ${SOURCE_DIR}/core)
set(ENTITY_DIR ${SOURCE_DIR}/entity)

set(CORE
        ${CORE_DIR}/FirenFrost.cpp
        ${CORE_DIR}/Viewport.h
        ${CORE_DIR}/Viewport.cpp
        )
set(ENTITY
        ${ENTITY_DIR}/Entity.h
        ${ENTITY_DIR}/Entity.cpp
        ${ENTITY_DIR}/AnimatedEntity.h
        ${ENTITY_DIR}/AnimatedEntity.cpp
        )

set(SOURCE_FILES ${CORE} ${ENTITY})

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)
find_package(SFML REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

add_executable(FirenFrost ${SOURCE_FILES})

target_link_libraries(FirenFrost ${SFML_LIBRARIES})