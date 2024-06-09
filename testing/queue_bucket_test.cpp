#include "queue_bucket.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "fifo_stack.hpp Test\n")

    DEBUG_HEADER_PRINT(<< "Static\n")
    test::test_queue_values<lstax::static_queue_bucket<test::Data_T, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();
    test::test_queue_pointers<lstax::static_queue_bucket<test::Data_T*, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();

    DEBUG_HEADER_PRINT(<< "Dynamic\n")
    test::test_queue_values<lstax::dynamic_queue_bucket<test::Data_T, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::test_queue_pointers<lstax::dynamic_queue_bucket<test::Data_T*, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();    

    return 0;
}