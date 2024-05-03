#pragma once

/**
 * @file queue_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, First Out (FIFO) principle.
 */

#include "bucket.hpp"

#define QUEUE_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define QUEUE_BUCKET queue_bucket<T, Size_T, Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>

namespace lstax
{
    QUEUE_BUCKET_TEMPLATE
    /**
     * @class queue_bucket
     * @brief A stack of fixed sixe that follows the First In, First Out (FIFO) principle.
     */
    struct queue_bucket : BUCKET
    {
        /**
         * @fn lstax::queue_bucket::_increment_bottom()
         * @brief Increment the bottom index of the stack.
         */
        void _increment_bottom() {
            if (++this->bottom == Stack_Size) {
                this->bottom = 0;
            }
        }

        /**
         * @val lstax::queue_bucket::bottom
         * @brief The index of the bottom element of the stack.
         * 
         * This is the push point for the stack.
        */
        Size_T bottom;

        /**
         * @fn lstax::queue_bucket::queue_stack()
         * @brief Construct a new queue_bucket object.
         * 
         * @see lstax::bucket::bucket()
         */
        queue_bucket() : bottom(0), BUCKET() {}
        /**
         * @fn lstax::queue_bucket::~queue_stack()
         * @brief Destroy the queue_bucket object.
         * 
         * @see lstax::bucket::~bucket()
         */
        ~queue_bucket() {}

        /**
         * @fn lstax::queue_bucket::push(const T& _data)
         * @brief Add an element to the top of the stack.
         * 
         * If an element is added and the stack is at capacity, the oldest _data will be overwritten.
         * 
         * @param _data The _data to add to the stack.
         * 
         * @see lstax::data_structure::push()
        */
        void push(const T& _data) override
        {
            if (this->length != 0)
            {
                this->_increment_bottom();
            }
            this->data.value[this->bottom] = _data;
            ++this->length;
        }

        /**
         * @fn lstax::queue_bucket::pop()
         * @brief Remove the top element of the stack.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override
        {
            this->_decrement_length();
            this->_increment_top();
        }
    };
}

#undef QUEUE_BUCKET_TEMPLATE
#undef QUEUE_BUCKET
#undef BUCKET