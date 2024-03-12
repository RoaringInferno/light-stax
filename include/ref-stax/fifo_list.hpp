/*
* ==================== fifo.hpp ====================
* First In First Out variable-sized memory queue.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FIFO_LIST_TEMPLATE template<typename Size_T, typename T>
#define FIFO_LIST fifo_list<Size_T, T>

#define FIFO_LIST_LINK_TEMPLATE template<typename T>
#define FIFO_LIST_LINK fifo_list_link<T>

namespace lstax {

FIFO_LIST_LINK_TEMPLATE
class fifo_list_link {
public:
    T* data; // Pointer to stored data.
    FIFO_LIST_LINK* next; // Pointer to the next link.

    
    fifo_list_link(T* _data, FIFO_LIST_LINK* _previous = nullptr); // Creates a fifo_list_link behind the given link, with the given data.

    ~fifo_list_link(); // Deletes the fifo_list_link, and associated data.
};


FIFO_LIST_TEMPLATE
class fifo_list : public stack<Size_T, T> {
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FIFO_LIST_LINK* top; // Pointer to the top link (pop target)
    FIFO_LIST_LINK* bottom; // Pointer to the bottom link (push target)

    fifo_list(); // Constructs a stack with no data
    fifo_list(T* _data); // Constructs a stack with a single piece of data.

    ~fifo_list(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    T* popOff(); // Returns the held data. Requires 1 additional pointer.

    T* operator[](size_t _index); // Indexing operator
};

} // namespace lstax

namespace lstax { // fifo_list_link

FIFO_LIST_LINK_TEMPLATE
FIFO_LIST_LINK::fifo_list_link(T* _data, FIFO_LIST_LINK* _previous = nullptr) : data(_data) {
    if (_previous != nullptr) _previous->next = this;
};

FIFO_LIST_LINK_TEMPLATE
FIFO_LIST_LINK::~fifo_list_link() {
    delete data;
};

} // namespace lstax

namespace lstax { // fifo_list

FIFO_LIST_TEMPLATE
FIFO_LIST::fifo_list() : stack<T>(), length(0), top(nullptr), bottom(nullptr) {};

FIFO_LIST_TEMPLATE
FIFO_LIST::fifo_list(T* _data) : stack<T>(), length(1), top(new FIFO_LIST_LINK(_data)), bottom(top) {};

FIFO_LIST_TEMPLATE
FIFO_LIST::~fifo_list() {
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FIFO_LIST_TEMPLATE
void FIFO_LIST::push(const T* _data) {
    bottom = new FIFO_LIST_LINK(_data, bottom);
    ++length;
};

FIFO_LIST_TEMPLATE
void FIFO_LIST::push(const T& _data) {
    push(*_data);
};


FIFO_LIST_TEMPLATE
T* FIFO_LIST::top() {
    return top->data;
};

FIFO_LIST_TEMPLATE
void FIFO_LIST::pop() {
    FIFO_LIST_LINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FIFO_LIST_TEMPLATE
T* FIFO_LIST::popOff() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FIFO_LIST_TEMPLATE
T* FIFO_LIST::operator[](size_t _index) {
    FIFO_LIST_LINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FIFO_LIST_TEMPLATE
Size_T FIFO_LIST::length() {
    return length;
};

} // namespace lstax


#undef FIFO_LIST_TEMPLATE
#undef FIFO

#undef FIFO_LIST_LINK_TEMPLATE
#undef FIFO_LIST_LINK
