#pragma once

#include <cstddef>

#define STACK_TEMPLATE template<typename T>
#define STACK Stack<T>

namespace lstax
{
STACK_TEMPLATE
class Stack {
public:
Stack(); // Empty constructor
~Stack();

virtual size_t length() = 0; // Returns the length

virtual void push(const T* _data) = 0; // Adds a link with the given data.
virtual void push(const T& _data) = 0; // Adds a link with the given data.

virtual T* top() = 0; // Views the top element.
virtual void pop() = 0;  // Removes the top element.
virtual T* pop_off() = 0; // Returns the held data. Requires 1 additional pointer.

virtual T* operator[](size_t _index) = 0; // Indexing operator
};
} // namespace lstax

namespace lstax
{
STACK_TEMPLATE
STACK::Stack() {};

STACK_TEMPLATE
STACK::~Stack() {};
} // namespace lstax