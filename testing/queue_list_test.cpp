#include "queue_list.hpp"

#include "testing.hpp"


int main() {
    DEBUG_HEADER_PRINT(<< "fifo_list.hpp Test\n")

    test::fifo_rvalue<lstax::queue_list<test::Data_T, test::Size_T>>();
    test::fifo_lvalue<lstax::queue_list<test::Data_T*, test::Size_T>>();

    return 0;
}