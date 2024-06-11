#pragma once

/**
 * @file bucket.hpp
 * @brief This file contains the definition of the bucket class template.
 * 
 * It also contains the definitions of two bucket structures: static_bucket and dynamic_bucket.
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
     * @interface bucket
     * @brief A stack of fixed size that uses an array to store its data.
    */
    struct bucket : public DATA_STRUCTURE
    {
        /**
         * @var lstax::bucket::_top_index
         * @brief The index of the top element in the stack.
        */
        Size_T _top_index;

        /**
         * @fn lstax::bucket::bucket()
         * @brief Construct a new bucket object.
         * 
         * @see lstax::data_structure::data_structure()
        */
        bucket() : DATA_STRUCTURE(), _top_index(0) {}

        /**
         * @fn lstax::bucket::_increment_top_index()
         * @brief Increments the top index of the stack.
         * 
         * @see lstax::bucket::_top_index
        */
        void _increment_top_index()
        {
            if (++this->_top_index == Stack_Size)
            {
                this->_top_index = 0;
            }
        }

        /**
         * @fn lstax::bucket::_decrement_top_index()
         * @brief Decrements the top index of the stack.
         * 
         * @see lstax::bucket::_top_index
        */
        void _decrement_top_index()
        {
            if (this->_top_index-- == 0)
            {
                this->_top_index = Stack_Size - 1;
            }
        }
    };

    BUCKET_TEMPLATE
    /**
     * @interface static_bucket
     * @brief A stack of fixed size that uses an array to store its data.
    */
    struct static_bucket : public BUCKET
    {
        
        /**
         * @var lstax::static_bucket::data
         * @brief The data of the stack.
        */
        _data_array_stack<T, Size_T, Stack_Size> data;

        /**
         * @fn lstax::static_bucket::stack_list()
         * @brief Construct a new static_bucket object.
         * 
         * @see lstax::bucket::bucket()
        */
        static_bucket() : BUCKET() {}

        /**
         * @fn lstax::static_bucket::~stack_list()
         * @brief Destroy the static_bucket object.
         * 
         * @see lstax::bucket::~bucket()
        */
        ~static_bucket() {}

        /**
         * @fn lstax::static_bucket::peek()
         * @brief Get the top element of the stack.
         * 
         * @return The top element of the stack.
         * @see lstax::data_structure::peek()
        */
        T& peek() override
        {
            return this->data[this->_top_index];
        }
    };

    BUCKET_TEMPLATE
    /**
     * @interface dynamic_bucket
     * @brief A stack of fixed size that uses a dynamically allocated array to store its data.
    */
    struct dynamic_bucket : public BUCKET
    {
        /**
         * @var lstax::dynamic_bucket::data
         * @brief The data of the stack.
        */
        _data_array_heap<T, Size_T, Stack_Size> data;

        /**
         * @fn lstax::dynamic_bucket::stack_list()
         * @brief Construct a new dynamic_bucket object.
         * 
         * @see lstax::bucket::bucket()
        */
        dynamic_bucket() : BUCKET() {}

        /**
         * @fn lstax::dynamic_bucket::~stack_list()
         * @brief Destroy the dynamic_bucket object.
         * 
         * @see lstax::bucket::~bucket()
        */
        ~dynamic_bucket() {}

        /**
         * @fn lstax::dynamic_bucket::peek()
         * @brief Get the top element of the stack.
         * 
         * @return The top element of the stack.
         * @see lstax::data_structure::peek()
        */
        T& peek() override
        {
            return this->data[this->_top_index];
        }
    };
}

#undef BUCKET_TEMPLATE
#undef BUCKET
#undef DATA_STRUCTURE