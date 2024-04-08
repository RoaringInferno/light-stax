cmake_minimum_required(VERSION 3.2)

project(light-stax)

set(TESTING true)

add_compile_definitions(
    "nullptr=0"
)

add_library(light-stax INTERFACE)
target_include_directories(light-stax INTERFACE
    src/
    src/link/
    src/linked_list/
)



if(${TESTING})
    include(CTest)

    add_compile_definitions(
        #"_DEBUG_PRINTLN" # Prints every line. Slows testing by a factor of 10^2
        #"_DEBUG_LIST_LOOPS=100000000" # Heavy performance testing. 10^8 (100 million)
    )

    set(UNIT_TESTS
        filo_list
        fifo_list
    )

    foreach(UNIT_TEST ${UNIT_TESTS})
        set(UNIT_TEST_EXEC "${UNIT_TEST}")
        set(UNIT_TEST_SRC "testing/${UNIT_TEST}_test.cpp")
        add_executable("${UNIT_TEST}" ${UNIT_TEST_SRC})
        #target_include_directories("${UNIT_TEST_EXEC}" PUBLIC include/)
        target_link_libraries("${UNIT_TEST}" PUBLIC light-stax)
        add_test(NAME "${UNIT_TEST_EXEC}" COMMAND "${UNIT_TEST_EXEC}")
    endforeach()
endif()