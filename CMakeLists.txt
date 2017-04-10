cmake_minimum_required(VERSION 3.7)
project(FirenFrost)

#set(CMAKE_CXX_STANDARD 17)
add_compile_options(-std=c++17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_DIR src/com/mnenmenth/firenfrost)

set(CORE_DIR ${SOURCE_DIR}/core)
set(ENTITY_DIR ${SOURCE_DIR}/entity)
set(L_ENTITY_DIR ${ENTITY_DIR}/living) #Living Entity
set(NL_ENTITY_DIR ${ENTITY_DIR}/nonliving) #Non Living Entity
set(LOOT_DIR ${NL_ENTITY_DIR}/loot)
set(EQUIPPABLE_DIR ${LOOT_DIR}/equippable)
set(ARMOUR_DIR ${EQUIPPABLE_DIR}/armour)
set(WEAPON_DIR ${EQUIPPABLE_DIR}/weapon)
set(RENDER_DIR ${SOURCE_DIR}/render)

set(CORE
        ${CORE_DIR}/FirenFrost.cpp
        ${CORE_DIR}/Viewport.h
        ${CORE_DIR}/Viewport.cpp
        )

set(L_ENTITY
        ${L_ENTITY_DIR}/LivingEntity.h
        ${L_ENTITY_DIR}/LivingEntity.cpp
        )

set(ARMOUR
        ${ARMOUR_DIR}/Armour.h
        ${ARMOUR_DIR}/Armour.cpp
        )

set(WEAPON
        ${WEAPON_DIR}/Weapon.h
        ${WEAPON_DIR}/Weapon.cpp
        )

set(EQUIPPABLE
        ${EQUIPPABLE_DIR}/Equippable.h
        ${EQUIPPABLE_DIR}/Equippable.cpp
        ${ARMOUR}
        ${WEAPON}
        )

set(LOOT
        ${LOOT_DIR}/Loot.h
        ${LOOT_DIR}/Loot.cpp
        ${EQUIPPABLE}
        )

set(NL_ENTITY
        ${LOOT}
        )

set(ENTITY
        ${ENTITY_DIR}/Entity.h
        ${ENTITY_DIR}/Entity.cpp
        ${ENTITY_DIR}/AnimFrame.h
        ${ENTITY_DIR}/AnimFrame.cpp
        ${ENTITY_DIR}/Hitbox.h
        ${ENTITY_DIR}/Hitbox.cpp

        ${L_ENTITY}
        ${NL_ENTITY}
        )

set(RENDER
        ${RENDER_DIR}/Render.h
        ${RENDER_DIR}/Render.cpp
        )

set(SOURCE_FILES ${CORE} ${ENTITY} ${RENDER} )

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)
find_package(SFML REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})

add_executable(FirenFrost ${SOURCE_FILES})

target_link_libraries(FirenFrost ${SFML_LIBRARIES})