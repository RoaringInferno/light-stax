/*
* ==================== filo.hpp ====================
* First In Last Out variable-sized memory stack.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>
#include <stdexcept>

#define FILO_TEMPLATE_DECL template<typename Size_T = size_t, typename T>
#define FILO_TEMPLATE template<typename Size_T, typename T>
#define FILO Filo<Size_T, T>

#define FILO_LINK_TEMPLATE template<typename T>
#define FILO_LINK Filo_Link<T>

namespace lstax {

FILO_LINK_TEMPLATE
class Filo_Link {
public:
    T* data; // Pointer to stored data.
    FILO_LINK* next; // Pointer to the next link.

    
    Filo_Link(T* _data, FILO_LINK* _next = nullptr); // Creates a Filo_Link behind the given link, with the given data.

    ~Filo_Link(); // Deletes the Filo_Link, and associated data.
};


FILO_TEMPLATE_DECL
class Filo : public Stack<Size_T, T>
{
public:
    Size_T length; // Length of the stack.
    Size_T length(); // Returns the length

    FILO_LINK* top; // Pointer to the top link

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

namespace lstax { // Filo_Link

FILO_LINK_TEMPLATE
FILO_LINK::Filo_Link(T* _data, FILO_LINK* _next = nullptr) : data(_data) {
    next = _next;
};

FILO_LINK_TEMPLATE
FILO_LINK::~Filo_Link() {
    delete data;
};

} // namespace lstax

namespace lstax { // Filo

FILO_TEMPLATE
FILO::Filo() : Stack<T>(), length(0), top(nullptr) {};

FILO_TEMPLATE
FILO::Filo(T* _data) : Stack<T>(), length(1), top(new FILO_LINK(_data)) {};

FILO_TEMPLATE
FILO::~Filo() {
    FILO_LINK* bottom;
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FILO_TEMPLATE
void FILO::push(const T* _data) {
    top = new FILO_LINK(_data, top);
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
    FILO_LINK* interm = top->next;
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
    if (_index >= length) {throw std::out_of_range("Index out of bounds");}
    FILO_LINK* target = top;
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