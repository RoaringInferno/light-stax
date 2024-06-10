#pragma once

#include "batcher.hpp"
#include "stack_list.hpp"

#define STACK_BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define STACK_BATCHER stack_batcher<T, Size_T, Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>

namespace lstax
{
    STACK_BATCHER_TEMPLATE
    struct stack_batcher : public BATCHER
    {
        stack_list<batch_link<T, Size_T, Batch_Size>, Size_T> batch_list;

        stack_batcher() : BATCHER() {
            this->_push_batch();
            this->_reset_top_index_empty();
        };
        ~stack_batcher() {};

        void push(const T& _data) override {
            if (this->_top_is_full()) {
                // Get the next batch
                this->_push_batch();
                this->_reset_top_index_empty();
            }
            this->batch_list.peek()[this->_top_index] = _data;
            this->_increment_top_index();
            this->_increment_length();
        };
        void pop() override {
            if (this->_top_is_empty()) {
                // Get the next batch
                this->_pop_batch();
                this->_reset_top_index_full();
            } else {
                this->_decrement_top_index();
            }
            this->_decrement_length();
        };
        T& peek() override {
            if (this->_top_is_empty()) {
                return this->batch_list.top->next->data.value[batch_link<T, Size_T, Batch_Size>::HIGHEST_INDEX];
            }
            return this->batch_list.peek()[this->_top_index-1];
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
    };
}