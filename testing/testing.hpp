#pragma once

#include <cassert>
#include <iostream>

#ifdef _DEBUG_PRINTLN
    #define DEBUG_PRINT(TEXT) std::cout TEXT;
#else
    #define DEBUG_PRINT(TEXT)
#endif

#ifndef _DEBUG_LIST_LOOPS
    #define _DEBUG_LIST_LOOPS 100000 // Light performance testing. 10^5 (100 thousand)
#endif