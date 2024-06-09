#include "queue_list.hpp"

#include "testing.hpp"


int main() {
    DEBUG_HEADER_PRINT(<< "fifo_list.hpp Test\n")

    test::test_queue_values<lstax::queue_list<test::Data_T, test::Size_T>, DYNAMIC_DEBUG_LIST_LOOPS>();
    test::test_queue_pointers<lstax::queue_list<test::Data_T*, test::Size_T>, DYNAMIC_DEBUG_LIST_LOOPS>();

    return 0;
}