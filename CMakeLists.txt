cmake_minimum_required(VERSION 3.2)

project(light-stax)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Dnullptr=0")

add_library(light-stax INTERFACE)
target_include_directories(light-stax INTERFACE
    src/
    src/link/
    src/filo/
)

include(CTest)

add_compile_definitions(
    #"_DEBUG_PRINTLN"
    "_DEBUG_LIST_LOOPS=100000000"
)

set(UNIT_TESTS
    filo_list
)

foreach(UNIT_TEST ${UNIT_TESTS})
    set(UNIT_TEST_EXEC "${UNIT_TEST}")
    set(UNIT_TEST_SRC "testing/src/${UNIT_TEST}_test.cpp")
    add_executable("${UNIT_TEST}" ${UNIT_TEST_SRC})
    #target_include_directories("${UNIT_TEST_EXEC}" PUBLIC include/)
    target_link_libraries("${UNIT_TEST}" PUBLIC light-stax)
    add_test(NAME "${UNIT_TEST_EXEC}" COMMAND "${UNIT_TEST_EXEC}")
endforeach()