#pragma once

/**
 * @file _data_array.hpp
 * @brief A wrapper for data arrays to allow for custom cleanup.
 */

#define DATA_ARRAY_TEMPLATE template<typename T, typename Size_T, Size_T capacity>

namespace lstax // Static Allocation
{
    DATA_ARRAY_TEMPLATE
    struct _data_array_stack_structure
    {
        T value[capacity];

        _data_array_stack_structure() {};
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array_stack : public _data_array_stack_structure<T, Size_T, capacity>
    {
        _data_array_stack() : _data_array_stack_structure<T, Size_T, capacity>() {};
        ~_data_array_stack() {};
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array_stack<T*, Size_T, capacity> : public _data_array_stack_structure<T*, Size_T, capacity>
    {
        _data_array_stack() : _data_array_stack_structure<T*, Size_T, capacity>() {};
        ~_data_array_stack() {
            for (Size_T i = 0; i < capacity; i++) {
                delete this->value[i];
            }
        };
    };
}

namespace lstax // Dynamic Allocation
{
    DATA_ARRAY_TEMPLATE
    struct _data_array_heap_structure
    {
        T* value = new T[capacity];

        _data_array_heap_structure() {};
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array_heap : public _data_array_heap_structure<T, Size_T, capacity>
    {
        _data_array_heap() : _data_array_heap_structure<T, Size_T, capacity>() {};
        ~_data_array_heap() {};
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array_heap<T*, Size_T, capacity> : public _data_array_heap_structure<T*, Size_T, capacity>
    {
        _data_array_heap() : _data_array_heap_structure<T*, Size_T, capacity>() {};
        ~_data_array_heap() {
            for (Size_T i = 0; i < capacity; i++) {
                delete this->value[i];
            }
        };
    };
}

#undef DATA_ARRAY_TEMPLATE