#pragma once

/**
 * @file batch_link.hpp
 * @brief Batch link implementation.
 */

#define BATCH_LINK_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCH_LINK batch_link<T, Size_T, Batch_Size>

namespace lstax
{
    BATCH_LINK_TEMPLATE
    /**
     * @struct batch_link
     * @brief A batch link node.
     * 
     * This struct represents a node in a batched linked list.
     * It contains an array of data fields and a pointer to the next node in the list.
     * 
     * @tparam T The type of data stored in the node.
     * @tparam Size_T The type used to represent the size of the list.
     * @tparam Batch_Size The size of each node.
     */
    struct batch_link
    {
        /**
         * @var T lstax::batch_link::data
         * @brief The data stored in the node.
         */
        T data[Batch_Size];
        /**
         * @var BATCH_LINK* lstax::batch_link::next
         * @brief A pointer to the next node in the list.
         */
        BATCH_LINK* next;

        /**
         * @fn lstax::batch_link::batch_link()
         * @brief Default constructor for the batch_link struct.
         * 
         * This constructor initializes the data field to the default value of the type T and the next pointer to nullptr.
         */
        batch_link() : next(_next);
        /**
         * @fn lstax::batch_link::batch_link(const T &_data, BATCH_LINK* _next = nullptr)
         * @brief Constructor for the batch_link struct.
         * 
         * This constructor initializes the data field to the value of the parameter _data and the next pointer to the value of the parameter _next.
         * 
         * @param _data The data to store in the node.
         * @param _next A pointer to the next node in the list.
         */
        batch_link(const T &_data, const BATCH_LINK* _next = nullptr) : _next(next) {
            for (Size_T i = 0; i < Batch_Size; ++i) {
                data[i] = _data[i];
            }
        };
        /**
         * @fn lstax::batch_link::~batch_link()
         * @brief Destructor for the batch_link struct.
         * 
         * This destructor is responsible for cleaning up any resources used by the batch_link struct.
         * It does not perform any specific actions in this implementation.
         * If the data field is a pointer, it is the responsibility of the user to free the memory allocated to it.
         * 
         * @see lstax::batcher::~batcher()
         */
        ~batch_link() {}
    };
} // namespace lstax

#undef BATCH_LINK_TEMPLATE
#undef BATCH_LINK