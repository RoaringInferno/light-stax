#pragma once

#include "link.hpp"
#include "stack.hpp"

#define FIFO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FIFO_LIST fifo_list<T, Size_T>
#define STACK stack<T, Size_T>
#define LINK link<T>

namespace lstax
{
    FIFO_LIST_TEMPLATE
    struct fifo_list : STACK
    {
        LINK* bottom;
        LINK* top;

        fifo_list() : top(nullptr), STACK() {};
        ~fifo_list() {};

        void push(const T _data) {
            if (this->length != 0) {
                LINK* temp = new LINK(_data);
                bottom->next = temp;
                bottom = temp;
            } else {
                bottom = new LINK(_data);
                top = bottom;
            }
            ++this->length;
        };

        void pop() {
            LINK* temp = top;
            top = temp->next;
            delete temp;
            --this->length;
        };

        T peek() const {
            return top->data;
        };
    };
} // namespace lstax

#undef FIFO_LIST_TEMPLATE
#undef FIFO_LIST
#undef STACK
#undef LINK