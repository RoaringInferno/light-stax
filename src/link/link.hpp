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

        Link(const LINK* _next = nullptr) : next(_next) {};
        Link(const T _data, const LINK* _next = nullptr) : data(_data), next(_next) {};
        ~Link() {delete data};
    };
} // namespace lstax

#undef LINK_TEMPLATE
#undef LINK