#include "stack_bucket.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "filo_stack.hpp Test\n")

    DEBUG_HEADER_PRINT(<< "==  Static\n")
    test::filo_rvalue<lstax::static_stack_bucket<test::Data_T, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();
    test::filo_lvalue<lstax::static_stack_bucket<test::Data_T*, test::Size_T, STATIC_DEBUG_LIST_LOOPS>, STATIC_DEBUG_LIST_LOOPS>();

    DEBUG_HEADER_PRINT(<< "==  Dynamic\n")
    test::filo_rvalue<lstax::dynamic_stack_bucket<test::Data_T, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::filo_lvalue<lstax::dynamic_stack_bucket<test::Data_T*, test::Size_T, DYNAMIC_DEBUG_LIST_LOOPS>, DYNAMIC_DEBUG_LIST_LOOPS>();

    return 0;
}