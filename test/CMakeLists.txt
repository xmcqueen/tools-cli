cmake_minimum_required(VERSION 3.1)
project(test_jinja2cpp-cli CXX)

find_package(gtest REQUIRED)

add_executable (
        command_line_test.cpp
        param_resolver_test.cpp
        )

target_link_libraries( gtest::gtest jinja2cpp::cli)

add_test(NAME  COMMAND  --gtest_output=xml)
