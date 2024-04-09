#pragma once

/**
 * @file fifo_stack.hpp
 * @brief A stack of fixed size that follows the First In, First Out (FIFO) principle.
 */

#include "stack_list.hpp"

#define FIFO_STACK_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define FIFO_STACK fifo_stack<T, Size_T, Stack_Size>
#define STACK_LIST stack_list<T, Size_T, Stack_Size>

namespace lstax
{
    FIFO_STACK_TEMPLATE
    /**
     * @class fifo_stack
     * @brief A stack of fixed sixe that follows the First In, First Out (FIFO) principle.
     */
    struct fifo_stack : STACK_LIST
    {
        /**
         * @fn lstax::fifo_stack::_increment_bottom()
         * @brief Increment the bottom index of the stack.
         */
        void _increment_bottom() {
            if (++this->bottom == Stack_Size) {
                this->bottom = 0;
            }
        }

        /**
         * @val lstax::fifo_stack::bottom
         * @brief The index of the bottom element of the stack.
         * 
         * This is the push point for the stack.
        */
        Size_T bottom;

        /**
         * @fn lstax::fifo_stack::fifo_stack()
         * @brief Construct a new fifo_stack object.
         * 
         * @see lstax::stack_list::stack_list()
         */
        fifo_stack() : bottom(0), STACK_LIST() {}
        /**
         * @fn lstax::fifo_stack::~fifo_stack()
         * @brief Destroy the fifo_stack object.
         * 
         * @see lstax::stack_list::~stack_list()
         */
        ~fifo_stack() {}

        /**
         * @fn lstax::fifo_stack::push(const T& _data)
         * @brief Add an element to the top of the stack.
         * 
         * If an element is added and the stack is at capacity, the oldest _data will be overwritten.
         * 
         * @param _data The _data to add to the stack.
         * 
         * @see lstax::stack::push()
        */
        void push(const T& _data) override
        {
            if (this->length != 0)
            {
                this->_increment_bottom();
            }
            this->data[this->bottom].value = _data;
            ++this->length;
        }

        /**
         * @fn lstax::fifo_stack::pop()
         * @brief Remove the top element of the stack.
        */
        void pop() override
        {
            this->_decrement_length();
            this->_increment_top();
        }
    };
}

#undef FIFO_STACK_TEMPLATE
#undef FIFO_STACK
#undef STACK_LIST