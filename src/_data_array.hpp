#pragma once

#include "_data.hpp"

/**
 * @file _data_array.hpp
 * @brief A wrapper for data arrays to allow for custom cleanup.
 * @brief This file contains the definitions of two data array structures: `_data_array_stack` and `_data_array_heap`.
 * 
 * The `_data_array_stack` structure represents a stack-based data array, where the data is stored directly in the structure itself.
 * The `_data_array_heap` structure represents a heap-based data array, where the data is stored in dynamically allocated memory.
 * 
 * Both structures provide an overloaded `operator[]` to access elements of the data array.
 */

#define DATA_ARRAY_TEMPLATE template<typename T, typename Size_T, Size_T capacity>

namespace lstax
{
    DATA_ARRAY_TEMPLATE
    /**
     * @struct _data_array_stack
     * @brief A stack-based data array structure.
     * 
     * @tparam T The type of data stored in the array.
     * @tparam capacity The maximum capacity of the data array.
    */
    struct _data_array_stack
    {
        /**
         * @var _data<T> lstax::_data_array_stack::value[capacity]
         * @brief The array of data values.
        */
        _data<T> value[capacity];

        /**
         * @fn lstax::_data_array_stack::_data_array_stack()
         * @brief Default constructor for the `_data_array_stack` structure.
        */
        _data_array_stack() {};

        /**
         * @fn lstax::_data_array_stack::operator[]
         * @brief Accesses the element at the specified index in the data array.
         * 
         * @param index The index of the element to access.
         * @return A reference to the element at the specified index.
         */
        T& operator[](Size_T index) {
            return value[index].value;
        }
    };

    DATA_ARRAY_TEMPLATE
    /**
     * @struct _data_array_heap
     * @brief A heap-based data array structure.
     * 
     * @tparam T The type of data stored in the array.
     * @tparam capacity The maximum capacity of the data array.
    */
    struct _data_array_heap
    {
        /**
         * @var _data<T>* lstax::_data_array_heap::value
         * @brief The array of data values.
        */
        _data<T>* value = new _data<T>[capacity];

        /**
         * @fn lstax::_data_array_heap::_data_array_heap()
         * @brief Default constructor for the `_data_array_heap` structure.
        */
        _data_array_heap() {};

        /**
         * @fn lstax::_data_array_heap::~_data_array_heap()
         * @brief Destructor for the `_data_array_heap` structure.
         * 
         * Deletes the dynamically allocated memory used by the data array.
         */
        ~_data_array_heap() {
            delete[] value;
        };

        /**
         * @fn lstax::_data_array_heap::operator[]
         * @brief Accesses the element at the specified index in the data array.
         * 
         * @param index The index of the element to access.
         * @return A reference to the element at the specified index.
         */
        T& operator[](Size_T index) {
            return value[index].value;
        }
    };
}

#undef DATA_ARRAY_TEMPLATE