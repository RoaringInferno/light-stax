#pragma once

#include "stack.hpp"
#include "stackexcept.hpp"

#define STACK_LIST_TEMPLATE template <typename T, typename Size_T, Size_T Stack_Size>
#define STACK_LIST stack_list<T, Size_T, Stack_Size>
#define STACK stack<T, Size_T>

namespace lstax
{
    STACK_LIST_TEMPLATE
    struct stack_list : public STACK
    {
        T data[Stack_Size];
        Size_T top;

        stack_list() : STACK() {}

        /**
         * @fn lstax::stack_list::pop()
         * @brief Remove the top element of the stack
         * 
         * Cycles through the stack and shifts all elements to the left.
         * Does not delete the penultimate element.
        */
        void pop() override
        {
            if (this->length-- == 0)
            {
                throw stack_underflow();
            }
            ++this->top;
            if (this->top == Stack_Size)
            {
                this->top = 0;
            }
        }
    };
}

#undef STACK_LIST_TEMPLATE
#undef STACK_LIST