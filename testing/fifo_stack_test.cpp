#include "fifo_stack.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "fifo_stack.hpp Test\n")

    test::fifo_rvalue<lstax::fifo_stack<test::Data_T, test::Size_T, test::count>>();
    test::fifo_lvalue<lstax::fifo_stack<test::Data_T*, test::Size_T, test::count>>();

    return 0;
}