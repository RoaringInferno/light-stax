#pragma once

/**
 * @file stack_list.hpp
 * @brief A stack of fixed size that uses an array to store its data.
*/

#include "data_structure.hpp"

#define STACK_LIST_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define STACK_LIST stack_list<T, Size_T, Stack_Size>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    STACK_LIST_TEMPLATE
    /**
     * @class stack_list
     * @brief A stack of fixed size that uses an array to store its data.
    */
    struct stack_list : public DATA_STRUCTURE
    {
        /**
         * @fn lstax::stack_list::_increment_top()
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
         * @fn lstax::stack_list::_increment_top()
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
         * @var lstax::stack_list::top
         * @brief The index of the top element of the stack.
        */
        Size_T top;
        /**
         * @var lstax::stack_list::data
         * @brief The data of the stack.
        */
        T data[Stack_Size];

        /**
         * @fn lstax::stack_list::stack_list()
         * @brief Construct a new stack_list object.
         * 
         * @see lstax::data_structure::data_structure()
        */
        stack_list() : top(0), DATA_STRUCTURE() {}

        /**
         * @fn lstax::stack_list::~stack_list()
         * @brief Destroy the stack_list object.
         * 
         * @see lstax::data_structure::~data_structure()
        */
        ~stack_list() {}

        /**
         * @fn lstax::stack_list::peek() const
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

#undef STACK_LIST_TEMPLATE
#undef STACK_LIST