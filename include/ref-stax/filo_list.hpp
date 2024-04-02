
#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FILO_LIST_TEMPLATE template <typename Size_T, typename T>
#define FILO_LIST filo_list<Size_T, T>

#define FILO_LIST_LINK_TEMPLATE template <typename T>
#define FILO_LIST_LINK filo_list_link<T>

namespace lstax
{

    FILO_LIST_LINK_TEMPLATE
    /**
     * @brief A link in the filo_list.
     *
     * @tparam T The type of data stored in the link.
     */
    class filo_list_link
    {
    public:
        T *data;              // Pointer to stored data.
        FILO_LIST_LINK *next; // Pointer to the next link.

        /**
         * @brief Constructs a filo_list_link with the given data and next link.
         *
         * @param _data Pointer to the data to be stored in the link.
         * @param _next Pointer to the next link in the list.
         */
        filo_list_link(T *_data, FILO_LIST_LINK *_next = nullptr);

        /**
         * @brief Destructor for filo_list_link.
         *
         * Deletes the filo_list_link and associated data.
         */
        ~filo_list_link();
    };

    /**
     * @brief A stack implemented as a filo_list.
     *
     * @tparam Size_T The type used to represent the size of the stack.
     * @tparam T The type of data stored in the stack.
     */
    FILO_LIST_TEMPLATE
    class filo_list : public stack<Size_T, T>
    {
    public:
        Size_T length; // Length of the stack.

        /**
         * @brief Returns the length of the stack.
         *
         * @return The length of the stack.
         */
        Size_T length() const override;

        FILO_LIST_LINK *top; // Pointer to the top link

        /**
         * @brief Constructs an empty filo_list.
         */
        filo_list();

        /**
         * @brief Constructs a filo_list with a single piece of data.
         *
         * @param _data Pointer to the data to be stored in the stack.
         */
        filo_list(T *_data);

        /**
         * @brief Destructor for filo_list.
         *
         * Deletes all links and all data.
         */
        ~filo_list();

        /**
         * @brief Adds a link with the given data to the top of the stack.
         *
         * @param _data Pointer to the data to be added.
         */
        void push(const T *_data) override;

        /**
         * @brief Adds a link with the given data to the top of the stack.
         *
         * @param _data Reference to the data to be added.
         */
        void push(const T &_data) override;

        /**
         * @brief Views the top element of the stack.
         *
         * @return Pointer to the top element of the stack.
         */
        T *top() const override;

        /**
         * @brief Removes the top element of the stack.
         */
        void pop() override;

        /**
         * @brief Removes the top element of the stack and sets the given pointer to the data.
         *
         * @param _data Pointer to store the data of the removed element.
         */
        void pop(T *_data) override;

        /**
         * @brief Removes the top element of the stack and returns the held data.
         *
         * @return Pointer to the data of the removed element.
         */
        T *popOff() override;

        /**
         * @brief Indexing operator to access elements in the stack.
         *
         * @param _index The index of the element to access.
         * @return Pointer to the data of the element at the given index.
         */
        T *operator[](size_t _index) const override;
    };

} // namespace lstax

namespace lstax
{ // filo_list_link

    FILO_LIST_LINK_TEMPLATE
    FILO_LIST_LINK::filo_list_link(T *_data, FILO_LIST_LINK *_next = nullptr) : data(_data)
    {
        next = _next;
    };

    FILO_LIST_LINK_TEMPLATE
    FILO_LIST_LINK::~filo_list_link()
    {
        delete data;
    };

} // namespace lstax

namespace lstax
{ // filo_list

    FILO_LIST_TEMPLATE
    FILO_LIST::filo_list() : stack<T>(), length(0), top(nullptr){};

    FILO_LIST_TEMPLATE
    FILO_LIST::filo_list(T *_data) : stack<T>(), length(1), top(new FILO_LIST_LINK(_data)){};

    FILO_LIST_TEMPLATE
    FILO_LIST::~filo_list()
    {
        FILO_LIST_LINK *bottom;
        for (size_t i = 0; i < length; ++i)
        {
            bottom = top->next;
            delete top;
            top = bottom;
        }
    };

    FILO_LIST_TEMPLATE
    void FILO_LIST::push(const T *_data)
    {
        top = new FILO_LIST_LINK(_data, top);
        ++length;
    };

    FILO_LIST_TEMPLATE
    void FILO_LIST::push(const T &_data)
    {
        push(*_data);
    };

    FILO_LIST_TEMPLATE
    T *FILO_LIST::top() const
    {
        return top->data;
    };

    FILO_LIST_TEMPLATE
    void FILO_LIST::pop()
    {
        FILO_LIST_LINK *interm = top->next;
        delete top;
        top = interm;
        --length;
    };

    FILO_LIST_TEMPLATE
    void FILO_LIST::pop(T *_data)
    {
        _data = top->data;
        top->data = nullptr;
        pop();
    };

    FILO_LIST_TEMPLATE
    T *FILO_LIST::popOff()
    {
        T *data = top->data;
        top->data = nullptr;
        pop();
        return data;
    };

    FILO_LIST_TEMPLATE
    T *FILO_LIST::operator[](size_t _index) const
    {
        FILO_LIST_LINK *target = top;
        for (size_t i = 0; i < _index; ++i)
        {
            target = target->next;
        }
        return target->data;
    };

    FILO_LIST_TEMPLATE
    Size_T FILO_LIST::length() const
    {
        return length;
    };

} // namespace lstax

#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK