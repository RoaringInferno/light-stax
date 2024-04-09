#include "filo_stack.hpp"

#include "testing.hpp"

int main() {
    test::filo_lvalue<lstax::filo_stack<test::Data_T, test::Size_T, test::count>>();
    test::filo_rvalue<lstax::filo_stack<test::Data_T*, test::Size_T, test::count>>();

    return 0;
}