#pragma once

#include "batcher.hpp"
#include "queue_list.hpp"

#define QUEUE_BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define QUEUE_BATCHER queue_batcher<T, Size_T, Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>

namespace lstax
{
    QUEUE_BATCHER_TEMPLATE
    struct queue_batcher : public BATCHER {
        queue_list<batch_link<T, Size_T, Batch_Size>, Size_T> batch_list;

        Size_T _bottom_index;

        queue_batcher() : BATCHER() {
            this->_push_batch();
            this->_reset_top_index_empty();
            this->_reset_bottom_index_empty();
        };
        ~queue_batcher() {};

        void push(const T& _data) override {
            if (this->_bottom_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_bottom_index_empty();
            }
            this->batch_list.bottom->data.value[this->_bottom_index] = _data;
            this->_increment_bottom_index();
            this->_increment_length();
        };
        void pop() override {
            this->_increment_top_index();
            if (this->_top_is_full()) {
                // Get the next batch
                this->_pop_batch();
                this->_reset_top_index_empty();
            }
            this->_decrement_length();
        };
        T& peek() override {
            return this->batch_list.peek()[this->_top_index];
        };

        // Interface with linked_list
        Size_T get_batch_count() const {
            return batch_list.length;
        };
        void _push_batch() {
            batch_list.push(); // Linked list must hold dereferenced batches
        };
        void _pop_batch() {
            batch_list.pop();
        };

        // Private Methods (bottom_index)
        void _increment_bottom_index() {
            this->_bottom_index++;
        };
        void _decrement_bottom_index() {
            this->_bottom_index--;
        };
        bool _bottom_is_full() const {
            return this->_bottom_index == Batch_Size;
        };
        bool _bottom_is_empty() const {
            return this->_bottom_index == 0;
        };
        void _reset_bottom_index_empty() {
            this->_bottom_index = batch_link<T, Size_T, Batch_Size>::LOWEST_INDEX;
        };
        void _reset_bottom_index_full() {
            this->_bottom_index = batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX;
        };
    };
}

#undef QUEUE_BATCHER_TEMPLATE
#undef QUEUE_BATCHER
#undef BATCHER