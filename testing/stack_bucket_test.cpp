#include "stack_bucket.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "filo_stack.hpp Test\n")

    test::filo_rvalue<lstax::stack_bucket<test::Data_T, test::Size_T, test::count>>();
    test::filo_lvalue<lstax::stack_bucket<test::Data_T*, test::Size_T, test::count>>();

    return 0;
}