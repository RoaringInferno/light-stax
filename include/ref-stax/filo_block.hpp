/**
 * @file filo_block.hpp
 * @brief Contains the definition of the filo_block class.
 */

#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FILO_BLOCK_TEMPLATE template <typename Size_T, typename T, Size_T size>
#define FILO_BLOCK filo_block<Size_T, T, size>

namespace lstax
{
    FILO_BLOCK_TEMPLATE
    /**
     * @brief Template parameter for the filo_block class.
     *
     * The FILO_BLOCK_TEMPLATE is used as a template parameter for the filo_block class.
     * It allows the filo_block class to be instantiated with different types of data.
     *
     * @tparam Size_T The type used for size-related operations.
     * @tparam T The type of data stored in the filo_block.
     */
    class filo_block : stack<Size_T, T>
    {
    public:
        T *data[size]; /**< Array to store the data elements. */
        Size_T top;    /**< The first empty index. */

        /**
         * @brief Default constructor for the filo_block class.
         */
        filo_block();

        /**
         * @brief Constructor for the filo_block class.
         *
         * @param _data Pointer to the data element to be stored in the filo_block.
         */
        filo_block(T *_data);

        /**
         * @brief Destructor for the filo_block class.
         *
         * Deletes all data elements stored in the filo_block.
         */
        ~filo_block();

        /**
         * @brief Get the top data element.
         *
         * @return Pointer to the top data element.
         */
        T *top();

        /**
         * @brief Remove the top data element.
         */
        void pop();

        /**
         * @brief Remove the top data element and assign it to the given pointer.
         *
         * @param _data Pointer to store the top data element.
         */
        void pop(T *_data);

        /**
         * @brief Remove the top data element and return it.
         *
         * @return Pointer to the removed top data element.
         */
        T *popOff();

        /**
         * @brief Push a new data element onto the filo_block.
         *
         * @param _data Pointer to the data element to be pushed.
         */
        void push(const T *_data);

        /**
         * @brief Push a new data element onto the filo_block.
         *
         * @param _data Reference to the data element to be pushed.
         */
        void push(const T &_data);

        /**
         * @brief Access the data element at the given index.
         *
         * @param _index The index of the data element to access.
         * @return Pointer to the data element at the given index.
         */
        T *operator[](Size_T _index);
    };
}

namespace lstax
{
    FILO_BLOCK_TEMPLATE
    FILO_BLOCK::filo_block() : stack<Size_T, T>(), top(0){
                                                       //
                                                   };

    FILO_BLOCK_TEMPLATE
    FILO_BLOCK::filo_block(T *_data) : stack<Size_T, T>(), top(1)
    {
        data[0] = _data;
    };

    FILO_BLOCK_TEMPLATE
    FILO_BLOCK::~filo_block()
    {
        for (Size_T i = 0; i < size; ++i)
        {
            delete data[i];
        }
    };

    FILO_BLOCK_TEMPLATE
    T *FILO_BLOCK::top()
    {
        return data[top - 1];
    };

    FILO_BLOCK_TEMPLATE
    void FILO_BLOCK::pop()
    {
        delete data[--top];
    };

    FILO_BLOCK_TEMPLATE
    void FILO_BLOCK::pop(T *_data)
    {
        _data = data[--top];
    };

    FILO_BLOCK_TEMPLATE
    T *FILO_BLOCK::popOff()
    {
        T *temp = top();
        pop();
        return temp;
    };

    FILO_BLOCK_TEMPLATE
    void FILO_BLOCK::push(const T *_data)
    {
        data[top++] = _data;
    };

    FILO_BLOCK_TEMPLATE
    void FILO_BLOCK::push(const T &_data)
    {
        push(&_data);
    };

    FILO_BLOCK_TEMPLATE
    T *FILO_BLOCK::operator[](Size_T _index)
    {
        return data[_index];
    };
}

#undef FILO_STACK_TEMPLATE
#undef FILO_STACK