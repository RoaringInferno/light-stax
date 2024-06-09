#include "stack_list.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "filo_list.hpp Test\n")

    test::test_stack_values<lstax::stack_list<test::Data_T, test::Size_T>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::test_stack_pointers<lstax::stack_list<test::Data_T*, test::Size_T>, DYNAMIC_DEBUG_LIST_LOOPS>();

    return 0;
}