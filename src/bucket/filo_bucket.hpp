#pragma once

/**
 * @file filo_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, Last Out (FILO) principle.
 */

#include "bucket.hpp"

#define FILO_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define FILO_BUCKET filo_bucket<T, Size_T, Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>

namespace lstax
{
    FILO_BUCKET_TEMPLATE
    /**
     * @class filo_bucket
     * @brief A stack of fixed sixe that follows the First In, Last Out (FILO) principle.
     */
    struct filo_bucket : BUCKET
    {
        /**
         * @fn lstax::filo_bucket::filo_stack()
         * @brief Construct a new filo_bucket object.
         * 
         * @see lstax::bucket::stack_list()
         */
        filo_bucket() : BUCKET() {}
        /**
         * @fn lstax::filo_bucket::~filo_stack()
         * @brief Destroy the filo_bucket object.
         * 
         * @see lstax::bucket::~stack_list()
         */
        ~filo_bucket() {}

        /**
         * @fn lstax::filo_bucket::push(const T& _data)
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
            this->data[this->top] = _data;
            ++this->length;
        }

        /**
         * @fn lstax::filo_bucket::pop()
         * @brief Remove the top element of the stack.
        */
        void pop() override
        {
            this->_decrement_length();
            this->_decrement_top();
        }
    };
}

#undef FILO_BUCKET_TEMPLATE
#undef FILO_BUCKET
#undef BUCKET