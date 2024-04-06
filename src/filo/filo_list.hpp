#pragma once

#include "link.hpp"
#include "stack.hpp"

#define FILO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FILO_LIST filo_list<T, Size_T>
#define STACK stack<T, Size_T>
#define LINK link<T>

namespace lstax
{
    FILO_LIST_TEMPLATE
    struct filo_list : STACK
    {
        LINK* top;

        filo_list() : top(nullptr), STACK() {};
        ~filo_list() {};

        void push(const T _data) {
            top = new LINK(_data, top);
            ++this->length;
        };

        void pop() {
            LINK* temp = top;
            top = temp->next;
            --this->length;
            delete temp;
        };

        T peek() const {
            return top->data;
        };
    };
} // namespace lstax

#undef FILO_LIST_TEMPLATE
#undef FILO_LIST
#undef STACK
#undef LINK