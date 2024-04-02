
#pragma once

#include <cstddef>

#define STACK_TEMPLATE template <typename Size_T, typename T>
#define STACK stack<Size_T, T>

#define LINK_TEMPLATE template <typename T>
#define LINK link<T>

namespace lstax
{
    STACK_TEMPLATE
    /**
     * @brief An abstract base class for a stack.
     * 
     * @tparam Size_T The type used for size/count values.
     * @tparam T The type of data stored in the stack.
     */
    class stack
    {
    public:
        /**
         * @brief Constructs an empty stack.
         */
        stack(); // Empty constructor

        /**
         * @brief Returns the length of the stack.
         * 
         * @return The length of the stack.
         */
        virtual Size_T length() const = 0;

        /**
         * @brief Adds a link with the given data to the top of the stack.
         * 
         * @param _data The data to be added to the stack.
         */
        virtual void push(const T *_data) = 0;

        /**
         * @brief Adds a link with the given data to the top of the stack.
         * 
         * @param _data The data to be added to the stack.
         */
        virtual void push(const T &_data) = 0;

        /**
         * @brief Views the top element of the stack.
         * 
         * @return A pointer to the top element of the stack.
         */
        virtual T *top() const = 0;

        /**
         * @brief Removes the top element from the stack.
         */
        virtual void pop() = 0;

        /**
         * @brief Removes the top element from the stack and sets the given pointer to the data.
         * 
         * @param _data A pointer to store the data of the removed element.
         */
        virtual void pop(T *_data) = 0;

        /**
         * @brief Removes the top element from the stack and returns the held data.
         * 
         * @return A pointer to the held data. Requires 1 additional pointer.
         */
        virtual T *popOff() = 0;

        /**
         * @brief Accesses the element at the specified index in the stack.
         * 
         * @param _index The index of the element to access.
         * @return A pointer to the element at the specified index.
         */
        virtual T *operator[](Size_T _index) const = 0;
    };
} // namespace lstax

namespace lstax
{
    STACK_TEMPLATE
    STACK::stack(){};
} // namespace lstax

#undef STACK_TEMPLATE
#undef STACK

#undef LINK_TEMPLATE
#undef LINK