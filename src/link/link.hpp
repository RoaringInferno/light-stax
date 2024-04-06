#pragma once

#define LINK_TEMPLATE template<typename T>
#define LINK link<T>

namespace lstax
{
    LINK_TEMPLATE
    struct link
    {
        T data;
        LINK* next;

        link() : next(nullptr) {};
        link(const T &_data, LINK* _next = nullptr) : data(_data), next(_next) {};
        ~link() {};
    };
} // namespace lstax

#undef LINK_TEMPLATE
#undef LINK