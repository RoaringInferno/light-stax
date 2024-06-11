#pragma once

/**
 * @file stack_batcher.hpp
 * @brief This file contains the definition of the stack_batcher class template.
 * 
 * The stack_batcher class template represents a batcher data structure that follows the First In, Last Out (FILO) principle.
*/

#include "batcher.hpp"
#include "stack_list.hpp"

#define STACK_BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>

namespace lstax
{
    STACK_BATCHER_TEMPLATE
    /**
     * @struct stack_batcher
     * @brief Represents a batcher data structure that follows the First In, Last Out (FILO) principle.
     * 
     * @tparam T The type of elements stored in the stack batcher.
     * @tparam Size_T The type used for size-related operations.
     * @tparam Batch_Size The size of each batch in the stack batcher.
    */
    struct stack_batcher : public BATCHER
    {
        /**
         * @var lstax::stack_list<lstax::batch_link<T, Size_T, Batch_Size>, Size_T> lstax::stack_batcher::batch_list
         * @brief The linked list of batches in the stack batcher.
        */
        stack_list<batch_link<T, Size_T, Batch_Size>, Size_T> batch_list;

        /**
         * @var Size_T lstax::stack_batcher::_top_index
         * @brief The index of the top element in the current batch.
         * @note This index is the batcher's pop point, and points to the next available slot in the batch.
         * 
         * @see lstax::batcher::batcher()
        */
        stack_batcher() : BATCHER() {
            this->_push_batch();
            this->_reset_top_index_empty();
        };

        /**
         * @fn lstax::stack_batcher::push(const T& _data)
         * @brief Adds an element to the end of the stack batcher.
         * 
         * @param _data The _data to add to the stack batcher.
         * 
         * @see lstax::data_structure::push(const T& _data)
        */
        void push(const T& _data) override {
            if (this->_top_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_top_index_empty();
            }
            this->batch_list.peek()[this->_top_index] = _data;
            this->_top_index++;
            this->_incrementLength();
        };

        /**
         * @fn lstax::stack_batcher::push()
         * @brief Adds an element to the end of the stack batcher.
         * 
         * @see lstax::data_structure::push()
        */
        void push() override {
            if (this->_top_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_top_index_empty();
            }
            this->_top_index++;
            this->_incrementLength();
        };

        /**
         * @fn lstax::stack_batcher::pop()
         * @brief Removes the top element from the stack batcher.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override {
            if (this->_top_is_empty()) {
                // Get the next batch
                this->_pop_batch();
                this->_reset_top_index_full();
            } else {
                this->_top_index--;
            }
            this->_decrementLength();
        };

        /**
         * @fn lstax::stack_batcher::peek()
         * @brief Returns the top element of the stack batcher.
         * @return The top element of the stack batcher.
         * 
         * @see lstax::data_structure::peek()
        */
        T& peek() override {
            if (this->_top_is_empty()) {
                return this->batch_list.top->next->data.value[batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX];
            }
            return this->batch_list.peek()[this->_top_index-1];
        };

        // Interface with linked_list
        /**
         * @fn lstax::stack_batcher::get_batch_count() const
         * @brief Retrieves the number of batches in the stack batcher.
         * @return The number of batches in the stack batcher.
         * 
         * @see lstax::stack_list::length
        */
        Size_T get_batch_count() const {
            return batch_list.length;
        };

        /**
         * @fn lstax::stack_batcher::_push_batch()
         * @brief Pushes a new batch into the stack batcher.
         * 
         * @see lstax::batcher::_push_batch()
         * @see lstax::stack_list::push()
        */
        void _push_batch() override {
            batch_list.push(); // Linked list must hold dereferenced batches
        };

        /**
         * @fn lstax::stack_batcher::_pop_batch()
         * @brief Pops the top batch from the stack batcher.
         * 
         * @see lstax::batcher::_pop_batch()
         * @see lstax::stack_list::pop()
        */
        void _pop_batch() override {
            batch_list.pop();
        };
    };
}

#undef STACK_BATCHER_TEMPLATE
#undef BATCHER