#pragma once

#include "linked_list.hpp"

#define FILO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FILO_LIST filo_list<T, Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define LINK link<T>

namespace lstax
{
    FILO_LIST_TEMPLATE
    struct filo_list : LINKED_LIST
    {
        filo_list() : LINKED_LIST() {};
        ~filo_list() {};

        void push(const T _data) override {
            this->top = new LINK(_data, this->top);
            ++this->length;
        };
    };
} // namespace lstax

#undef FILO_LIST_TEMPLATE
#undef FILO_LIST
#undef LINKED_LIST
#undef LINK