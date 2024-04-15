#pragma once

/**
 * @file bucket.hpp
 * @brief A stack of fixed size that uses an array to store its data.
*/

#include "data_structure.hpp"

#define BUCKET_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define BUCKET bucket<T, Size_T, Stack_Size>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    BUCKET_TEMPLATE
    /**
     * @class bucket
     * @brief A stack of fixed size that uses an array to store its data.
    */
    struct bucket : public DATA_STRUCTURE
    {
        /**
         * @fn lstax::bucket::_increment_top()
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
         * @fn lstax::bucket::_increment_top()
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
         * @var lstax::bucket::top
         * @brief The index of the top element of the stack.
        */
        Size_T top;
        /**
         * @var lstax::bucket::data
         * @brief The data of the stack.
        */
        T data[Stack_Size];

        /**
         * @fn lstax::bucket::stack_list()
         * @brief Construct a new bucket object.
         * 
         * @see lstax::data_structure::data_structure()
        */
        bucket() : top(0), DATA_STRUCTURE() {}

        /**
         * @fn lstax::bucket::~stack_list()
         * @brief Destroy the bucket object.
         * 
         * @see lstax::data_structure::~data_structure()
        */
        ~bucket() {}

        /**
         * @fn lstax::bucket::peek() const
         * @brief Get the top element of the stack.
         * 
         * @return The top element of the stack.
         * @see lstax::data_structure::peek() const
        */
        T peek() const override
        {
            return this->data[this->top];
        }
    };
}

#undef BUCKET_TEMPLATE
#undef BUCKET