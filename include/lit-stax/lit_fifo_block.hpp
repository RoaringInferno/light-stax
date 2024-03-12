#pragma once

#include <cstddef>

#include "stack.hpp"

#define LITFIFOSTACK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define LITFIFOSTACK LitFifoStack<Size_T, T, size>

namespace lstax
{
LITFIFOSTACK_TEMPLATE
class LitFifoStack : stack<Size_T, T>
{
public:
    T data[size];
    Size_T top; // The first empty index

    LitFifoStack();
    LitFifoStack(T* _data);
    ~LitFifoStack(); // Deletes all data. Iterates through the whole array in order to ensure memory cleanup.

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
LITFIFOSTACK_TEMPLATE
LITFIFOSTACK::LitFifoStack() : stack<Size_T, T>, top(0) {
    //
};
LITFIFOSTACK_TEMPLATE
LITFIFOSTACK::LitFifoStack(T* _data) : stack<Size_T, T>, top(1) {
    data[0] = _data;
};
LITFIFOSTACK_TEMPLATE
LITFIFOSTACK::~LitFifoStack() {
    for (Size_T i = 0; i < size; ++i) {
        delete data[i];
    }
};

LITFIFOSTACK_TEMPLATE
T* LITFIFOSTACK::top() {
    return &data[0];
};

LITFIFOSTACK_TEMPLATE
void LITFIFOSTACK::pop() {
    delete data[0];
    for (Size_T i = 0; i < size;) {
        data[i] = data[++i];
    }
    --top;
};
LITFIFOSTACK_TEMPLATE
void LITFIFOSTACK::pop(T* _data) {
    _data = &top();
    pop();
};
LITFIFOSTACK_TEMPLATE
T* LITFIFOSTACK::popOff() {
    T* temp = top();
    pop();
    return temp;
};

LITFIFOSTACK_TEMPLATE
void LITFIFOSTACK::push(const T* _data) {
    push(*_data);
};
LITFIFOSTACK_TEMPLATE
void LITFIFOSTACK::push(const T& _data) {
    data[top++] = _data;
};

LITFIFOSTACK_TEMPLATE
T* LITFIFOSTACK::operator[](Size_T _index) {
    return &data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK