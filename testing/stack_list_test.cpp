#include "stack_list.hpp"

#include "testing.hpp"

int main() {
    DEBUG_HEADER_PRINT(<< "filo_list.hpp Test\n")

    test::filo_rvalue<lstax::stack_list<test::Data_T, test::Size_T>>();
    test::filo_lvalue<lstax::stack_list<test::Data_T*, test::Size_T>>();

    return 0;
}