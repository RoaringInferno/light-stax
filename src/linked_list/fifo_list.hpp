#pragma once

#include "linked_list.hpp"

#define FIFO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FIFO_LIST fifo_list<T, Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define LINK link<T>

namespace lstax
{
    FIFO_LIST_TEMPLATE
    struct fifo_list : LINKED_LIST
    {
        LINK* bottom;

        fifo_list() : LINKED_LIST() {};
        ~fifo_list() {};

        void push(const T& _data) override {
            if (this->length != 0) {
                LINK* temp = new LINK(_data);
                this->bottom->next = temp;
                this->bottom = temp;
            } else {
                this->bottom = new LINK(_data);
                this->top = this->bottom;
            }
            ++this->length;
        };
    };
} // namespace lstax

#undef FIFO_LIST_TEMPLATE
#undef FIFO_LIST
#undef LINKED_LIST
#undef LINK