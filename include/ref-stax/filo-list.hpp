/*
* ==================== filo.hpp ====================
* First In Last Out variable-sized memory stack.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>

#include "stack.hpp"

#define FILOLIST_TEMPLATE_DECL template<typename Size_T = size_t, typename T>
#define FILOLIST_TEMPLATE template<typename Size_T, typename T>
#define FILOLIST FiloList<Size_T, T>

#define FILOLINK_TEMPLATE template<typename T>
#define FILOLINK FiloLink<T>

namespace lstax {

FILOLINK_TEMPLATE
class FiloLink {
public:
    T* data; // Pointer to stored data.
    FILOLINK* next; // Pointer to the next link.

    
    FiloLink(T* _data, FILOLINK* _next = nullptr); // Creates a FiloLink behind the given link, with the given data.

    ~FiloLink(); // Deletes the FiloLink, and associated data.
};


FILOLIST_TEMPLATE_DECL
class FiloList : public Stack<Size_T, T>
{
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FILOLINK* top; // Pointer to the top link

    FiloList(); // Constructs a stack with no data
    FiloList(T* _data); // Constructs a stack with a single piece of data.

    ~FiloList(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    T* popOff(); // Returns the held data. Requires 1 additional pointer.

    T* operator[](size_t _index); // Indexing operator
};

} // namespace lstax

namespace lstax { // FiloLink

FILOLINK_TEMPLATE
FILOLINK::FiloLink(T* _data, FILOLINK* _next = nullptr) : data(_data) {
    next = _next;
};

FILOLINK_TEMPLATE
FILOLINK::~FiloLink() {
    delete data;
};

} // namespace lstax

namespace lstax { // FiloList

FILOLIST_TEMPLATE
FILOLIST::FiloList() : Stack<T>(), length(0), top(nullptr) {};

FILOLIST_TEMPLATE
FILOLIST::FiloList(T* _data) : Stack<T>(), length(1), top(new FILOLINK(_data)) {};

FILOLIST_TEMPLATE
FILOLIST::~FiloList() {
    FILOLINK* bottom;
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FILOLIST_TEMPLATE
void FILOLIST::push(const T* _data) {
    top = new FILOLINK(_data, top);
    ++length;
};

FILOLIST_TEMPLATE
void FILOLIST::push(const T& _data) {
    push(*_data);
};


FILOLIST_TEMPLATE
T* FILOLIST::top() {
    return top->data;
};

FILOLIST_TEMPLATE
void FILOLIST::pop() {
    FILOLINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FILOLIST_TEMPLATE
T* FILOLIST::popOff() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FILOLIST_TEMPLATE
T* FILOLIST::operator[](size_t _index) {
    FILOLINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FILOLIST_TEMPLATE
Size_T FILOLIST::length() {
    return length;
};

} // namespace lstax


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK