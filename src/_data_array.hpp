#pragma once

/**
 * @file _data_array.hpp
 * @brief A wrapper for data arrays to allow for custom cleanup.
 */

#define DATA_ARRAY_TEMPLATE template<typename T, typename Size_T, Size_T capacity>

namespace lstax
{
    DATA_ARRAY_TEMPLATE
    struct _data_array_structure
    {
        T value[capacity];

        _data_array_structure() {};
        _data_array_structure(const _data_array_structure& other) {
            for (Size_T i = 0; i < capacity; i++) {
                this->value[i] = other.value[i];
            };
        };
        _data_array_structure(const T* _data) {
            for (Size_T i = 0; i < capacity; i++) {
                this->value[i] = _data[i];
            };
        };
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array : public _data_array_structure<T, Size_T, capacity>
    {
        _data_array() {};
        _data_array(const _data_array& other) : _data_array_structure<T, Size_T, capacity>(other) {};
        _data_array(const T* _data) : _data_array_structure<T, Size_T, capacity>(_data) {};
        ~_data_array() {};
    };

    DATA_ARRAY_TEMPLATE
    struct _data_array<T*, Size_T, capacity> : public _data_array_structure<T*, Size_T, capacity>
    {
        _data_array() {};
        _data_array(const _data_array& other) : _data_array_structure<T*, Size_T, capacity>(other) {};
        _data_array(const T** _data) : _data_array_structure<T*, Size_T, capacity>(_data) {};
        ~_data_array() {
            for (Size_T i = 0; i < capacity; i++) {
                delete this->value[i];
            }
        };
    };
}

#undef DATA_ARRAY_TEMPLATE
#undef DATA_STRUCTURE