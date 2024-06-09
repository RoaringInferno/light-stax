#pragma once

#include "stack.hpp"

#define BATCHER_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCHER batcher<T, Size_T, Batch_Size>
#define BATCH_LINK batch_link<T, Size_T, Batch_Size>

namespace lstax
{\
    BATCHER_TEMPLATE
    struct batcher : public stack<T, Size_T>
    {
        typedef BATCH_LINK batch_link;

        Size_T _batch_count;

        batch_link* furthest;

        batcher() {};
        ~batcher() {};

        void push(const &T data) override {};
        void pop() override {};
        T peek() override {};
    }; 
}

#undef BATCHER_TEMPLATE
#undef BATCHER
