/**
 * @file fifo_block.hpp
 * @brief Contains the definition of the fifo_block class.
 */

#pragma once

#include <cstddef>

#include "../stack.hpp"

#define FIFO_BLOCK_TEMPLATE template <typename Size_T, typename T, Size_T size>
#define FIFO_STACK fifo_block<Size_T, T, size>

/**
 * @namespace lstax
 * @brief Namespace for the lstax library.
 */
namespace lstax
{
    FIFO_BLOCK_TEMPLATE
    /**
     * @brief Template parameter for the fifo_block class.
     *
     * The FIFO_BLOCK_TEMPLATE is used to specify the template parameter for the fifo_block class.
     * It allows the user to define the type of elements stored in the fifo_block.
     *
     * @tparam Size_T The type used for size and index calculations.
     * @tparam T The type of elements stored in the fifo_block.
     */
    class fifo_block : stack<Size_T, T>
    {
    public:
        T *data[size]; /**< The array to store the elements of the fifo_block. */
        Size_T bottom; /**< The index of the first empty element in the fifo_block. */

        /**
         * @brief Default constructor for the fifo_block class.
         */
        fifo_block();

        /**
         * @brief Constructor for the fifo_block class.
         *
         * @param _data The initial data to be stored in the fifo_block.
         */
        fifo_block(T *_data);

        /**
         * @brief Destructor for the fifo_block class.
         *
         * Deletes all data stored in the fifo_block and ensures memory cleanup.
         */
        ~fifo_block();

        /**
         * @brief Get the top element of the fifo_block.
         *
         * @return T* A pointer to the top element of the fifo_block.
         */
        T *top();

        /**
         * @brief Remove the top element from the fifo_block.
         *
         * Deletes the top element from the fifo_block.
         */
        void pop();

        /**
         * @brief Remove the top element from the fifo_block and retrieve its data.
         *
         * Marks the top element as empty and sets the given pointer to the data.
         *
         * @param _data A pointer to store the data of the top element.
         */
        void pop(T *_data);

        /**
         * @brief Remove the top element from the fifo_block and return its data.
         *
         * @return T* A pointer to the data of the top element.
         */
        T *popOff();

        /**
         * @brief Push an element into the fifo_block.
         *
         * @param _data The element to be pushed into the fifo_block.
         */
        void push(const T *_data);

        /**
         * @brief Push an element into the fifo_block.
         *
         * @param _data The element to be pushed into the fifo_block.
         */
        void push(const T &_data);

        /**
         * @brief Access an element in the fifo_block by index.
         *
         * @param _index The index of the element to be accessed.
         * @return T* A pointer to the element at the specified index.
         */
        T *operator[](Size_T _index);
    };
}

namespace lstax
{
    FIFO_BLOCK_TEMPLATE
    FIFO_STACK::fifo_block() : stack<Size_T, T>, top(0){
                                                     //
                                                 };
    FIFO_BLOCK_TEMPLATE
    FIFO_STACK::fifo_block(T *_data) : stack<Size_T, T>, top(1)
    {
        data[0] = _data;
    };
    FIFO_BLOCK_TEMPLATE
    FIFO_STACK::~fifo_block()
    {
        for (Size_T i = 0; i < size; ++i)
        {
            delete data[i];
        }
    };

    FIFO_BLOCK_TEMPLATE
    T *FIFO_STACK::top()
    {
        return data[0];
    };

    FIFO_BLOCK_TEMPLATE
    void FIFO_STACK::pop()
    {
        delete data[0];
        for (Size_T i = 0; i < size;)
        {
            data[i] = data[++i];
        }
        --top;
    };
    FIFO_BLOCK_TEMPLATE
    void FIFO_STACK::pop(T *_data)
    {
        _data = top();
        for (Size_T i = 0; i < size;)
        {
            data[i] = data[++i];
        }
        --top;
    };
    FIFO_BLOCK_TEMPLATE
    T *FIFO_STACK::popOff()
    {
        T *temp = top();
        pop();
        return temp;
    };

    FIFO_BLOCK_TEMPLATE
    void FIFO_STACK::push(const T *_data)
    {
        data[bottom++] = _data;
    };
    FIFO_BLOCK_TEMPLATE
    void FIFO_STACK::push(const T &_data)
    {
        push(&_data);
    };

    FIFO_BLOCK_TEMPLATE
    T *FIFO_STACK::operator[](Size_T _index)
    {
        return data[_index];
    };
}

#undef FIFO_STACK_TEMPLATE
#undef FIFO_STACK