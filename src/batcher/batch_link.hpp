#pragma once

#include "_data_array.hpp"
#include "link.hpp"

#define BATCH_LINK_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCH_LINK batch_link<T, Size_T, Batch_Size>

namespace lstax
{
    BATCH_LINK_TEMPLATE
    struct batch_link
    {
        static const Size_T LOWEST_INDEX = 0;
        static const Size_T HIGHEST_INDEX = Batch_Size - 1;

        // Stores data from 0 to Batch_Size - 1
        _data_array_stack<T, Size_T, Batch_Size> data;

        T& operator[](const Size_T index)
        {
            return data[index];
        }
    };
} // namespace lstax

#undef BATCH_LINK_TEMPLATE
#undef BATCH_LINK