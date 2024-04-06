#pragma once

#define BATCH_LINK_TEMPLATE template<typename T, typename Size_T, Size_T Batch_Size>
#define BATCH_LINK batch_link<T, Size_T, Batch_Size>

namespace lstax
{
    BATCH_LINK_TEMPLATE
    struct batch_link
    {
        T data[Batch_Size];
        BATCH_LINK* next;

        batch_link(const BATCH_LINK* _next = nullptr) : next(_next);
        batch_link(const T (&_data)[Batch_Size], const BATCH_LINK* _next = nullptr) : _next(next) {
            for (Size_T i = 0; i < Batch_Size; ++i) {
                data[i] = _data[i];
            }
        };
        ~batch_link() {
            delete data; // CONFIRM_THIS
        }
    };
} // namespace lstax

#undef BATCH_LINK_TEMPLATE
#undef BATCH_LINK