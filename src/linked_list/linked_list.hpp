#pragma once

/**
 * @file linked_list.hpp
 * @brief Linked list implementation.
*/

#include "link.hpp"
#include "stack.hpp"

#define LINKED_LIST_TEMPLATE template<typename T, typename Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define STACK stack<T, Size_T>
#define LINK link<T>

namespace lstax
{
    LINKED_LIST_TEMPLATE
    /**
     * @class linked_list
     * @brief A linked list implementation.
     *
     * This class represents a linked list, where elements are added to the end of the list and removed from the front.
     * It is implemented using a linked list _data structure.
     * 
     * @tparam T The type of _data stored in the list.
     * @tparam Size_T The type used to represent the size of the list.
     */
    struct linked_list : STACK {
        /**
         * @var LINK* lstax::linked_list::top
         * @brief The top node of the list. This is the pop point.
         */
        LINK* top;

        /**
         * @fn lstax::linked_list::linked_list()
         * @brief Constructor for the linked_list class.
         * 
         * This constructor initializes the top pointer to nullptr and sets the length of the list to 0.
         * 
         * @see lstax::stack::stack()
         */
        linked_list() : top(nullptr), STACK() {};
        /**
         * @fn lstax::linked_list::~linked_list()
         * @brief Destructor for the linked_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the linked_list class.
         * It deletes all nodes in the list.
         * 
         * @see lstax::stack::~stack()
         */
        ~linked_list() {
            while (this->top != nullptr) {
                LINK* temp = this->top;
                this->top = temp->next;
                delete temp;
            }
        };

        /**
         * @fn lstax::linked_list::pop()
         * @brief Removes an element from the list.
         * 
         * This method removes an element from the list.
         * 
         * @see lstax::stack::pop()
        */
        void pop() override {
            this->_decrement_length();
            LINK* temp = this->top;
            this->top = temp->next;
            delete temp;
        };
        
        /**
         * @fn lstax::linked_list::peek() const
         * @brief Returns the top element of the list.
         * 
         * This method returns the top element of the list without removing it.
         * 
         * @return The top element of the list.
         * 
         * @see lstax::stack::peek()
         */
        T peek() const override {
            return this->top->data.value;
        };
    };
} // namespace lstax

#undef LINKED_LIST_TEMPLATE
#undef LINKED_LIST
#undef STACK
#undef LINK