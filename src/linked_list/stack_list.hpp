#pragma once

/**
 * @file stack_list.hpp
 * @brief A linked list that follows the First In, Last Out (FILO) principle.
*/

#include "linked_list.hpp"

#define STACK_LIST_TEMPLATE template<typename T, typename Size_T>
#define LINKED_LIST linked_list<T, Size_T>

namespace lstax
{
    STACK_LIST_TEMPLATE
    /**
     * @class stack_list
     * @brief A linked list that follows the First In, Last Out (FILO) principle.
     * 
     * @tparam T The type of data stored in the stack_list.
     * @tparam Size_T The type used to represent the size of the list.
     */
    struct stack_list : LINKED_LIST
    {
        /**
         * @fn lstax::stack_list::stack_list()
         * @brief Constructor for the stack_list class.
         * 
         * This constructor initializes the top pointer to nullptr and sets the length of the list to 0.
         * 
         * @see lstax::linked_list::linked_list()
         */
        stack_list() : LINKED_LIST() {};

        /**
         * @fn lstax::stack_list::~stack_list()
         * @brief Destructor for the stack_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the stack_list class.
         * It does not perform any specific actions in this implementation.
         * 
         * @see lstax::linked_list::~linked_list()
         */
        ~stack_list() {};

        /**
         * @fn lstax::stack_list::push(const T& _data)
         * @brief Adds an element to the end of the list.
         * 
         * This method adds an element to the end of the list.
         * It creates a new node with the specified _data and sets the next pointer of the current top node to the new node.
         * The new node becomes the top node of the list.
         * 
         * @param _data The _data to add to the list.
         * 
         * @see lstax::data_structure::push(const T& _data)
         */
        void push(const T& _data) override {
            ++this->length;
            this->top = new link<T>(_data, this->top);
        };

        /**
         * @fn lstax::stack_list::push()
         * @brief Adds an element to the end of the list.
         * 
         * This method adds an element to the end of the list.
         * It creates a new node with the specified _data and sets the next pointer of the current top node to the new node.
         * The new node becomes the top node of the list.
         * 
         * @see lstax::data_structure::push()
         */
        void push() override {
            ++this->length;
            this->top = new link<T>(this->top);
        };
    };
} // namespace lstax

#undef STACK_LIST_TEMPLATE
#undef LINKED_LIST