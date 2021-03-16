cmake_minimum_required(VERSION 3.1)

# set the project name
project(jinja2cpp-cli LANGUAGES CXX C VERSION 1.0)

find_package (Threads)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

configure_file(j2cli.pc.in j2cli.pc @ONLY)

configure_file(j2cli.h.in j2cli.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/program_options/install/include ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp/include/ ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp/thirdparty/json/nlohmann/include)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/program_options/build/libs/program_options)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(thirdparty/nlohmann ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/nlohmann)

function(update_submodule submodule)
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init thirdparty/${submodule}
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endfunction()

update_submodule(boost)

include(build_thirdparty)

BuildThirdparty(program_options "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost" "${CMAKE_CURRENT_BINARY_DIR}/program_options/build/libs/program_options/libboost_program_options.a" "-DBOOST_CMAKE_LIBRARIES=program_options")

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-Wno-error=parentheses COMPILER_HAS_WNO_ERROR_PARENTHESES_FLAG)
check_cxx_compiler_flag(-Wno-error=deprecated-declarations COMPILER_HAS_WNO_ERROR_DEPRECATED_DECLARATIONS_FLAG)
check_cxx_compiler_flag(-Wno-error=maybe-uninitialized COMPILER_HAS_WNO_ERROR_MAYBE_UNINITIALIZED_FLAG)

add_subdirectory (thirdparty/Jinja2Cpp ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp)

add_executable(j2cli 
    src/command_line.cpp
    src/command_line.h
    src/main.cpp
    src/param_resolver.cpp
    src/param_resolver.h
)

set_target_properties(j2cli PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
        j2cli
        jinja2cpp
	boost_program_options
        ${CMAKE_THREAD_LIBS_INIT}
        nlohmann_json::nlohmann_json
)

