/*
* ==================== filo.hpp ====================
* First In Last Out variable-sized memory stack.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>

#include "stack.hpp"

#define FILO_TEMPLATE_DECL template<typename Size_T = size_t, typename T>
#define FILO_TEMPLATE template<typename Size_T, typename T>
#define FILO Filo<Size_T, T>

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


FILO_TEMPLATE_DECL
class Filo : public Stack<Size_T, T>
{
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FILOLINK* top; // Pointer to the top link

    Filo(); // Constructs a stack with no data
    Filo(T* _data); // Constructs a stack with a single piece of data.

    ~Filo(); // Deletes all links and all data.


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

namespace lstax { // Filo

FILO_TEMPLATE
FILO::Filo() : Stack<T>(), length(0), top(nullptr) {};

FILO_TEMPLATE
FILO::Filo(T* _data) : Stack<T>(), length(1), top(new FILOLINK(_data)) {};

FILO_TEMPLATE
FILO::~Filo() {
    FILOLINK* bottom;
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FILO_TEMPLATE
void FILO::push(const T* _data) {
    top = new FILOLINK(_data, top);
    ++length;
};

FILO_TEMPLATE
void FILO::push(const T& _data) {
    push(*_data);
};


FILO_TEMPLATE
T* FILO::top() {
    return top->data;
};

FILO_TEMPLATE
void FILO::pop() {
    FILOLINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FILO_TEMPLATE
T* FILO::popOff() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FILO_TEMPLATE
T* FILO::operator[](size_t _index) {
    FILOLINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FILO_TEMPLATE
Size_T FILO::length() {
    return length;
};

} // namespace lstax


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK