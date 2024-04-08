#pragma once

/**
 * @file filo_stack.hpp
 * @brief A stack of fixed size that follows the First In, Last Out (FILO) principle.
 */

#include "stack_list.hpp"

#define FILO_STACK_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define FILO_STACK filo_stack<T, Size_T, Stack_Size>
#define STACK_LIST stack_list<T, Size_T, Stack_Size>

namespace lstax
{
    FILO_STACK_TEMPLATE
    /**
     * @class filo_stack
     * @brief A stack of fixed sixe that follows the First In, Last Out (FILO) principle.
     */
    struct filo_stack : STACK_LIST
    {
        /**
         * @fn lstax::filo_stack::filo_stack()
         * @brief Construct a new filo_stack object.
         * 
         * @see lstax::stack_list::stack_list()
         */
        filo_stack() : STACK_LIST() {}
        /**
         * @fn lstax::filo_stack::~filo_stack()
         * @brief Destroy the filo_stack object.
         * 
         * @see lstax::stack_list::~stack_list()
         */
        ~filo_stack() {}

        /**
         * @fn lstax::filo_stack::push(const T& _data)
         * @brief Add an element to the top of the stack.
         * 
         * @param _data The _data to add to the stack.
         * 
         * @see lstax::stack::push()
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
         * @fn lstax::filo_stack::pop()
         * @brief Remove the top element of the stack.
        */
        void pop() override
        {
            this->_decrement_length();
            this->_decrement_top();
        }
    };
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK
#undef STACK_LIST