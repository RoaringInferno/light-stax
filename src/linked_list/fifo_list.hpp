#pragma once

#include "linked_list.hpp"

#define FIFO_LIST_TEMPLATE template<typename T, typename Size_T>
#define FIFO_LIST fifo_list<T, Size_T>
#define LINKED_LIST linked_list<T, Size_T>
#define LINK link<T>

namespace lstax
{
    /**
     * @brief Template parameter for the FIFO list.
     * 
     * This template parameter is used to define the type of data stored in the FIFO list.
     * It allows the user to specify the data type when creating an instance of the FIFO list.
     * 
     * @tparam T The type of data stored in the FIFO list.
     */
    FIFO_LIST_TEMPLATE
    /**
     * @brief A First-In-First-Out (FIFO) linked list implementation.
     *
     * This class represents a FIFO list, where elements are added to the end of the list and removed from the front.
     * It is implemented using a linked list data structure.
     */
    struct fifo_list : LINKED_LIST
    {
        /**
         * @brief Represents a node in a linked list.
         */
        LINK* bottom;

        
        fifo_list() : LINKED_LIST() {};
        /**
         * @brief Destructor for the fifo_list class.
         * 
         * This destructor is responsible for cleaning up any resources used by the fifo_list class.
         * It does not perform any specific actions in this implementation.
         */
        ~fifo_list() {};
        
        void push(const T& _data) override {
            if (this->length != 0) {
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

#undef FIFO_LIST_TEMPLATE
#undef FIFO_LIST
#undef LINKED_LIST
#undef LINK