#pragma once

/**
 * @file fifo_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, First Out (FIFO) principle.
 */

#include "bucket.hpp"

#define FIFO_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define FIFO_BUCKET fifo_bucket<T, Size_T, Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>

namespace lstax
{
    FIFO_BUCKET_TEMPLATE
    /**
     * @class fifo_bucket
     * @brief A stack of fixed sixe that follows the First In, First Out (FIFO) principle.
     */
    struct fifo_bucket : BUCKET
    {
        /**
         * @fn lstax::fifo_bucket::_increment_bottom()
         * @brief Increment the bottom index of the stack.
         */
        void _increment_bottom() {
            if (++this->bottom == Stack_Size) {
                this->bottom = 0;
            }
        }

        /**
         * @val lstax::fifo_bucket::bottom
         * @brief The index of the bottom element of the stack.
         * 
         * This is the push point for the stack.
        */
        Size_T bottom;

        /**
         * @fn lstax::fifo_bucket::fifo_stack()
         * @brief Construct a new fifo_bucket object.
         * 
         * @see lstax::bucket::bucket()
         */
        fifo_bucket() : bottom(0), BUCKET() {}
        /**
         * @fn lstax::fifo_bucket::~fifo_stack()
         * @brief Destroy the fifo_bucket object.
         * 
         * @see lstax::bucket::~bucket()
         */
        ~fifo_bucket() {}

        /**
         * @fn lstax::fifo_bucket::push(const T& _data)
         * @brief Add an element to the top of the stack.
         * 
         * If an element is added and the stack is at capacity, the oldest data will be overwritten.
         * 
         * @param _data The data to add to the stack.
         * 
         * @see lstax::data_structure::push()
        */
        void push(const T& _data) override
        {
            if (this->length != 0)
            {
                this->_increment_bottom();
            }
            this->data[this->bottom] = _data;
            ++this->length;
        }

        /**
         * @fn lstax::fifo_bucket::pop()
         * @brief Remove the top element of the stack.
        */
        void pop() override
        {
            this->_decrement_length();
            this->_increment_top();
        }
    };
}

#undef FIFO_BUCKET_TEMPLATE
#undef FIFO_BUCKET
#undef BUCKET