#pragma once

/**
 * @file batcher.hpp
 * @brief This file contains the definition of the batcher class template.
 * 
 * The batcher class is the base class for all batcher data structures.
 */

#include "data_structure.hpp"
#include "batch_link.hpp"
#include "linked_list.hpp"

#define BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    /**
     * @interface batcher
     * @brief The batcher class template represents a batcher data structure.
     * 
     * @tparam T The type of elements stored in the batcher.
     * @tparam Size_T The type used for size-related operations.
     * @tparam Batch_Size The size of each batch in the batcher.
     */
    BATCHER_TEMPLATE
    struct batcher : public DATA_STRUCTURE {
        /**
         * @var batcher::_top_index
         * @brief The index of the top batch in the batcher.
        */
        Size_T _top_index;

        /**
         * @fn lstax::batcher::batcher()
         * @brief Constructs a new batcher object.
         * 
         * @see lstax::data_structure::data_structure()
         */
        batcher() : DATA_STRUCTURE() {};

        /**
         * @fn lstax::batcher::_push_batch()
         * @brief Pushes a new batch into the batcher.
         * @note This method is an interface to be implemented by derived classes.
         */
        virtual void _push_batch() = 0;

        /**
         * @fn lstax::batcher::_pop_batch()
         * @brief Pops the top batch from the batcher.
         * @note This method is an interface to be implemented by derived classes.
         */
        virtual void _pop_batch() = 0;

        // Private Methods (_top_index)

        /**
         * @fn lstax::batcher::_top_is_full() const
         * @brief Checks if the top batch is full.
         * @return True if the top batch is full, false otherwise.
         */
        bool _top_is_full() const {
            return this->_top_index == Batch_Size;
        };

        /**
         * @fn lstax::batcher::_top_is_empty() const
         * @brief Checks if the top batch is empty.
         * 
         * @return True if the top batch is empty, false otherwise.
         */
        bool _top_is_empty() const {
            return this->_top_index == 0;
        };

        /**
         * @fn lstax::batcher::_reset_top_index_empty()
         * @brief Resets the top index to indicate an empty batch.
         */
        void _reset_top_index_empty() {
            this->_top_index = batch_link<T, Size_T, Batch_Size>::LOWEST_INDEX;
        };

        /**
         * @fn lstax::batcher::_reset_top_index_full()
         * @brief Resets the top index to indicate a full batch.
         */
        void _reset_top_index_full() {
            this->_top_index = batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX;
        };
    };
}

#undef BATCHER_TEMPLATE
#undef DATA_STRUCTURE