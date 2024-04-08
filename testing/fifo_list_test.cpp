#include "fifo_list.hpp"

#include "testing.hpp"

const unsigned long test_count = _DEBUG_LIST_LOOPS;

int main() {
    DEBUG_PRINT(<< "Constructing\n")

    lstax::fifo_list<unsigned long, unsigned long> list;

    assert(list.top == nullptr);

    DEBUG_PRINT(<< "Pushing\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        DEBUG_PRINT(<< "==== Loop " << i << "\n")
        list.push(i);
        DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
        assert(list.peek() == 0);
        DEBUG_PRINT(<< "\tlist.peek() == 0\n")
        assert(list.top->data == 0);
        DEBUG_PRINT(<< "\tlist.top->data == 0\n")
        assert(list.length == i + 1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
    }

    DEBUG_PRINT(<< "Popping\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        DEBUG_PRINT(<< "==== Loop " << i << "\n")
        assert(list.peek() == i);
        DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
        assert(list.top->data == i);
        DEBUG_PRINT(<< "\tlist.top->data == "<<i<<"\n")
        assert(list.length == test_count-i);
        DEBUG_PRINT(<< "\tlist.length == "<<test_count-i<<"\n")
        list.pop();
        DEBUG_PRINT(<< "\tlist.pop()\n")
    }

    assert(list.top == nullptr);
    assert(list.length == 0);

    DEBUG_PRINT(<< "Done\n")

    return 0;
}