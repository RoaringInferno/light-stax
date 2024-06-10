#pragma once

#include <cassert>
#include <iostream>

#ifdef DEBUG_HEADER_PRINTLN
    #define DEBUG_HEADER_PRINT(TEXT) std::cout TEXT;
#else
    #define DEBUG_HEADER_PRINT(TEXT)
#endif

#ifdef DEBUG_PRINTLN
    #define DEBUG_PRINT(TEXT) std::cout TEXT;
#else
    #define DEBUG_PRINT(TEXT)
#endif

/**
 * @brief The number of loops to run for the tests.
 * 
 * NOTE: Because filo and fifo_stack are built on statically-allocated arrays, larger numbers may throw segfaults.
*/
#ifndef STATIC_DEBUG_LIST_LOOPS
    #define STATIC_DEBUG_LIST_LOOPS 10000 // Light testing. 10^6 (10 thousand)
#endif

#ifndef DYNAMIC_DEBUG_LIST_LOOPS
    #define DYNAMIC_DEBUG_LIST_LOOPS 1000000 // Heavy testing. 10^6 (1 million)
#endif

#ifndef BATCHER_BUFFER_SIZE
    #define BATCHER_BUFFER_SIZE 100
#endif

namespace test
{
    typedef unsigned long Size_T;
    typedef unsigned long Data_T;
    typedef unsigned long Count_T;
}


#define TEST_TEMPLATE template<class T, Count_T count>

namespace test
{
    TEST_TEMPLATE
    void test_queue_values() {
        DEBUG_HEADER_PRINT(<< "test_queue_values\n")

        DEBUG_HEADER_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            list.push(i);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(list.peek() == 0);
            assert(list.length == i + 1);
        }

        DEBUG_HEADER_PRINT(<< "Popping\n")

        for (unsigned long i = 0; i < count; ++i) {
            assert(list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
            assert(list.length == count-i);
            list.pop();
        }

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void test_queue_pointers() {
        DEBUG_HEADER_PRINT(<< "test_queue_pointers\n")

        DEBUG_HEADER_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            auto* data = new unsigned long(i);
            list.push(data);
            DEBUG_PRINT(<< "\tlist.push(*"<< i<<")\n")
            assert(*list.peek() == 0);
            assert(list.length == i + 1);
        }

        DEBUG_HEADER_PRINT(<< "Popping\n")

        for (unsigned long i = 0; i < count; ++i) {
            assert(*list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == *"<<i<<"\n")
            assert(list.length == count-i);
            list.pop();
        }

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void test_stack_values() {
        DEBUG_HEADER_PRINT(<< "test_stack_values\n")

        DEBUG_HEADER_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            list.push(i);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(list.peek() == i);
            assert(list.length == i + 1);
        }

        DEBUG_HEADER_PRINT(<< "Popping\n")

        for (unsigned long i = count-1; i < count; --i) {
            assert(list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
            assert(list.length == i+1);
            list.pop();
        }

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void test_stack_pointers() {
        DEBUG_HEADER_PRINT(<< "test_stack_pointers\n")

        DEBUG_HEADER_PRINT(<< "Constructing\n")
        T list;

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            auto* data = new unsigned long(i);
            list.push(data);
            DEBUG_PRINT(<< "\tlist.push(*"<< i<<")\n")
            assert(*list.peek() == i);
            assert(list.length == i + 1);
        }

        DEBUG_HEADER_PRINT(<< "Popping\n")

        for (unsigned long i = count-1; i < count; --i) {
            assert(*list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == *"<<i<<"\n")
            assert(list.length == i+1);
            list.pop();
        }

        assert(list.length == 0);

        DEBUG_HEADER_PRINT(<< "Done\n")
    }
}

#undef TEST_TEMPLATE