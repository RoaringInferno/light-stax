#pragma once

/**
 * @file batch_link.hpp
 * @brief This file contains the definition of the batch_link struct template.
 * 
 * The batch_link struct template represents a batch link that stores data from 0 to Batch_Size - 1.
*/

#include "_data_array.hpp"
#include "link.hpp"

#define BATCH_LINK_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>

namespace lstax
{
    BATCH_LINK_TEMPLATE
    /**
     * @brief Represents a batch link that stores data from 0 to Batch_Size - 1.
     * 
     * @tparam T The type of data stored in the batch link.
     * @tparam Size_T The type used for indexing the batch link.
     * @tparam Batch_Size The size of the batch link.
     */
    struct batch_link
    {
        // Constants
        /**
         * @var lstax::batch_link::Size_T lstax::batch_link::LOWEST_INDEX
         * @brief The lowest index of the batch link.
         */
        static const Size_T LOWEST_INDEX = 0;
        /**
         * @var lstax::batch_link::Size_T lstax::batch_link::HIGHEST_INDEX
         * @brief The highest index of the batch link.
        */
        static const Size_T HIGHEST_INDEX = Batch_Size - 1;

        /**
         * @var _data_array_stack<T, Size_T, Batch_Size> lstax::batch_link::data
         * @brief The data array of the batch link.
        */
        _data_array_stack<T, Size_T, Batch_Size> data;

        /**
         * @fn lstax::batch_link::batch_link()
         * @brief Accesses the element at the specified index in the batch link.
         * 
         * @param index The index of the element to access.
         * @return T& A reference to the element at the specified index.
         * 
         * @see lstax::_data_array_stack::operator[](const Size_T index)
         */
        T& operator[](const Size_T index)
        {
            return data[index];
        }
    };
} // namespace lstax

#undef BATCH_LINK_TEMPLATE