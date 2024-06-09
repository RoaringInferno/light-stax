#pragma once

#include "data_structure.hpp"
#include "batch_link.hpp"
#include "linked_list.hpp"

#define BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>
#define DATA_STRUCTURE data_structure<T, Size_T>

namespace lstax
{
    BATCHER_TEMPLATE
    struct batcher : public DATA_STRUCTURE {
        Size_T _top_index; // Points to the first empty index in the top batch

        batcher() : DATA_STRUCTURE() {};
        ~batcher() {};

        // Private Methods
        void _increment_top_index() {
            this->_top_index++;
        };
        void _decrement_top_index() {
            this->_top_index--;
        };

        bool _top_is_full() const {
            return this->_top_index == Batch_Size;
        };
        bool _top_is_empty() const {
            return this->_top_index == 0;
        };
        void _reset_top_index() {
            if (this->get_batch_count() == 0) {
                // Make a new empty batch
                this->_push_batch();
                this->_top_index = 0;
            } else {
                // Reset to the top of an assumed full batch
                this->_top_index = Batch_Size - 1;
            }
        };
        void _reset_top_index_empty() {
            this->_top_index = batch_link<T, Size_T, Batch_Size>::LOWEST_INDEX;
        };
        void _reset_top_index_full() {
            this->_top_index = batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX;
        };
    };
}

#undef BATCHER_TEMPLATE
#undef BATCHER
#undef DATA_STRUCTURE