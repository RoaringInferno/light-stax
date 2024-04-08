#include "fifo_list.hpp"
#define _DEBUG_PRINTLN
#include "testing.hpp"

const unsigned long test_count = _DEBUG_LIST_LOOPS;


void test_lvalue() {
    DEBUG_PRINT(<< "Constructing\n")

    lstax::fifo_list<unsigned long, unsigned long> list;

    assert(list.top == nullptr);

    DEBUG_PRINT(<< "Pushing\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        list.push(i);
        DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
        assert(list.peek() == 0);
        DEBUG_PRINT(<< "\tlist.peek() == 0\n")
        assert(list.length == i + 1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
    }

    DEBUG_PRINT(<< "Popping\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        assert(list.peek() == i);
        DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
        assert(list.length == test_count-i);
        DEBUG_PRINT(<< "\tlist.length == "<<test_count-i<<"\n")
        list.pop();
        DEBUG_PRINT(<< "\tlist.pop()\n")
    }

    assert(list.top == nullptr);
    assert(list.length == 0);

    DEBUG_PRINT(<< "Done\n")
}

void test_rvalue() {
    DEBUG_PRINT(<< "Constructing\n")

    lstax::fifo_list<unsigned long*, unsigned long> list;

    assert(list.top == nullptr);

    DEBUG_PRINT(<< "Pushing\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        auto* data = new unsigned long(i);
        list.push(data);
        DEBUG_PRINT(<< "\tlist.push("<< *data <<")\n")
        assert(*list.peek() == 0);
        DEBUG_PRINT(<< "\t*list.peek() == 0\n")
        assert(list.length == i + 1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
    }

    DEBUG_PRINT(<< "Popping\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        assert(*list.peek() == i);
        DEBUG_PRINT(<< "\t*list.peek() == "<<i<<"\n")
        assert(list.length == test_count-i);
        DEBUG_PRINT(<< "\tlist.length == "<<test_count-i<<"\n")
        delete list.peek();
        list.pop();
        DEBUG_PRINT(<< "\tlist.pop()\n")
    }

    assert(list.top == nullptr);
    assert(list.length == 0);

    DEBUG_PRINT(<< "Done\n")
}
#undef _DEBUG_PRINTLN
int main() {
    //test_lvalue();
    test_rvalue();

    return 0;
}