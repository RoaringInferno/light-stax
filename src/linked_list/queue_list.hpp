#pragma once

/**
 * @file queue_list.hpp
 * @brief A linked list that follows the First In, First Out (FIFO) principle.
*/

#include "linked_list.hpp"

#define QUEUE_LIST_TEMPLATE template<typename T, typename Size_T>
#define QUEUE_LIST queue_list<T, Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define LINK link<T>

namespace lstax
{
    QUEUE_LIST_TEMPLATE
    /**
     * @class queue_list
     * @brief A linked list that follows the First In, First Out (FIFO) principle.
     * 
     * @tparam T The type of data stored in the QUEUE list.
     * @tparam Size_T The type used to represent the size of the list.
     */
    struct queue_list : LINKED_LIST
    {
        /**
         * @var linked_list<T, Size_T>* lstax::queue_list::bottom
         * @brief The bottom node of the list. This is the push point.
         */
        LINK* bottom;

        
        /**
         * @fn lstax::queue_list::queue_list()
         * @brief Constructor for the queue_list class.
         * 
         * This constructor initializes the top and bottom pointers to nullptr and sets the length of the list to 0.
         * 
         * @see lstax::linked_list::linked_list()
         */
        queue_list() : LINKED_LIST() {};
        /**
         * @fn lstax::queue_list::~queue_list()
         * @brief Destructor for the queue_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the queue_list class.
         * It does not perform any specific actions in this implementation.
         * 
         * @see lstax::linked_list::~linked_list()
         */
        ~queue_list() {};
        
        /**
         * @fn lstax::queue_list::push(const T& _data)
         * @brief Adds an element to the end of the list.
         * 
         * @param _data The _data to add to the list.
         * 
         * @see lstax::stack::push()
         */
        void push(const T& _data) override {
            if (this->top != nullptr) {
                LINK* temp = new LINK(_data);
                this->bottom->next = temp;
                this->bottom = temp;
            } else {
                this->bottom = new LINK(_data);
                this->top = this->bottom;
            }
            ++this->length;
        };
    };
} // namespace lstax

#undef QUEUE_LIST_TEMPLATE
#undef QUEUE_LIST
#undef LINKED_LIST
#undef LINK