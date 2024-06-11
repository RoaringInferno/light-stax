#pragma once

/**
 * @file link.hpp
 * @brief Linked list node implementation.
 */

#define LINK_TEMPLATE template<typename T>
#define LINK link<T>

#include "_data.hpp"

namespace lstax
{
    LINK_TEMPLATE
    /**
     * @struct link
     * @brief A linked list node.
     * 
     * @tparam T The type of data stored in the node.
     */
    struct link
    {
        /**
         * @var lstax::link::_data
         * @brief The data stored in the node.
         */
        _data<T> data;

        /**
         * @var lstax::link::next
         * @brief A pointer to the next node in the list.
         */
        LINK* next;

        /**
         * @fn lstax::link::link(LINK* _next = nullptr)
         * @brief Constructor for the link struct.
         * 
         * @param _next A pointer to the next node in the list.
        */
        link(LINK* _next = nullptr) : next(_next) {};

        /**
         * @fn lstax::link::link(const T &_data, LINK* _next = nullptr)
         * @brief Constructor for the link struct.
         * 
         * @param _data The data to store in the node.
         * @param _next A pointer to the next node in the list.
         */
        link(const T &_data, LINK* _next = nullptr) : data(_data), next(_next) {};

        /**
         * @fn lstax::link::value()
         * @brief Returns the data stored in the node.
         *
         * This method returns the data stored in the node.
         *
         * @return A reference to the data stored in the node.
         */
        T& value() const {
            return data.get_value();
        }
    };
} // namespace lstax

#undef LINK_TEMPLATE
#undef LINK