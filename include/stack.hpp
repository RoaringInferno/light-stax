#pragma once

#include <cstddef>

#define STACK_TEMPLATE_DECL template<typename Size_T = size_t, typename T>
#define STACK_TEMPLATE template<typename Size_T, typename T>
#define STACK Stack<Size_T, T>

namespace lstax
{
STACK_TEMPLATE_DECL
class Stack {
public:
Stack(); // Empty constructor

virtual Size_T length() = 0; // Returns the length

virtual void push(const T* _data) = 0; // Adds a link with the given data.
virtual void push(const T& _data) = 0; // Adds a link with the given data.

virtual T* top() = 0; // Views the top element.
virtual void pop() = 0;  // Removes the top element.
virtual void pop(T* _data) = 0;  // Removes the top element.
virtual T* popOff() = 0; // Returns the held data. Requires 1 additional pointer.

virtual T* operator[](Size_T _index) = 0; // Indexing operator
};
} // namespace lstax

namespace lstax
{
STACK_TEMPLATE
STACK::Stack() {};
} // namespace lstax