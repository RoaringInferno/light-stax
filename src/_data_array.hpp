#pragma once

#include "_data.hpp"

/**
 * @file _data_array.hpp
 * @brief A wrapper for data arrays to allow for custom cleanup.
 */

#define DATA_ARRAY_TEMPLATE template<typename T, typename Size_T, Size_T capacity>

namespace lstax // Static Allocation
{
    DATA_ARRAY_TEMPLATE
    struct _data_array_stack
    {
        _data<T> value[capacity];

        _data_array_stack() {};

        T& operator[](Size_T index) {
            return value[index].value;
        }
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array_heap
    {
        _data<T>* value = new _data<T>[capacity];

        _data_array_heap() {};
        ~_data_array_heap() {
            delete[] value;
        };

        T& operator[](Size_T index) {
            return value[index].value;
        }
    };
}

#undef DATA_ARRAY_TEMPLATE