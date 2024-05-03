#include "queue_bucket.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "fifo_stack.hpp Test\n")

    DEBUG_HEADER_PRINT(<< "Static\n")
    test::fifo_rvalue<lstax::static_queue_bucket<test::Data_T, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();
    test::fifo_lvalue<lstax::static_queue_bucket<test::Data_T*, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();

    DEBUG_HEADER_PRINT(<< "Dynamic\n")
    test::fifo_rvalue<lstax::dynamic_queue_bucket<test::Data_T, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::fifo_lvalue<lstax::dynamic_queue_bucket<test::Data_T*, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();    

    return 0;
}