#include "stack_bucket.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "filo_stack.hpp Test\n")

    DEBUG_HEADER_PRINT(<< "==  Static\n")
    test::test_stack_values<lstax::static_stack_bucket<test::Data_T, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();
    test::test_stack_pointers<lstax::static_stack_bucket<test::Data_T*, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();

    DEBUG_HEADER_PRINT(<< "==  Dynamic\n")
    test::test_stack_values<lstax::dynamic_stack_bucket<test::Data_T, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::test_stack_pointers<lstax::dynamic_stack_bucket<test::Data_T*, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();

    return 0;
}