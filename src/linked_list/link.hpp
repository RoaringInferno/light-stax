#pragma once

/**
 * @file link.hpp
 * @brief Linked list node implementation.
 */

#define LINK_TEMPLATE template<typename T>
#define LINK link<T>

namespace lstax
{
    LINK_TEMPLATE
    /**
     * @struct link
     * @brief A linked list node.
     * 
     * This struct represents a node in a linked list.
     * It contains a data field and a pointer to the next node in the list.
     * 
     * @tparam T The type of data stored in the node.
     */
    struct link
    {
        /**
         * @var T lstax::link::data
         * @brief The data stored in the node.
         */
        T data;
        /**
         * @var LINK* lstax::link::next
         * @brief A pointer to the next node in the list.
         */
        LINK* next;

        /**
         * @fn lstax::link::link()
         * @brief Default constructor for the link struct.
         * 
         * This constructor initializes the data field to the default value of the type T and the next pointer to 0.
         */
        link() : next(0) {};
        /**
         * @fn lstax::link::link(const T &_data, LINK* _next = 0)
         * @brief Constructor for the link struct.
         * 
         * This constructor initializes the data field to the value of the parameter _data and the next pointer to the value of the parameter _next.
         * 
         * @param _data The data to store in the node.
         * @param _next A pointer to the next node in the list.
         */
        link(const T &_data, LINK* _next = 0) : data(_data), next(_next) {};
        /**
         * @fn lstax::link::~link()
         * @brief Destructor for the link struct.
         * 
         * This destructor is responsible for cleaning up any resources used by the link struct.
         * It does not perform any specific actions in this implementation.
         * If the data field is a pointer, it is the responsibility of the user to free the memory allocated to it.
         * 
         * @see lstax::linked_list::~linked_list()
         */
        ~link() {};
    };
} // namespace lstax

#undef LINK_TEMPLATE
#undef LINK