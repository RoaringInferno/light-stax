/*
* ==================== fifo.hpp ====================
* First In First Out variable-sized memory queue.
* Stores pointers to data.
*/

#pragma once

#include <cstddef>
#include <stdexcept>

#define FIFO_TEMPLATE template<typename T>
#define FIFO Fifo<T>

#define FIFO_LINK_TEMPLATE template<typename T>
#define FIFO_LINK Fifo_Link<T>

namespace lstax {

FIFO_LINK_TEMPLATE
class Fifo_Link {
public:
    T* data; // Pointer to stored data.
    FIFO_LINK* next; // Pointer to the next link.

    
    Fifo_Link(T* _data, FIFO_LINK* _previous = nullptr); // Creates a Fifo_Link behind the given link, with the given data.

    ~Fifo_Link(); // Deletes the Fifo_Link, and associated data.
};


FIFO_TEMPLATE
class Fifo : public Stack {
public:
    size_t length; // Length of the stack.
    size_t length(); // Returns the length

    FIFO_LINK* top; // Pointer to the top link (pop target)
    FIFO_LINK* bottom; // Pointer to the bottom link (push target)

    Fifo(); // Constructs a stack with no data
    Fifo(T* _data); // Constructs a stack with a single piece of data.

    ~Fifo(); // Deletes all links and all data.


    void push(const T* _data); // Adds a link with the given data.
    void push(const T& _data); // Adds a link with the given data.

    T* top(); // Views the top element.
    void pop();  // Removes the top element.
    T* pop_off(); // Returns the held data. Requires 1 additional pointer.

    T* operator[](size_t _index); // Indexing operator
};

} // namespace lstax

namespace lstax { // Fifo_Link

FIFO_LINK_TEMPLATE
FIFO_LINK::Fifo_Link(T* _data, FIFO_LINK* _previous = nullptr) : data(_data) {
    if (_previous != nullptr) _previous->next = this;
};

FIFO_LINK_TEMPLATE
FIFO_LINK::~Fifo_Link() {
    delete data;
};

} // namespace lstax

namespace lstax { // Fifo

FIFO_TEMPLATE
FIFO::Fifo() : length(0), top(nullptr), bottom(nullptr), Stack() {};

FIFO_TEMPLATE
FIFO::Fifo(T* _data) : length(1), top(new FIFO_LINK(_data)), bottom(top), Stack() {};

FIFO_TEMPLATE
FIFO::~Fifo() {
    for (size_t i = 0; i < length; ++i)
    {
        bottom = top->next;
        delete top;
        top = bottom;
    }
};

FIFO_TEMPLATE
void FIFO::push(const T* _data) {
    bottom = new FIFO_LINK(_data, bottom);
    ++length;
};

FIFO_TEMPLATE
void FIFO::push(const T& _data) {
    push(*_data);
};


FIFO_TEMPLATE
T* FIFO::top() {
    return top->data;
};

FIFO_TEMPLATE
void FIFO::pop() {
    FIFO_LINK* interm = top->next;
    delete top;
    top = interm;
    --length;
};

FIFO_TEMPLATE
T* FIFO::pop_off() {
    T* data = top->data;
    top->data = nullptr;
    pop();
    return data;
};

FIFO_TEMPLATE
T* FIFO::operator[](size_t _index) {
    if (_index >= length) {throw std::out_of_range("Index out of bounds");}
    FIFO_LINK* target = top;
    for (size_t i = 0; i < _index; ++i) {
        target = target->next;
    }
    return target->data;
};

FIFO_TEMPLATE
size_t FIFO::length() {
    return length;
};

} // namespace lstax


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK
