#pragma once

#define STACK_TEMPLATE template<typename T, typename Size_T>
#define STACK stack<T, Size_T>

namespace lstax
{
    STACK_TEMPLATE
    struct stack
    {
        Size_T length;
        
        stack() : length(0) {};
        ~stack() {};

        virtual void push(const T _data) = 0;
        virtual void pop() = 0;
        virtual T peek() const = 0;
    };
} // namespace lstax

#undef STACK_TEMPLATE
#undef STACK