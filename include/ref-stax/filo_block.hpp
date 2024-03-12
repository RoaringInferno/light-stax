#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FILO_BLOCK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define FILO_BLOCK filo_block<Size_T, T, size>

namespace lstax
{
FILO_BLOCK_TEMPLATE
class filo_block : stack<Size_T, T>
{
public:
    T* data[size];
    Size_T top; // The first empty index

    filo_block();
    filo_block(T* _data);
    ~filo_block(); // Deletes all data. Iterates through the whole array in order to ensure memory cleanup.

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
FILO_BLOCK_TEMPLATE
FILO_BLOCK::filo_block() : stack<Size_T, T>(), top(0) {
    //
};
FILO_BLOCK_TEMPLATE
FILO_BLOCK::filo_block(T* _data) : stack<Size_T, T>(), top(1) {
    data[0] = _data;
};
FILO_BLOCK_TEMPLATE
FILO_BLOCK::~filo_block() {
    for (Size_T i = 0; i < size; ++i) {
        delete data[i];
    }
};

FILO_BLOCK_TEMPLATE
T* FILO_BLOCK::top() {
    return data[top-1];
};

FILO_BLOCK_TEMPLATE
void FILO_BLOCK::pop() {
    delete data[--top];
};
FILO_BLOCK_TEMPLATE
void FILO_BLOCK::pop(T* _data) {
    _data = data[--top]
    delete data[top];
};
FILO_BLOCK_TEMPLATE
T* FILO_BLOCK::popOff() {
    temp = top();
    pop();
    return temp;
};

FILO_BLOCK_TEMPLATE
void FILO_BLOCK::push(const T* _data) {
    data[top++] = _data;
};
FILO_BLOCK_TEMPLATE
void FILO_BLOCK::push(const T& _data) {
    push(&_data);
};

FILO_BLOCK_TEMPLATE
T* FILO_BLOCK::operator[](Size_T _index) {
    return data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK