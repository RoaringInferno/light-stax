#include "filo_stack.hpp"

#include "testing.hpp"

const unsigned long test_count = _DEBUG_LIST_LOOPS;

int main() {
    DEBUG_PRINT(<< "Constructing\n")

    lstax::filo_stack<unsigned long, unsigned long, test_count> list;

    assert(list.top == 0);
    assert(list.length == 0);

    DEBUG_PRINT(<< "Pushing\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        list.push(i);
        DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
        assert(list.peek() == i);
        DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
        assert(list.length == i + 1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
    }

    DEBUG_PRINT(<< "Popping\n")

    for (unsigned long i = test_count-1; i < test_count; --i) {
        assert(list.peek() == i);
        DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
        assert(list.length == i+1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
        list.pop();
        DEBUG_PRINT(<< "\tlist.pop()\n")
    }

    assert(list.length == 0);

    DEBUG_PRINT(<< "Done\n")

    return 0;
}