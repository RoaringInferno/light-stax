/*
* ==================== filo.hpp ====================
* First In Last Out variable-sized memory stack.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>
#include <stdexcept>

#define FILO_TEMPLATE template<typename T>
#define FILO Filo<T>

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


FILO_TEMPLATE
class Filo : public Stack {
public:
    size_t length; // Length of the stack.
    size_t length(); // Returns the length

    FILO_LINK* top; // Pointer to the top link

    Filo(); // Constructs a stack with no data
    Filo(T* _data); // Constructs a stack with a single piece of data.

    ~Filo(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    void pop(T* _data); // Removes the top element. Overwrites the given pointer with a pointer to the data.
    T* pop_off(); // Returns the held data. Requires 1 additional pointer.

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
FILO::Filo() : length(0), top(nullptr), Stack() {};

FILO_TEMPLATE
FILO::Filo(T* _data) : length(1), top(new FILO_LINK(_data)), Stack() {};

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
void FILO::pop(T* _data) {
    _data = top->data;
    pop();
};

FILO_TEMPLATE
T* FILO::pop_off() {
    T* data = top->data;
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
size_t FILO::length() {
    return length;
};

} // namespace lstax


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK