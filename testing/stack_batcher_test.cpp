#include "stack_batcher.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "stack_batcher.hpp Test\n")

    test::test_stack_values<lstax::stack_batcher<test::Data_T, test::Size_T, BATCHER_BUFFER_SIZE>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::test_stack_pointers<lstax::stack_batcher<test::Data_T*, test::Size_T, BATCHER_BUFFER_SIZE>, DYNAMIC_DEBUG_LIST_LOOPS>();

    return 0;
}