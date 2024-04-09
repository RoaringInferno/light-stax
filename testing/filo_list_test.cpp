#include "filo_list.hpp"

#include "testing.hpp"

int main() {
    test::filo_lvalue<lstax::filo_list<test::Data_T, test::Size_T>>();
    test::filo_rvalue<lstax::filo_list<test::Data_T*, test::Size_T>>();

    return 0;
}