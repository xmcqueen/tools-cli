
function(update_submodule submodule)
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init thirdparty/${submodule}
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endfunction()

include (./thirdparty/thirdparty-internal.cmake)

set(J2CLI_PRIVATE_LIBS ${JINJA2CPP_PRIVATE_LIBS} boot_program_options)
