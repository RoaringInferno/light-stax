#pragma once

/**
 * @file filo_list.hpp
 * @brief First-In-Last-Out (FILO) linked list implementation.
*/

#include "linked_list.hpp"
#include "stackexcept.hpp"

#define FILO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FILO_LIST filo_list<T, Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define LINK link<T>

namespace lstax
{
    FILO_LIST_TEMPLATE
    /**
     * @class filo_list
     * @brief A First-In-Last-Out (FILO) linked list implementation.
     *
     * This class represents a FILO linked list, where elements are added to the end of the list and removed from the front.
     * It is implemented using a linked list data structure.
     * 
     * @tparam T The type of data stored in the FILO list.
     * @tparam Size_T The type used to represent the size of the list.
     */
    struct filo_list : LINKED_LIST
    {
        /**
         * @fn lstax::filo_list::filo_list()
         * @brief Constructor for the filo_list class.
         * 
         * This constructor initializes the top pointer to nullptr and sets the length of the list to 0.
         * 
         * @see lstax::linked_list::linked_list()
         */
        filo_list() : LINKED_LIST() {};
        /**
         * @fn lstax::filo_list::~filo_list()
         * @brief Destructor for the filo_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the filo_list class.
         * It does not perform any specific actions in this implementation.
         * 
         * @see lstax::linked_list::~linked_list()
         */
        ~filo_list() {};

        /**
         * @fn lstax::filo_list::push(const T& _data)
         * @brief Adds an element to the end of the list.
         * 
         * This method adds an element to the end of the list.
         * It creates a new node with the specified data and sets the next pointer of the current top node to the new node.
         * The new node becomes the top node of the list.
         * 
         * @param _data The data to add to the list.
         * 
         * @see lstax::stack::push()
         */
        void push(const T& _data) override {
            if (++this->length < 1) {
                throw stack_overflow();
            }
            this->top = new LINK(_data, this->top);
        };
    };
} // namespace lstax

#undef FILO_LIST_TEMPLATE
#undef FILO_LIST
#undef LINKED_LIST
#undef LINK