cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(light-stax)

set(TESTING true)

add_compile_definitions(
)

add_library(light-stax INTERFACE)
add_subdirectory(src/)

if(${TESTING})
    include(CTest)

    add_compile_definitions(
        "DEBUG_HEADER_PRINTLN"
        #"DEBUG_PRINTLN" # Prints every line. Slows testing by a factor of 10^2
        #"DEBUG_LIST_LOOPS=100000000" # Heavy performance testing. 10^8 (100 million)
    )

    set(UNIT_TESTS
        stack_list
        queue_list
        stack_bucket
        queue_bucket
    )

    foreach(UNIT_TEST ${UNIT_TESTS})
        set(UNIT_TEST_EXEC "${UNIT_TEST}")
        set(UNIT_TEST_SRC "testing/${UNIT_TEST}_test.cpp")
        add_executable("${UNIT_TEST}" ${UNIT_TEST_SRC})
        #target_include_directories("${UNIT_TEST_EXEC}" PUBLIC include/)
        target_link_libraries("${UNIT_TEST}" PUBLIC light-stax)
        add_test(NAME "${UNIT_TEST_EXEC}" COMMAND "${UNIT_TEST_EXEC}")
        #When running with Visual Studio, the test directory is "Debug".
    endforeach()
endif()
