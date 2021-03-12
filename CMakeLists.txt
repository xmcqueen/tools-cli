cmake_minimum_required(VERSION 3.1)

#cmake_minimum_required(VERSION 3.0.1)

# set the project name
project(jinja2cpp-cli LANGUAGES CXX C VERSION 1.0)

find_package (Threads)
#target_link_libraries (myapp ${CMAKE_THREAD_LIBS_INIT})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#set(J2CLI_PRIVATE_LIBS "${J2CLI_PRIVATE_LIBS}")
#set (CMAKE_CXX_FLAGS "-lpthread")
#set (CMAKE_C_FLAGS "-lpthread")

#include(thirdparty/CMakeLists.txt)
configure_file(j2cli.pc.in j2cli.pc @ONLY)
#cmake_policy(SET CMP0048 OLD)

configure_file(j2cli.h.in j2cli.h)
# ./build/program_options/install/include/boost/program_options.hpp
# ./thirdparty/Jinja2Cpp/thirdparty/json/nlohmann/include
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/program_options/install/include ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp/include/ ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp/thirdparty/json/nlohmann/include)
#/mnt/dev/jinja2-cli/thirdparty/Jinja2Cpp/thirdparty/json/nlohmann/include/nlohmann/json.hpp
#/mnt/dev/jinja2-cli/thirdparty/Jinja2Cpp/thirdparty/json/nlohmann/include/nlohmann/json.hpp



#./build/program_options/build/libs/program_options/libboost_program_options.a
#./build/program_options/build/libs/program_options/libboost_program_options.a
link_directories(${CMAKE_CURRENT_BINARY_DIR}/program_options/build/libs/program_options)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(thirdparty/nlohmann ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/nlohmann)

#then try CMAKE_CURRENT_SOURCE_DIR
#./thirdparty/Jinja2Cpp/thirdparty/json/nlohmann/include/nlohmann/json.hpp
#QQQQ:/mnt/dev/jinja2-cli/build/thirdparty/jinja2cpp/include/:
#./thirdparty/Jinja2Cpp/thirdparty/json/nlohmann/include/nlohmann/json.hpp
message("QQQQ:CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR}:")
message("QQQQ:CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}:")

function(update_submodule submodule)
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init thirdparty/${submodule}
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endfunction()

#set(J2CLI_PRIVATE_LIBS ${JINJA2CPP_PRIVATE_LIBS} boost_program_options)

#try to use the cmake macros like this
#/mnt/git/Jinja2Cpp/CMakeLists.txt:CollectSources(Sources Headers ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)
#/mnt/git/Jinja2Cpp/CMakeLists.txt:CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
#/mnt/git/Jinja2Cpp/CMakeLists.txt:    CollectSources(TestSources TestHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/test)
#/mnt/git/Jinja2Cpp/cmake/collect_sources.cmake:function (CollectSources SourcesVar HeadersVar RelativePath FromPath)
#
#see these lines
#include(collect_sources)
#
#set (LIB_TARGET_NAME jinja2cpp)
#
#CollectSources(Sources Headers ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)
#CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
#
#add_library(${LIB_TARGET_NAME} ${LIB_LINK_TYPE}
#   ${Sources}
#   ${Headers}
#   ${PublicHeaders}
#)

#this will find the collect_sources and the build_thiridparty macros in our cmake dir
#because the CMAKE_MODULE_PATH is set above
#include(collect_sources)
#CollectSources(Sources Headers ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost/libs/program_options/src ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost/libs/program_options/include)
#CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
#CollectSources(PublicSources PublicHeaders ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost/libs)
#add_library(boost_program_options STATIC
   #${Sources}
   #${Headers}
   #${PublicHeaders}
#)
#message(STATUS "QQQ:${PublicHeaders}")

update_submodule(boost)
#list(APPEND BOOST_CMAKE_LIBRARIES program_options)
#list(APPEND BOOST_CMAKE_LIBRARIES filesystem algorithm variant optional program_options)
#set(BOOST_CMAKE_LIBRARIES ${BOOST_CMAKE_LIBRARIES} CACHE INTERNAL "")
#add_subdirectory(thirdparty/boost EXCLUDE_FROM_ALL)
include(build_thirdparty)

#it should have a cmake command like this:
#cmake .. -DBOOST_CMAKE_LIBRARIES="thread filesystem chrono program_options"
#./build/program_options/build/libs/program_options/libboost_program_options.a
message(STATUS "QQQ:CMAKE_CURRENT_BINARY_DIR:${CMAKE_CURRENT_BINARY_DIR}:")
message(STATUS "QQQ:want:./build/program_options/build/libs/program_options/libboost_program_options.a:")
message(STATUS "QQQ:checking:${CMAKE_CURRENT_BINARY_DIR}/program_options/build/libs/program_options/libboost_program_options.a:")
BuildThirdparty(program_options "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost" "${CMAKE_CURRENT_BINARY_DIR}/program_options/build/libs/program_options/libboost_program_options.a" "-DBOOST_CMAKE_LIBRARIES=program_options")


#https://stackoverflow.com/questions/28597351/how-do-i-add-a-library-path-in-cmake
#add_library(boost SHARED STATIC ${PublicHeaders})
#set_target_properties(bar PROPERTIES
  #IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libbar.so"
  #INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/thirdparty/boost/libs"
#)

# Enable -Werror and -Wall on jinja2cpp target, ignoring warning errors from thirdparty libs
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-Wno-error=parentheses COMPILER_HAS_WNO_ERROR_PARENTHESES_FLAG)
check_cxx_compiler_flag(-Wno-error=deprecated-declarations COMPILER_HAS_WNO_ERROR_DEPRECATED_DECLARATIONS_FLAG)
check_cxx_compiler_flag(-Wno-error=maybe-uninitialized COMPILER_HAS_WNO_ERROR_MAYBE_UNINITIALIZED_FLAG)

add_subdirectory (thirdparty/Jinja2Cpp ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/jinja2cpp)

# add the executable
add_executable(j2cli 
    src/command_line.cpp
    src/command_line.h
    src/main_j2.cpp
    src/param_resolver.cpp
    src/param_resolver.h
    src/yaml_reflector.h
)

#target_link_libraries (j2cli jinja2cpp)
#set_target_properties (j2cli PROPERTIES
            #CXX_STANDARD 14
            #CXX_STANDARD_REQUIRED ON)
    
set_target_properties(j2cli PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        #PUBLIC_HEADER ${PublicHeaders}
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        #INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost/libs"
)
#set_property(TARGET j2cli PROPERTY PUBLIC_HEADER ${PublicHeaders} ${JINJA2CPP_EXTRA_PUBLIC_HEADERS})
#set_property(TARGET j2cli PROPERTY PUBLIC_HEADER ${PublicHeaders})
#set_target_properties(j2cli PROPERTY PUBLIC_HEADER ${PublicHeaders})

target_link_libraries(
        j2cli
        jinja2cpp
	boost_program_options
        ${CMAKE_THREAD_LIBS_INIT}
        nlohmann_json::nlohmann_json
)

#target_include_directories(j2cli PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(j2cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost/libs)

