#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FIFO_BLOCK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define FIFO_STACK fifo_block<Size_T, T, size>

namespace lstax
{
FIFO_BLOCK_TEMPLATE
class fifo_block : stack<Size_T, T>
{
public:
    T* data[size];
    Size_T bottom; // The first empty index

    fifo_block();
    fifo_block(T* _data);
    ~fifo_block(); // Deletes all data. Iterates through the whole array in order to ensure memory cleanup.

    T* top();

    void pop(); // Deletes the top element.
    void pop(T* _data); // Marks the top element as empty. Sets the given pointer to the data.
    T* popOff();

    void push(const T* _data);
    void push(const T& _data);

    T* operator[](Size_T _index);
};
}

namespace lstax
{
FIFO_BLOCK_TEMPLATE
FIFO_STACK::fifo_block() : stack<Size_T, T>, top(0) {
    //
};
FIFO_BLOCK_TEMPLATE
FIFO_STACK::fifo_block(T* _data) : stack<Size_T, T>, top(1) {
    data[0] = _data;
};
FIFO_BLOCK_TEMPLATE
FIFO_STACK::~fifo_block() {
    for (Size_T i = 0; i < size; ++i) {
        delete data[i];
    }
};

FIFO_BLOCK_TEMPLATE
T* FIFO_STACK::top() {
    return data[0];
};

FIFO_BLOCK_TEMPLATE
void FIFO_STACK::pop() {
    delete data[0];
    for (Size_T i = 0; i < size;) {
        data[i] = data[++i];
    }
    --top;
};
FIFO_BLOCK_TEMPLATE
void FIFO_STACK::pop(T* _data) {
    _data = top();
    for (Size_T i = 0; i < size;) {
        data[i] = data[++i];
    }
    --top;
};
FIFO_BLOCK_TEMPLATE
T* FIFO_STACK::popOff() {
    T* temp = top();
    pop();
    return temp;
};

FIFO_BLOCK_TEMPLATE
void FIFO_STACK::push(const T* _data) {
    data[bottom++] = _data;
};
FIFO_BLOCK_TEMPLATE
void FIFO_STACK::push(const T& _data) {
    push(&_data);
};

FIFO_BLOCK_TEMPLATE
T* FIFO_STACK::operator[](Size_T _index) {
    return data[_index];
};
}

#undef FIFO_STACK_TEMPLATE
#undef FIFO_STACK