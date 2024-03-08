#pragma once

#include <cstddef>
#include <stdexcept>

#include "stack.hpp"

#define LITFIFOSTACK_TEMPLATE_DECL template<typename Size_T = size_t, typename T, Size_T size>
#define LITFIFOSTACK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define LITFIFOSTACK LitFifoStack<Size_T, T, size>

namespace lstax
{
LITFIFOSTACK_TEMPLATE_DECL
class LitFifoStack : Stack<Size_T, T>
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

    bool push(const T* _data); // Returns true if the push was successful. If the stack is full, returns false.
    bool push(const T& _data); // Returns true if the push was successful. If the stack is full, returns false.

    T* operator[](Size_T _index);
};
}

namespace lstax
{
LITFIFOSTACK_TEMPLATE
LITFIFOSTACK::LitFifoStack() : Stack<Size_T, T>, top(0) {
    //
};
LITFIFOSTACK_TEMPLATE
LITFIFOSTACK::LitFifoStack(T* _data) : Stack<Size_T, T>, top(1) {
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
bool LITFIFOSTACK::push(const T* _data) {
    return push(*_data);
};
LITFIFOSTACK_TEMPLATE
bool LITFIFOSTACK::push(const T& _data) {
    if (top == size) return false;
    data[top++] = _data;
    return true;
};

LITFIFOSTACK_TEMPLATE
T* LITFIFOSTACK::operator[](Size_T _index) {
    if (_index >= top) throw std::out_of_range("Index out of range");
    return &data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK