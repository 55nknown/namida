cmake_minimum_required(VERSION 3.5.1)
project(namida VERSION 0.1.0)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_CXX_FLAGS "-Ofast")

# Output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

#
# Engine
#
set(engine_sources   namida/src/*.cpp)
set(engine_vendor    namida/vendor/**/*.cpp)
set(engine_libraries fmt)

include_directories(namida/include)
include_directories(namida/vendor)
file(GLOB sources ${engine_sources})
file(GLOB vendor  ${engine_vendor})

add_compile_definitions(NAMIDA_BUILD_LIB)
add_compile_definitions(SPDLOG_FMT_EXTERNAL)

add_library(namida STATIC ${sources} ${vendor})
target_link_libraries(namida ${engine_libraries})

#
# Sandbox
#
set(sandbox_sources   sandbox/src/*.cpp)
set(sandbox_vendor    sandbox/vendor/**/*.cpp)
set(sandbox_libraries namida)

# include namida
include_directories(namida/include)
include_directories(sandbox/include)
include_directories(sandbox/vendor)
file(GLOB sources ${sandbox_sources})
file(GLOB vendor  ${sandbox_vendor})

add_executable(sandbox ${sources} ${vendor})
target_link_libraries(sandbox ${sandbox_libraries})
