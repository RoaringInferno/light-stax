#pragma once

/**
 * @file stack_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, Last Out (FILO) principle.
 */

#include "bucket.hpp"

#define STACK_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define STACK_BUCKET stack_bucket<T, Size_T, Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>

namespace lstax
{
    STACK_BUCKET_TEMPLATE
    /**
     * @class stack_bucket
     * @brief A stack of fixed sixe that follows the First In, Last Out (STACK) principle.
     */
    struct stack_bucket : BUCKET
    {
        /**
         * @fn lstax::stack_bucket::filo_stack()
         * @brief Construct a new stack_bucket object.
         * 
         * @see lstax::bucket::bucket()
         */
        stack_bucket() : BUCKET() {}
        /**
         * @fn lstax::stack_bucket::~filo_stack()
         * @brief Destroy the stack_bucket object.
         * 
         * @see lstax::bucket::~bucket()
         */
        ~stack_bucket() {}

        /**
         * @fn lstax::stack_bucket::push(const T& _data)
         * @brief Add an element to the top of the stack.
         * 
         * @param _data The data to add to the stack.
         * 
         * @see lstax::data_structure::push()
        */
        void push(const T& _data) override
        {
            if (this->length != 0)
            {
                this->_increment_top();
            }
            this->data.value[this->top] = _data;
            ++this->length;
        }

        /**
         * @fn lstax::stack_bucket::pop()
         * @brief Remove the top element of the stack.
         * 
         * @see lstax::data_structure::pop()
        */
        void pop() override
        {
            this->_decrement_length();
            this->_decrement_top();
        }
    };
}

#undef STACK_BUCKET_TEMPLATE
#undef STACK_BUCKET
#undef BUCKET