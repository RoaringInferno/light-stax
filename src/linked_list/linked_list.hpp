#pragma once

/**
 * @file linked_list.hpp
 * @brief linked list interface implementation.
*/

#include "link.hpp"
#include "data_structure.hpp"

#define LINKED_LIST_TEMPLATE template<typename T, typename Size_T>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    LINKED_LIST_TEMPLATE
    /**
     * @interface linked_list
     * @brief A linked list implementation.
     *
     * This class represents a linked list, where elements are added to the end of the list and removed from the front.
     * It is implemented using a linked list _data structure.
     * 
     * @tparam T The type of _data stored in the list.
     * @tparam Size_T The type used to represent the size of the list.
     */
    struct linked_list : DATA_STRUCTURE {
        /**
         * @var link* lstax::linked_list::top
         * @brief The top node of the list. This is the pop point.
         */
        link<T>* top;

        /**
         * @fn lstax::linked_list::linked_list()
         * @brief Constructor for the linked_list class.
         * 
         * This constructor initializes the top pointer to nullptr and sets the length of the list to 0.
         * 
         * @see lstax::data_structure::data_structure()
         */
        linked_list() : top(nullptr), DATA_STRUCTURE() {};

        /**
         * @fn lstax::linked_list::~linked_list()
         * @brief Destructor for the linked_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the linked_list class.
         * It deletes all nodes in the list.
         * 
         * @see lstax::data_structure::~data_structure()
         */
        ~linked_list() {
            while (this->top != nullptr) {
                link<T>* temp = this->top;
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
         * @see lstax::data_structure::pop()
        */
        void pop() override {
            this->_decrementLength();
            link<T>* temp = this->top;
            this->top = temp->next;
            delete temp;
        };
        
        /**
         * @fn lstax::linked_list::peek()
         * @brief Returns the top element of the list.
         * 
         * This method returns the top element of the list without removing it.
         * 
         * @return A reference to the top element of the list.
         * 
         * @see lstax::data_structure::peek()
         */
        T& peek() override {
            return this->top->data.get_value();
        };
    };
} // namespace lstax

#undef LINKED_LIST_TEMPLATE
#undef DATA_STRUCTURE
