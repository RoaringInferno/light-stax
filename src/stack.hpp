#pragma once

/**
 * @file stack.hpp
 * @brief Stack data structure implementation.
 * 
 * This file contains the definition of the stack data structure interface.
*/

#include "stackexcept.hpp"

#define STACK_TEMPLATE template<typename T, typename Size_T>
#define STACK stack<T, Size_T>

namespace lstax
{    
    STACK_TEMPLATE
    /**
     * @interface stack
     * @brief A stack data structure interface.
     * 
     * This class represents a stack data structure, where elements are added and removed in a Last-In-First-Out (LIFO) order.
     * It provides a common interface for stack implementations to follow.
     * 
     * @tparam T The type of data stored in the stack.
     * @tparam Size_T The type used to represent the size of the stack.
     */
    struct stack
    {
        /**
         * @fn lstax::stack::_decrement()
         * @brief Decrements the length of the stack.
         * 
         * This method decrements the length of the stack.
         * If the length becomes negative, it throws a stack_underflow exception.
        */
        void _decrement_length() {
            if (this->length-- == 0)
            {
                throw stack_underflow();
            }
        }

        /**
         * @var Size_T lstax::stack::length
         * @brief The length of the stack.
         */
        Size_T length;
        
        /**
         * @fn lstax::stack::stack()
         * @brief Constructor for the stack class.
         * 
         * This constructor initializes the length of the stack to 0.
        */
        stack() : length(0) {};
        /**
         * @fn lstax::stack::~stack()
         * @brief Destructor for the stack class.
         * 
         * This destructor is responsible for cleaning up any resources used by the stack class.
         * It does not perform any specific actions in this implementation.
        */
        ~stack() {};

        /**
         * @fn lstax::stack::push(const T& _data)
         * @brief Adds an element to the stack.
         * 
         * This method adds an element to the stack.
         * 
         * @param _data The data to add to the stack.
        */
        virtual void push(const T& _data) = 0;
        /**
         * @fn lstax::stack::pop()
         * @brief Removes an element from the stack.
         * 
         * This method removes an element from the stack.
        */
        virtual void pop() = 0;
        /**
         * @fn lstax::stack::peek() const
         * @brief Returns the top element of the stack.
         * 
         * This method returns the top element of the stack without removing it.
         * 
         * @return The top element of the stack.
        */
        virtual T peek() const = 0;
    };
} // namespace lstax

#undef STACK_TEMPLATE
#undef STACK