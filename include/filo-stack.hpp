#pragma once

#include <cstddef>
#include <stdexcept>

#include "stack.hpp"

#define FILOSTACK_TEMPLATE_DECL template<typename Size_T = size_t, typename T, Size_T size>
#define FILOSTACK_TEMPLATE template<typename Size_T, typename T, Size_T size>
#define FILOSTACK FiloStack<Size_T, T, size>

namespace lstax
{
FILOSTACK_TEMPLATE_DECL
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

    bool push(const T* _data); // Returns true if the push was successful. If the stack is full, returns false.
    bool push(const T& _data); // Returns true if the push was successful. If the stack is full, returns false.

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
bool FILOSTACK::push(const T* _data) {
    if (top == size) return false;
    data[top++] = _data;
    return true;
};
FILOSTACK_TEMPLATE
bool FILOSTACK::push(const T& _data) {
    return push(&_data);
};

FILOSTACK_TEMPLATE
T* FILOSTACK::operator[](Size_T _index) {
    if (_index >= top) throw std::out_of_range("Index out of range");
    return data[_index];
};
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK