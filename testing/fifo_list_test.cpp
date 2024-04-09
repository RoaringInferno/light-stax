#include "fifo_list.hpp"

#include "testing.hpp"


int main() {
    test::fifo_lvalue<lstax::fifo_list<test::Data_T, test::Size_T>>();
    test::fifo_rvalue<lstax::fifo_list<test::Data_T*, test::Size_T>>();

    return 0;
}