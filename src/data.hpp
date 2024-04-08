#pragma once

#include <iostream>

#define DATA_TEMPLATE template<typename T>

namespace lstax
{
    DATA_TEMPLATE
    struct data
    {
        T value;

        data() {
            std::cout << "data\n";
        };
        ~data() {};

        T get() {
            return value;
        };
    };

    DATA_TEMPLATE
    struct data<T*>
    {
        T* value;

        data() {
            std::cout << "data<T*>\n";
        };
        ~data() {
            delete value;
        };

        T get() {
            return *value;
        };
    };
}

#undef DATA_TEMPLATE