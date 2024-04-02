#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FIFO_LIST_TEMPLATE template <typename Size_T, typename T>
#define FIFO_LIST fifo_list<Size_T, T>

#define FIFO_LIST_LINK_TEMPLATE template <typename T>
#define FIFO_LIST_LINK fifo_list_link<T>

namespace lstax
{

    FIFO_LIST_LINK_TEMPLATE
    /**
     * @brief Class representing a link in a FIFO list.
     *
     * The fifo_list_link class represents a link in a FIFO (First-In-First-Out) list.
     * It stores a pointer to the data and a pointer to the next link in the list.
     *
     * @tparam T The type of data that the link will store.
     */
    class fifo_list_link
    {
    public:
        T *data;              // Pointer to stored data.
        FIFO_LIST_LINK *next; // Pointer to the next link.

        /**
         * @brief Constructs a fifo_list_link with the given data and previous link.
         *
         * @param _data Pointer to the data to be stored in the link.
         * @param _previous Pointer to the previous link in the list. Default is nullptr.
         */
        fifo_list_link(T *_data, FIFO_LIST_LINK *_previous = nullptr);

        /**
         * @brief Destructor for fifo_list_link.
         *
         * Deletes the fifo_list_link and the associated data.
         */
        ~fifo_list_link();
    };

    FIFO_LIST_TEMPLATE
    /**
     * @brief Template class representing a FIFO list.
     *
     * The fifo_list class is a template class that represents a FIFO (First-In-First-Out) list.
     * It inherits from the stack class and provides additional functionality for FIFO operations.
     *
     * @tparam Size_T The type used to represent the size of the stack.
     * @tparam T The type of data that the fifo_list will store.
     */
    class fifo_list : public stack<Size_T, T>
    {
    public:
        Size_T length; // Length of the stack.

        /**
         * @brief Returns the length of the fifo_list.
         *
         * @return The length of the fifo_list.
         */
        Size_T length();

        FIFO_LIST_LINK *top;    // Pointer to the top link (pop target)
        FIFO_LIST_LINK *bottom; // Pointer to the bottom link (push target)

        /**
         * @brief Constructs an empty fifo_list.
         */
        fifo_list();

        /**
         * @brief Constructs a fifo_list with a single piece of data.
         *
         * @param _data Pointer to the data to be stored in the fifo_list.
         */
        fifo_list(T *_data);

        /**
         * @brief Destructor for fifo_list.
         *
         * Deletes all links and associated data in the fifo_list.
         */
        ~fifo_list();

        /**
         * @brief Adds a link with the given data to the fifo_list.
         *
         * @param _data Pointer to the data to be added to the fifo_list.
         */
        void push(const T *_data);

        /**
         * @brief Adds a link with the given data to the fifo_list.
         *
         * @param _data Reference to the data to be added to the fifo_list.
         */
        void push(const T &_data);

        /**
         * @brief Views the top element of the fifo_list.
         *
         * @return Pointer to the top element of the fifo_list.
         */
        T *top();

        /**
         * @brief Removes the top element from the fifo_list.
         */
        void pop();

        /**
         * @brief Removes the top element from the fifo_list and sets the given pointer to the data.
         *
         * @param _data Pointer to store the data of the removed element.
         */
        void pop(T *_data);

        /**
         * @brief Removes the top element from the fifo_list and returns the held data.
         *
         * @return Pointer to the held data. Requires 1 additional pointer.
         */
        T *popOff();

        /**
         * @brief Indexing operator for the fifo_list.
         *
         * @param _index The index of the element to access.
         * @return Pointer to the element at the specified index.
         */
        T *operator[](size_t _index);
    };

} // namespace lstax
namespace lstax
{

    FIFO_LIST_LINK_TEMPLATE
    class fifo_list_link
    {
    public:
        T *data;              // Pointer to stored data.
        FIFO_LIST_LINK *next; // Pointer to the next link.

        fifo_list_link(T *_data, FIFO_LIST_LINK *_previous = nullptr); // Creates a fifo_list_link behind the given link, with the given data.

        ~fifo_list_link(); // Deletes the fifo_list_link, and associated data.
    };
} // namespace lstax

namespace lstax
{ // fifo_list_link

    FIFO_LIST_LINK_TEMPLATE
    FIFO_LIST_LINK::fifo_list_link(T *_data, FIFO_LIST_LINK *_previous = nullptr) : data(_data)
    {
        if (_previous != nullptr)
            _previous->next = this;
    };

    FIFO_LIST_LINK_TEMPLATE
    FIFO_LIST_LINK::~fifo_list_link()
    {
        delete data;
    };

} // namespace lstax

/**
 * @brief Namespace for the FIFO list implementation.
 */
namespace lstax
{ // fifo_list

    FIFO_LIST_TEMPLATE
    FIFO_LIST::fifo_list() : stack<T>(), length(0), top(nullptr), bottom(nullptr){};

    FIFO_LIST_TEMPLATE
    FIFO_LIST::fifo_list(T *_data) : stack<T>(), length(1), top(new FIFO_LIST_LINK(_data)), bottom(top){};

    FIFO_LIST_TEMPLATE
    FIFO_LIST::~fifo_list()
    {
        for (size_t i = 0; i < length; ++i)
        {
            bottom = top->next;
            delete top;
            top = bottom;
        }
    };

    FIFO_LIST_TEMPLATE
    void FIFO_LIST::push(const T *_data)
    {
        bottom = new FIFO_LIST_LINK(_data, bottom);
        ++length;
    };

    FIFO_LIST_TEMPLATE
    void FIFO_LIST::push(const T &_data)
    {
        push(*_data);
    };

    FIFO_LIST_TEMPLATE
    T *FIFO_LIST::top()
    {
        return top->data;
    };

    FIFO_LIST_TEMPLATE
    void FIFO_LIST::pop()
    {
        FIFO_LIST_LINK *interm = top->next;
        delete top;
        top = interm;
        --length;
    };
    FIFO_LIST_TEMPLATE
    void FIFO_LIST::pop(T *_data)
    {
        _data = top->data;
        top->data = nullptr;
        pop();
    };

    FIFO_LIST_TEMPLATE
    T *FIFO_LIST::popOff()
    {
        T *data = top->data;
        top->data = nullptr;
        pop();
        return data;
    };

    FIFO_LIST_TEMPLATE
    T *FIFO_LIST::operator[](size_t _index)
    {
        FIFO_LIST_LINK *target = top;
        for (size_t i = 0; i < _index; ++i)
        {
            target = target->next;
        }
        return target->data;
    };

    FIFO_LIST_TEMPLATE
    Size_T FIFO_LIST::length()
    {
        return length;
    };

} // namespace lstax

#undef FIFO_LIST_TEMPLATE
#undef FIFO

#undef FIFO_LIST_LINK_TEMPLATE
#undef FIFO_LIST_LINK
