#pragma once

#include <Kernel/sys/_types/_size_t.h>
#include <cassert>
#include <iostream>

#ifdef _DEBUG_PRINTLN
    #define DEBUG_PRINT(TEXT) std::cout TEXT;
#else
    #define DEBUG_PRINT(TEXT)
#endif

#ifndef _DEBUG_LIST_LOOPS
    #define _DEBUG_LIST_LOOPS 10000000
#endif