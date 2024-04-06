#pragma once

#include "link.hpp"
#include "stack.hpp"

#define LINKED_LIST_TEMPLATE template<typename T, typename Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define STACK stack<T, Size_T>
#define LINK link<T>

namespace lstax
{
    LINKED_LIST_TEMPLATE
    struct linked_list : STACK {
        LINK* top;

        linked_list() : top(nullptr), STACK() {};
        ~linked_list() {
            while (this->top != nullptr) {
                LINK* temp = this->top;
                this->top = this->top->next;
                delete temp;
            }
        };

        void pop() override {
            LINK* temp = this->top;
            this->top = temp->next;
            --this->length;
            delete temp;
        };

        T peek() const override {
            return this->top->data;
        };
    };
} // namespace lstax

#undef LINKED_LIST_TEMPLATE
#undef LINKED_LIST
#undef STACK
#undef LINK