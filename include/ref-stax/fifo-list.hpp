/*
* ==================== fifo.hpp ====================
* First In First Out variable-sized memory queue.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>

#include "stack.hpp"

#define FIFOLIST_TEMPLATE_DECL template<typename Size_T = size_t, typename T>
#define FIFOLIST_TEMPLATE template<typename Size_T, typename T>
#define FIFOLIST FifoList<Size_T, T>

#define FIFOLINK_TEMPLATE template<typename T>
#define FIFOLINK FifoLink<T>

namespace lstax {

FIFOLINK_TEMPLATE
class FifoLink {
public:
    T* data; // Pointer to stored data.
    FIFOLINK* next; // Pointer to the next link.

    
    FifoLink(T* _data, FIFOLINK* _previous = nullptr); // Creates a FifoLink behind the given link, with the given data.

    ~FifoLink(); // Deletes the FifoLink, and associated data.
};


FIFOLIST_TEMPLATE_DECL
class FifoList : public Stack<Size_T, T> {
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FIFOLINK* top; // Pointer to the top link (pop target)
    FIFOLINK* bottom; // Pointer to the bottom link (push target)

    FifoList(); // Constructs a stack with no data
    FifoList(T* _data); // Constructs a stack with a single piece of data.

    ~FifoList(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    T* popOff(); // Returns the held data. Requires 1 additional pointer.

    T* operator[](size_t _index); // Indexing operator
};

} // namespace lstax

namespace lstax { // FifoLink

FIFOLINK_TEMPLATE
FIFOLINK::FifoLink(T* _data, FIFOLINK* _previous = nullptr) : data(_data) {
    if (_previous != nullptr) _previous->next = this;
};

FIFOLINK_TEMPLATE
FIFOLINK::~FifoLink() {
    delete data;
};

} // namespace lstax

namespace lstax { // FifoList

FIFOLIST_TEMPLATE
FIFOLIST::FifoList() : Stack<T>(), length(0), top(nullptr), bottom(nullptr) {};

FIFOLIST_TEMPLATE
FIFOLIST::FifoList(T* _data) : Stack<T>(), length(1), top(new FIFOLINK(_data)), bottom(top) {};

FIFOLIST_TEMPLATE
FIFOLIST::~FifoList() {
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FIFOLIST_TEMPLATE
void FIFOLIST::push(const T* _data) {
    bottom = new FIFOLINK(_data, bottom);
    ++length;
};

FIFOLIST_TEMPLATE
void FIFOLIST::push(const T& _data) {
    push(*_data);
};


FIFOLIST_TEMPLATE
T* FIFOLIST::top() {
    return top->data;
};

FIFOLIST_TEMPLATE
void FIFOLIST::pop() {
    FIFOLINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FIFOLIST_TEMPLATE
T* FIFOLIST::popOff() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FIFOLIST_TEMPLATE
T* FIFOLIST::operator[](size_t _index) {
    FIFOLINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FIFOLIST_TEMPLATE
Size_T FIFOLIST::length() {
    return length;
};

} // namespace lstax


#undef FIFOLIST_TEMPLATE
#undef FIFO

#undef FIFOLINK_TEMPLATE
#undef FIFOLINK
