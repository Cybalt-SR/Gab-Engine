﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/vcpkg/scripts/buildsystems/vcpkg.cmake")
message("INCLUDING VCPKG AT: " "${CMAKE_TOOLCHAIN_FILE}")

project ("gab-engine" LANGUAGES CXX)

#SUBDIRECTORY LOADING
add_subdirectory(src)

# Add source to this project's executable.
add_executable(${PROJECT_NAME} "src/gab-engine.h" "src/gab-engine.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE gbe_engine_src)

#Dependency Loading
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
find_package(SDL2_mixer CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE wx::core wx::base)

#Dependency Workarounds (temp hopefully)
find_package(Bullet CONFIG REQUIRED)
include_directories(${BULLET_INCLUDE_DIRS})
message("[GABENGINE] [WORKAROUND] INCLUDED: " ${BULLET_INCLUDE_DIRS} " To MAIN")

#COPY ASSETS TO BUILD TARGET COMMAND
add_custom_target(COPY_ASSETS_COMMAND
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_LIST_DIR}/DefaultAssets" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/DefaultAssets"
)

add_dependencies(${PROJECT_NAME} COPY_ASSETS_COMMAND)

#COPY DLL TO BUILD
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:${PROJECT_NAME}> $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}>
  COMMAND_EXPAND_LISTS
)

get_target_property(LINKED_LIBS ${PROJECT_NAME} LINK_LIBRARIES)
# Construct the compiler string for the include directories.
    foreach(lib ${LINKED_LIBS})
        string(APPEND LINKED_LIBS_STRING " | ${lib} ")
    endforeach()
message("LINKED LIBRARIES: " ${LINKED_LIBS_STRING})
get_target_property(INCLUDED_DIRS ${PROJECT_NAME} INCLUDE_DIRECTORIES)
    # Construct the compiler string for the include directories.
    foreach(dir ${INCLUDED_DIRS})
        string(APPEND INCLUDED_DIRS_STRING " | ${dir} ")
    endforeach()
message("INCLUDED DIRECTORIES: " ${INCLUDED_DIRS_STRING})