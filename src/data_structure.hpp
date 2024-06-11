#pragma once

/**
 * @file data_structure.hpp
 * @brief data_structure data structure implementation.
 * 
 * This file contains the definition of the data_structure data structure interface.
*/

#define DATA_STRUCTURE_TEMPLATE template<typename T, typename Size_T>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{    
    DATA_STRUCTURE_TEMPLATE
    /**
     * @interface data_structure
     * @brief A data_structure data structure interface.
     * 
     * This class represents a data_structure data structure, where elements are added and removed in a Last-In-First-Out (LIFO) order.
     * It provides a common interface for data_structure implementations to follow.
     * 
     * @tparam T The type of data stored in the data_structure.
     * @tparam Size_T The type used to represent the size of the data_structure.
     */
    struct data_structure
    {
        /**
         * @fn lstax::data_structure::_decrementLength()
         * @brief Decrements the length of the data_structure.
         * @note This method is used internally for ease of maintenance.
        */
        void _decrementLength() {
            --this->length;
        }

        /**
         * @fn lstax::data_structure::_incrementLength()
         * @brief Increments the length of the data_structure.
         * @note This method is used internally for ease of maintenance.
        */
        void _incrementLength() {
            ++this->length;
        }

        /**
         * @var Size_T lstax::data_structure::length
         * @brief The length of the data_structure.
         */
        Size_T length;
        
        /**
         * @fn lstax::data_structure::data_structure()
         * @brief Constructor for the data_structure class.
         * 
         * This constructor initializes the length of the data_structure to 0.
        */
        data_structure() : length(0) {};
        
        /**
         * @fn lstax::data_structure::~data_structure()
         * @brief Destructor for the data_structure class.
         * 
         * This destructor is responsible for cleaning up any resources used by the data_structure class.
         * It does not perform any specific actions in this implementation.
        */
        ~data_structure() {};

        /**
         * @fn lstax::data_structure::push(const T& _data)
         * @brief Adds an element to the data_structure.
         * 
         * This method adds an element to the data_structure.
         * 
         * @param _data The data to add to the data_structure.
        */
        virtual void push(const T& _data) = 0;

        /**
         * @fn lstax::data_structure::push()
         * @brief Adds an element to the data_structure.
         * 
         * This method adds an element to the data_structure.
         * Calls the default constructor of T.
        */
        virtual void push() = 0;

        /**
         * @fn lstax::data_structure::pop()
         * @brief Removes an element from the data_structure.
         * 
         * This method removes an element from the data_structure.
        */
        virtual void pop() = 0;

        /**
         * @fn lstax::data_structure::peek()
         * @brief Returns the top element of the data_structure.
         * 
         * This method returns the top element of the data_structure without removing it.
         * 
         * @return A reference to the top element of the data_structure.
        */
        virtual T& peek() = 0;
    };
} // namespace lstax

#undef DATA_STRUCTURE_TEMPLATE
#undef DATA_STRUCTURE