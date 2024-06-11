#pragma once

/**
 * @file queue_batcher.hpp
 * @brief This file contains the definition of the queue_batcher class template.
 * 
 * The queue_batcher class template represents a batcher data structure that follows the First In, First Out (FIFO) principle.
*/

#include "batcher.hpp"
#include "queue_list.hpp"

#define QUEUE_BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>

namespace lstax
{
    QUEUE_BATCHER_TEMPLATE
    /**
     * @struct queue_batcher
     * @brief Represents a batcher data structure that follows the First In, First Out (FIFO) principle.
     * 
     * @tparam T The type of elements stored in the queue batcher.
     * @tparam Size_T The type used for size-related operations.
     * @tparam Batch_Size The size of each batch in the queue batcher.
    */
    struct queue_batcher : public BATCHER {
        /**
         * @var lstax::queue_batcher::batch_list
         * @brief The linked list of batches in the queue batcher.
        */
        queue_list<batch_link<T, Size_T, Batch_Size>, Size_T> batch_list;

        /**
         * @var stax::queue_batcher::_bottom_index
         * @brief The index of the bottom element in the current batch.
         * @note This index is the batcher's push point, and points to the next available slot in the batch.
        */
        Size_T _bottom_index;

        /**
         * @fn lstax::queue_batcher::queue_batcher()
         * @brief Constructs a new queue batcher object.
         * 
         * @see lstax::batcher::batcher()
        */
        queue_batcher() : BATCHER() {
            this->_push_batch();
            this->_reset_top_index_empty();
            this->_reset_bottom_index_empty();
        };

        /**
         * @fn lstax::queue_batcher::push(const T& _data)
         * @brief Adds an element to the end of the queue batcher.
         * 
         * @param _data The data to add to the queue batcher.
         * 
         * @see lstax::data_structure::push(const T& _data)
        */
        void push(const T& _data) override {
            if (this->_bottom_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_bottom_index_empty();
            }
            this->batch_list.bottom->data.value[this->_bottom_index] = _data;
            this->_bottom_index++;
            this->_incrementLength();
        };

        /**
         * @fn lstax::queue_batcher::pop()
         * @brief Removes the top element from the queue batcher.
         * 
         * @see lstax::data_structure::push()
        */
        void push() override {
            if (this->_bottom_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_bottom_index_empty();
            }
            this->_bottom_index++;
            this->_incrementLength();
        }

        /**
         * @fn lstax::queue_batcher::pop()
         * @brief Removes the top element from the queue batcher.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override {
            this->_top_index++;
            if (this->_top_is_full()) {
                // Get the next batch
                this->_pop_batch();
                this->_reset_top_index_empty();
            }
            this->_decrementLength();
        };

        /**
         * @fn lstax::queue_batcher::peek()
         * @brief Retrieves the top element from the queue batcher.
         * 
         * @return The top element in the queue batcher.
         * 
         * @see lstax::data_structure::peek()
        */
        T& peek() override {
            return this->batch_list.peek()[this->_top_index];
        };

        // Interface with linked_list
        /**
         * @fn lstax::queue_batcher::get_batch_count() const
         * @brief Retrieves the number of batches in the queue batcher.
         * 
         * @return The number of batches in the queue batcher.
         * 
         * @see lstax::queue_list::length
        */
        Size_T get_batch_count() const {
            return batch_list.length;
        };

        /**
         * @fn lstax::queue_batcher::get_batch(Size_T index) const
         * @brief Retrieves the batch at the specified index in the queue batcher.
         * 
         * @param index The index of the batch to retrieve.
         * @return The batch at the specified index.
         * 
         * @see lstax::batcher::_push_batch()
         * @see lstax::queue_list::push()
        */
        void _push_batch() override {
            batch_list.push(); // Linked list must hold dereferenced batches
        };

        /**
         * @fn lstax::queue_batcher::get_batch(Size_T index) const
         * @brief Retrieves the batch at the specified index in the queue batcher.
         * 
         * @param index The index of the batch to retrieve.
         * @return The batch at the specified index.
         * 
         * @see lstax::batcher::_pop_batch()
         * @see lstax::queue_list::pop()
        */
        void _pop_batch() override {
            batch_list.pop();
        };

        // Private Methods (_bottom_index)
        /**
         * @fn lstax::queue_batcher::_bottom_is_full() const
         * @brief Checks if the bottom batch is full.
         * 
         * @return True if the bottom batch is full, false otherwise.
        */
        bool _bottom_is_full() const {
            return this->_bottom_index == Batch_Size;
        };

        /**
         * @fn lstax::queue_batcher::_bottom_is_empty() const
         * @brief Checks if the bottom batch is empty.
         * 
         * @return True if the bottom batch is empty, false otherwise.
        */
        bool _bottom_is_empty() const {
            return this->_bottom_index == 0;
        };

        /**
         * @fn lstax::queue_batcher::_reset_bottom_index_empty()
         * @brief Resets the bottom index to indicate an empty batch.
        */
        void _reset_bottom_index_empty() {
            this->_bottom_index = batch_link<T, Size_T, Batch_Size>::LOWEST_INDEX;
        };

        /**
         * @fn lstax::queue_batcher::get_batch_count() const
         * @brief Retrieves the number of batches in the queue batcher.
         * 
         * @return The number of batches in the queue batcher.
        */
        void _reset_bottom_index_full() {
            this->_bottom_index = batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX;
        };
    };
}

#undef QUEUE_BATCHER_TEMPLATE
#undef BATCHER