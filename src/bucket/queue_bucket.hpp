#pragma once

/**
 * @file static_queue_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, First Out (FIFO) principle.
 */

#include "bucket.hpp"

#define QUEUE_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define QUEUE_BUCKET static_queue_bucket<T, Size_T, Stack_Size>
#define BUCKET static_bucket<T, Size_T, Stack_Size>

namespace lstax
{
    QUEUE_BUCKET_TEMPLATE
    /**
     * @class static_queue_bucket
     * @brief A stack of fixed sixe that follows the First In, First Out (FIFO) principle.
     */
    struct static_queue_bucket : BUCKET
    {
        /**
         * @fn lstax::static_queue_bucket::_increment_bottom_index()
         * @brief Increment the bottom_index index of the stack.
         */
        void _increment_bottom_index() {
            if (++this->_bottom_index == Stack_Size) {
                this->_bottom_index = 0;
            }
        }

        /**
         * @val lstax::static_queue_bucket::bottom_index
         * @brief The index of the bottom_index element of the stack.
         * 
         * This is the push point for the stack.
        */
        Size_T _bottom_index;

        /**
         * @fn lstax::static_queue_bucket::queue_stack()
         * @brief Construct a new static_queue_bucket object.
         * 
         * @see lstax::static_bucket::static_bucket()
         */
        static_queue_bucket() : _bottom_index(0), BUCKET() {}
        /**
         * @fn lstax::static_queue_bucket::~queue_stack()
         * @brief Destroy the static_queue_bucket object.
         * 
         * @see lstax::static_bucket::~static_bucket()
         */
        ~static_queue_bucket() {}

        /**
         * @fn lstax::static_queue_bucket::push(const T& _data)
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
                this->_increment_bottom_index();
            }
            this->data[this->_bottom_index] = _data;
            this->_incrementLength();
        }

        void push() override
        {
            if (this->length != 0)
            {
                this->_increment_bottom_index();
            }
            this->_incrementLength();
        }

        /**
         * @fn lstax::static_queue_bucket::pop()
         * @brief Remove the top element of the stack.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override
        {
            this->_decrementLength();
            this->_increment_top_index();
        }
    };
}

#undef BUCKET
#undef QUEUE_BUCKET

#define BUCKET dynamic_bucket<T, Size_T, Stack_Size>
#define QUEUE_BUCKET dynamic_queue_bucket<T, Size_T, Stack_Size>

namespace lstax
{
    QUEUE_BUCKET_TEMPLATE
    /**
     * @class queue_bucket
     * @brief A stack of fixed sixe that follows the First In, First Out (FIFO) principle.
     */
    struct dynamic_queue_bucket : BUCKET
    {
        /**
         * @fn lstax::dynamic_queue_bucket::_increment_bottom_index()
         * @brief Increment the bottom_index index of the stack.
         */
        void _increment_bottom_index() {
            if (++this->_bottom_index == Stack_Size) {
                this->_bottom_index = 0;
            }
        }

        /**
         * @val lstax::dynamic_queue_bucket::bottom_index
         * @brief The index of the bottom_index element of the stack.
         * 
         * This is the push point for the stack.
        */
        Size_T _bottom_index;

        /**
         * @fn lstax::dynamic_queue_bucket::queue_stack()
         * @brief Construct a new dynamic_queue_bucket object.
         * 
         * @see lstax::dynamic_bucket::static_bucket()
         */
        dynamic_queue_bucket() : _bottom_index(0), BUCKET() {}
        /**
         * @fn lstax::dynamic_queue_bucket::~queue_stack()
         * @brief Destroy the dynamic_queue_bucket object.
         * 
         * @see lstax::dynamic_bucket::~static_bucket()
         */
        ~dynamic_queue_bucket() {}

        /**
         * @fn lstax::dynamic_queue_bucket::push(const T& _data)
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
                this->_increment_bottom_index();
            }
            this->data[this->_bottom_index] = _data;
            this->_incrementLength();
        }

        void push() override
        {
            if (this->length != 0)
            {
                this->_increment_bottom_index();
            }
            this->_incrementLength();
        }

        /**
         * @fn lstax::dynamic_queue_bucket::pop()
         * @brief Remove the top element of the stack.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override
        {
            this->_decrementLength();
            this->_increment_top_index();
        }
    };
}

#undef BUCKET
#undef QUEUE_BUCKET
#undef QUEUE_BUCKET_TEMPLATE