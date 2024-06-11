#pragma once

/**
 * @file _data.hpp
 * @brief This file contains the definition of the _data_structure and _data classes.
 * 
 * These classes are wrappers for _data to allow for custom cleanup when the _data is no longer needed.
 * The _data_structure class is a base class that stores a value of type T.
 * The _data class is a wrapper for _data to allow for custom cleanup of the _data value.
 * The _data<T*> class is a wrapper for _data pointers to allow for custom cleanup of the _data value.
 */

#define DATA_TEMPLATE template<typename T>

namespace lstax
{
    DATA_TEMPLATE
    /**
     * @interface _data_structure
     * @brief A simple _data structure.
     *
     * This struct is a simple _data structure that stores a value of type T.
     * Used as a base class for the _data struct, to share common members.
     *
     * @tparam T The type of _data to store.
     */
    struct _data_structure {
        /**
         * @var lstax::_data_structure::value
         * @brief The data value.
         */
        T value;

        /**
         * @fn lstax::_data_structure::_data_structure()
         * @brief Default constructor for the _data_structure struct.
         *
         * This constructor initializes the value field to the default value of the type T.
         */
        _data_structure() {};

        /**
         * @fn lstax::_data_structure::_data_structure(const _data_structure& other)
         * @brief Copy constructor for the _data_structure struct.
         *
         * This constructor initializes the value field to the value of the parameter other.
         *
         * @param other The _data_structure to copy.
         */
        _data_structure(const _data_structure& other) : value(other.value) {};

        /**
         * @fn lstax::_data_structure::_data_structure(T _value)
         * @brief Constructor for the _data_structure struct.
         *
         * This constructor initializes the value field to the value of the parameter _value.
         *
         * @param _value The data value to store.
         */
        _data_structure(const T& _value) : value(_value) {};
        
        /**
         * @fn lstax::_data_structure::~_data_structure()
         * @brief Destructor for the _data_structure struct.
         *
         * This destructor is responsible for cleaning up the data value.
         * It does not perform any specific actions in this implementation.
         */
        ~_data_structure() {};

        /**
         * @fn lstax::_data_structure::get_value()
         * @brief Returns a reference to the data value.
         * 
         * @return The data value.
        */
        T& get_value() {
            return value;
        }
    };

    DATA_TEMPLATE
    /**
     * @struct _data
     * @brief A wrapper for _data to allow for custom cleanup.
     *
     * This struct is a wrapper for _data to allow for custom cleanup when the _data is no longer needed.
     * It is used in linked list nodes to allow for the cleanup of the _data when the node is deleted.
     *
     * @tparam T The type of _data to store.
     */
    struct _data : _data_structure<T>
    {
        /**
         * @fn lstax::_data::_data()
         * @brief Default constructor for the _data struct.
         *
         * This constructor initializes the value field to the default value of the type T.
         */
        _data() : _data_structure<T>() {};

        /**
         * @fn lstax::_data::_data(T* _value)
         * @brief Constructor for the _data struct.
         *
         * This constructor initializes the value field to the value of the parameter _value.
         *
         * @param _value The _data value to store.
         */
        _data(const T& _value) : _data_structure<T>(_value) {};

        /**
         * @fn lstax::_data::~_data()
         * @brief Destructor for the _data struct.
         *
         * This destructor is responsible for cleaning up the _data value.
         * It does not perform any specific actions in this implementation.
         */
        ~_data() {};
    };

    DATA_TEMPLATE
    /**
     * @struct _data<T*>
     * @brief A wrapper for _data pointers to allow for custom cleanup.
     *
     * This struct is a wrapper for _data pointers to allow for custom cleanup when the _data is no longer needed.
     * It is used in linked list nodes to allow for the cleanup of the _data when the node is deleted.
     *
     * @tparam T The type of _data to store.
     */
    struct _data<T*> : _data_structure<T*>
    {
        /**
         * @fn lstax::_data::_data()
         * @brief Default constructor for the _data struct.
         *
         * This constructor initializes the _data value to nullptr.
         */
        _data() : _data_structure<T*>() {};

        /**
         * @fn lstax::_data::_data(T* _value)
         * @brief Constructor for the _data struct.
         *
         * This constructor initializes the _data value to the value of the parameter _value.
         *
         * @param _value The _data value to store.
         */
        _data(T *_value) : _data_structure<T*>(_value) {};
        
        /**
         * @fn lstax::_data::~_data()
         * @brief Destructor for the _data struct.
         *
         * This destructor is responsible for cleaning up the _data value.
         * It deletes the _data value if it is not nullptr.
         */
        ~_data() {
            delete this->value;
        };
    };
}

#undef DATA_TEMPLATE
#undef DATA_STRUCTURE