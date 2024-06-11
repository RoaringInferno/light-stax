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

        virtual void _push_batch() = 0;
        virtual void _pop_batch() = 0;

        // Private Methods (_top_index)
        bool _top_is_full() const {
            return this->_top_index == Batch_Size;
        };
        bool _top_is_empty() const {
            return this->_top_index == 0;
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