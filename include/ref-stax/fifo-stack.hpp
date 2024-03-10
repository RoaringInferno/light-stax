#pragma once

#include <cstddef>

#include "stack.hpp"

#define FIFOSTACK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define FIFOSTACK FifoStack<Size_T, T, size>

namespace lstax
{
FIFOSTACK_TEMPLATE
class FifoStack : Stack<Size_T, T>
{
public:
    T* data[size];
    Size_T top; // The first empty index

    FifoStack();
    FifoStack(T* _data);
    ~FifoStack(); // Deletes all data. Iterates through the whole array in order to ensure memory cleanup.

    T* top();

    void pop();
    void pop(T* _data);
    T* popOff();

    void push(const T* _data);
    void push(const T& _data);

    T* operator[](Size_T _index);
};
}

namespace lstax
{
FIFOSTACK_TEMPLATE
FIFOSTACK::FifoStack() : Stack<Size_T, T>, top(0) {
    //
};
FIFOSTACK_TEMPLATE
FIFOSTACK::FifoStack(T* _data) : Stack<Size_T, T>, top(1) {
    data[0] = _data;
};
FIFOSTACK_TEMPLATE
FIFOSTACK::~FifoStack() {
    for (Size_T i = 0; i < size; ++i) {
        delete data[i];
    }
};

FIFOSTACK_TEMPLATE
T* FIFOSTACK::top() {
    return data[0];
};

FIFOSTACK_TEMPLATE
void FIFOSTACK::pop() {
    delete data[0];
    for (Size_T i = 0; i < size;) {
        data[i] = data[++i];
    }
    --top;
};
FIFOSTACK_TEMPLATE
void FIFOSTACK::pop(T* _data) {
    _data = top();
    pop();
};
FIFOSTACK_TEMPLATE
T* FIFOSTACK::popOff() {
    T* temp = top();
    pop();
    return temp;
};

FIFOSTACK_TEMPLATE
void FIFOSTACK::push(const T* _data) {
    data[top++] = _data;
};
FIFOSTACK_TEMPLATE
void FIFOSTACK::push(const T& _data) {
    push(&_data);
};

FIFOSTACK_TEMPLATE
T* FIFOSTACK::operator[](Size_T _index) {
    return data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK