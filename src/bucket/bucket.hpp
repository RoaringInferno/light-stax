#pragma once

/**
 * @file static_bucket.hpp
 * @brief A stack of fixed size that uses an array to store its data.
*/

#include "_data_array.hpp"
#include "data_structure.hpp"

#define BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    BUCKET_TEMPLATE
    /**
     * @class static_bucket
     * @brief A stack of fixed size that uses an array to store its data.
    */
    struct static_bucket : public DATA_STRUCTURE
    {
        /**
         * @fn lstax::static_bucket::_increment_top()
         * @brief Increment the top index of the stack.
         */
        void _increment_top()
        {
            if (++this->top == Stack_Size)
            {
                this->top = 0;
            }
        }

        /**
         * @fn lstax::static_bucket::_increment_top()
         * @brief Increment the top index of the stack.
        */
        void _decrement_top()
        {
            if (this->top-- == 0)
            {
                this->top = Stack_Size - 1;
            }
        }

        /**
         * @var lstax::static_bucket::top
         * @brief The index of the top element of the stack.
        */
        Size_T top;
        
        /**
         * @var lstax::static_bucket::data
         * @brief The data of the stack.
        */
        _data_array_stack<T, Size_T, Stack_Size> data;

        /**
         * @fn lstax::static_bucket::stack_list()
         * @brief Construct a new static_bucket object.
         * 
         * @see lstax::data_structure::data_structure()
        */
        static_bucket() : top(0), DATA_STRUCTURE() {}

        /**
         * @fn lstax::static_bucket::~stack_list()
         * @brief Destroy the static_bucket object.
         * 
         * @see lstax::data_structure::~data_structure()
        */
        ~static_bucket() {}

        /**
         * @fn lstax::static_bucket::peek() const
         * @brief Get the top element of the stack.
         * 
         * @return The top element of the stack.
         * @see lstax::data_structure::peek() const
        */
        T peek() const override
        {
            return this->data.value[this->top];
        }
    };

    BUCKET_TEMPLATE
    /**
     * @class dynamic_bucket
     * @brief A stack of fixed size that uses a dynamically allocated array to store its data.
    */
    struct dynamic_bucket : public DATA_STRUCTURE
    {
        /**
         * @fn lstax::dynamic_bucket::_increment_top()
         * @brief Increment the top index of the stack.
         */
        void _increment_top()
        {
            if (++this->top == Stack_Size)
            {
                this->top = 0;
            }
        }

        /**
         * @fn lstax::dynamic_bucket::_increment_top()
         * @brief Increment the top index of the stack.
        */
        void _decrement_top()
        {
            if (this->top-- == 0)
            {
                this->top = Stack_Size - 1;
            }
        }

        /**
         * @var lstax::dynamic_bucket::top
         * @brief The index of the top element of the stack.
        */
        Size_T top;
        
        /**
         * @var lstax::dynamic_bucket::data
         * @brief The data of the stack.
        */
        _data_array_heap<T, Size_T, Stack_Size> data;

        /**
         * @fn lstax::dynamic_bucket::stack_list()
         * @brief Construct a new dynamic_bucket object.
         * 
         * @see lstax::data_structure::data_structure()
        */
        dynamic_bucket() : top(0), DATA_STRUCTURE() {}

        /**
         * @fn lstax::dynamic_bucket::~stack_list()
         * @brief Destroy the dynamic_bucket object.
         * 
         * @see lstax::data_structure::~data_structure()
        */
        ~dynamic_bucket() {}

        /**
         * @fn lstax::dynamic_bucket::peek() const
         * @brief Get the top element of the stack.
         * 
         * @return The top element of the stack.
         * @see lstax::data_structure::peek() const
        */
        T peek() const override
        {
            return this->data.value[this->top];
        }
    };
}

#undef BUCKET_TEMPLATE
#undef BUCKET