message(STATUS "'internal' dependencies mode selected for Jinja2Cpp. All dependencies are used as submodules")

update_submodule(boost)
list(APPEND BOOST_CMAKE_LIBRARIES program_options)
set(BOOST_CMAKE_LIBRARIES ${BOOST_CMAKE_LIBRARIES} CACHE INTERNAL "")
add_subdirectory(thirdparty/boost EXCLUDE_FROM_ALL)

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-Wno-error=parentheses COMPILER_HAS_WNO_ERROR_PARENTHESES_FLAG)
check_cxx_compiler_flag(-Wno-error=deprecated-declarations COMPILER_HAS_WNO_ERROR_DEPRECATED_DECLARATIONS_FLAG)
check_cxx_compiler_flag(-Wno-error=maybe-uninitialized COMPILER_HAS_WNO_ERROR_MAYBE_UNINITIALIZED_FLAG)

