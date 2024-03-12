/*
* ==================== filo.hpp ====================
* First In Last Out variable-sized memory stack.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FILO_LIST_TEMPLATE template<typename Size_T, typename T>
#define FILO_LIST filo_list<Size_T, T>

#define FILO_LIST_LINK_TEMPLATE template<typename T>
#define FILO_LIST_LINK filo_list_link<T>

namespace lstax {

FILO_LIST_LINK_TEMPLATE
class filo_list_link {
public:
    T* data; // Pointer to stored data.
    FILO_LIST_LINK* next; // Pointer to the next link.

    
    filo_list_link(T* _data, FILO_LIST_LINK* _next = nullptr); // Creates a filo_list_link behind the given link, with the given data.

    ~filo_list_link(); // Deletes the filo_list_link, and associated data.
};


FILO_LIST_TEMPLATE
class filo_list : public stack<Size_T, T>
{
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FILO_LIST_LINK* top; // Pointer to the top link

    filo_list(); // Constructs a stack with no data
    filo_list(T* _data); // Constructs a stack with a single piece of data.

    ~filo_list(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    T* popOff(); // Returns the held data. Requires 1 additional pointer.

    T* operator[](size_t _index); // Indexing operator
};

} // namespace lstax

namespace lstax { // filo_list_link

FILO_LIST_LINK_TEMPLATE
FILO_LIST_LINK::filo_list_link(T* _data, FILO_LIST_LINK* _next = nullptr) : data(_data) {
    next = _next;
};

FILO_LIST_LINK_TEMPLATE
FILO_LIST_LINK::~filo_list_link() {
    delete data;
};

} // namespace lstax

namespace lstax { // filo_list

FILO_LIST_TEMPLATE
FILO_LIST::filo_list() : stack<T>(), length(0), top(nullptr) {};

FILO_LIST_TEMPLATE
FILO_LIST::filo_list(T* _data) : stack<T>(), length(1), top(new FILO_LIST_LINK(_data)) {};

FILO_LIST_TEMPLATE
FILO_LIST::~filo_list() {
    FILO_LIST_LINK* bottom;
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FILO_LIST_TEMPLATE
void FILO_LIST::push(const T* _data) {
    top = new FILO_LIST_LINK(_data, top);
    ++length;
};

FILO_LIST_TEMPLATE
void FILO_LIST::push(const T& _data) {
    push(*_data);
};


FILO_LIST_TEMPLATE
T* FILO_LIST::top() {
    return top->data;
};

FILO_LIST_TEMPLATE
void FILO_LIST::pop() {
    FILO_LIST_LINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FILO_LIST_TEMPLATE
T* FILO_LIST::popOff() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FILO_LIST_TEMPLATE
T* FILO_LIST::operator[](size_t _index) {
    FILO_LIST_LINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FILO_LIST_TEMPLATE
Size_T FILO_LIST::length() {
    return length;
};

} // namespace lstax


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK