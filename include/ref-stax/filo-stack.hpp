#pragma once

#include <cstddef>

#include "stack.hpp"

#define FILOSTACK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define FILOSTACK FiloStack<Size_T, T, size>

namespace lstax
{
FILOSTACK_TEMPLATE
class FiloStack : Stack<Size_T, T>
{
public:
    T* data[size];
    Size_T top; // The first empty index

    FiloStack();
    FiloStack(T* _data);
    ~FiloStack(); // Deletes all data. Iterates through the whole array in order to ensure memory cleanup.

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
FILOSTACK_TEMPLATE
FILOSTACK::FiloStack() : Stack<Size_T, T>(), top(0) {
    //
};
FILOSTACK_TEMPLATE
FILOSTACK::FiloStack(T* _data) : Stack<Size_T, T>(), top(1) {
    data[0] = _data;
};
FILOSTACK_TEMPLATE
FILOSTACK::~FiloStack() {
    for (Size_T i = 0; i < size; ++i) {
        delete data[i];
    }
};

FILOSTACK_TEMPLATE
T* FILOSTACK::top() {
    return data[top-1];
};

FILOSTACK_TEMPLATE
void FILOSTACK::pop() {
    delete data[--top];
};
FILOSTACK_TEMPLATE
void FILOSTACK::pop(T* _data) {
    _data = data[--top]
    delete data[top];
};
FILOSTACK_TEMPLATE
T* FILOSTACK::popOff() {
    temp = top();
    pop();
    return temp;
};

FILOSTACK_TEMPLATE
void FILOSTACK::push(const T* _data) {
    data[top++] = _data;
};
FILOSTACK_TEMPLATE
void FILOSTACK::push(const T& _data) {
    push(&_data);
};

FILOSTACK_TEMPLATE
T* FILOSTACK::operator[](Size_T _index) {
    return data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK