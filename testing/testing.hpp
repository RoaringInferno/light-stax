#pragma once

#include <cassert>
#include <iostream>

#ifdef _DEBUG_PRINTLN
    #define DEBUG_PRINT(TEXT) std::cout TEXT;
#else
    #define DEBUG_PRINT(TEXT)
#endif

/**
 * @brief The number of loops to run for the tests.
 * 
 * NOTE: Because filo and fifo_stack are built on statically-allocated arrays, larger numbers may throw segfaults.
*/
#ifndef _DEBUG_LIST_LOOPS
    #define _DEBUG_LIST_LOOPS 100000 // Light performance testing. 10^5 (100 thousand)
#endif


#define TEST_TEMPLATE template<class T>

namespace test
{
    typedef unsigned long Size_T;
    typedef unsigned long Data_T;
    typedef unsigned long Count_T;
    const Count_T count = _DEBUG_LIST_LOOPS;

    TEST_TEMPLATE
    void fifo_lvalue() {
        DEBUG_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            list.push(i);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(list.peek() == 0);
            DEBUG_PRINT(<< "\tlist.peek() == 0\n")
            assert(list.length == i + 1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
        }

        DEBUG_PRINT(<< "Popping\n")

        for (unsigned long i = 0; i < count; ++i) {
            assert(list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
            assert(list.length == count-i);
            DEBUG_PRINT(<< "\tlist.length == "<<count-i<<"\n")
            list.pop();
            DEBUG_PRINT(<< "\tlist.pop()\n")
        }

        assert(list.length == 0);

        DEBUG_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void fifo_rvalue() {
        DEBUG_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            auto* data = new unsigned long(i);
            list.push(data);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(*list.peek() == 0);
            DEBUG_PRINT(<< "\t*list.peek() == 0\n")
            assert(list.length == i + 1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
        }

        DEBUG_PRINT(<< "Popping\n")

        for (unsigned long i = 0; i < count; ++i) {
            assert(*list.peek() == i);
            DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
            assert(list.length == count-i);
            DEBUG_PRINT(<< "\tlist.length == "<<count-i<<"\n")
            list.pop();
            DEBUG_PRINT(<< "\tlist.pop()\n")
        }

        assert(list.length == 0);

        DEBUG_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void filo_lvalue() {
        DEBUG_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            list.push(i);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(list.peek() == i);
            DEBUG_PRINT(<< "\t*list.peek() == "<<i<<"\n")
            assert(list.length == i + 1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
        }

        DEBUG_PRINT(<< "Popping\n")

        for (unsigned long i = count-1; i < count; --i) {
            assert(list.peek() == i);
            DEBUG_PRINT(<< "\t*list.peek() == "<<i<<"\n")
            assert(list.length == i+1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
            list.pop();
            DEBUG_PRINT(<< "\tlist.pop()\n")
        }

        assert(list.length == 0);

        DEBUG_PRINT(<< "Done\n")
    }

    TEST_TEMPLATE
    void filo_rvalue() {
        DEBUG_PRINT(<< "Constructing\n")

        T list;

        assert(list.length == 0);

        DEBUG_PRINT(<< "Pushing\n")

        for (unsigned long i = 0; i < count; ++i) {
            auto* data = new unsigned long(i);
            list.push(data);
            DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
            assert(*list.peek() == i);
            DEBUG_PRINT(<< "\t*list.peek() == "<<i<<"\n")
            assert(list.length == i + 1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
        }

        DEBUG_PRINT(<< "Popping\n")

        for (unsigned long i = count-1; i < count; --i) {
            assert(*list.peek() == i);
            DEBUG_PRINT(<< "\t*list.peek() == "<<i<<"\n")
            assert(list.length == i+1);
            DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
            list.pop();
            DEBUG_PRINT(<< "\tlist.pop()\n")
        }

        assert(list.length == 0);

        DEBUG_PRINT(<< "Done\n")
    }
}

#undef TEST_TEMPLATE