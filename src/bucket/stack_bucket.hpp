#pragma once

/**
 * @file stack_bucket.hpp
 * @brief A data structure of fixed size that follows the First In, Last Out (FILO) principle.
 */

#include "bucket.hpp"

#define STACK_BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>

#define STACK_BUCKET static_stack_bucket<T, Size_T, Stack_Size>
#define BUCKET static_bucket<T, Size_T, Stack_Size>

namespace lstax
{
    STACK_BUCKET_TEMPLATE
    /**
     * @class static_stack_bucket
     * @brief A stack of fixed sixe that follows the First In, Last Out (STACK) principle.
     */
    struct static_stack_bucket : BUCKET
    {
        /**
         * @fn lstax::static_stack_bucket::filo_stack()
         * @brief Construct a new static_stack_bucket object.
         * 
         * @see lstax::static_bucket::static_bucket()
         */
        static_stack_bucket() : BUCKET() {}
        /**
         * @fn lstax::static_stack_bucket::~filo_stack()
         * @brief Destroy the static_stack_bucket object.
         * 
         * @see lstax::static_bucket::~static_bucket()
         */
        ~static_stack_bucket() {}

        /**
         * @fn lstax::static_stack_bucket::push(const T& _data)
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
         * @fn lstax::static_stack_bucket::pop()
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

#undef STACK_BUCKET
#undef BUCKET

#define STACK_BUCKET dynamic_stack_bucket<T, Size_T, Stack_Size>
#define BUCKET dynamic_bucket<T, Size_T, Stack_Size>

namespace lstax
{
    STACK_BUCKET_TEMPLATE
    /**
     * @class dynamic_stack_bucket
     * @brief A stack of fixed sixe that follows the First In, Last Out (STACK) principle.
     */
    struct dynamic_stack_bucket : BUCKET
    {
        /**
         * @fn lstax::dynamic_stack_bucket::filo_stack()
         * @brief Construct a new dynamic_stack_bucket object.
         * 
         * @see lstax::static_bucket::static_bucket()
         */
        dynamic_stack_bucket() : BUCKET() {}
        /**
         * @fn lstax::dynamic_stack_bucket::~filo_stack()
         * @brief Destroy the dynamic_stack_bucket object.
         * 
         * @see lstax::static_bucket::~static_bucket()
         */
        ~dynamic_stack_bucket() {}

        /**
         * @fn lstax::dynamic_stack_bucket::push(const T& _data)
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
         * @fn lstax::dynamic_stack_bucket::pop()
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

#undef STACK_BUCKET
#undef BUCKET
#undef STACK_BUCKET_TEMPLATE