#include "queue_bucket.hpp"

#include "testing.hpp"

const unsigned long test_count = _DEBUG_LIST_LOOPS;

int main() {
    DEBUG_PRINT(<< "Constructing\n")

    lstax::queue_bucket<unsigned long, unsigned long, test_count> list;

    assert(list.length == 0);
    assert(list.top == 0);

    DEBUG_PRINT(<< "Pushing\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        DEBUG_PRINT(<< "==== Loop " << i << "\n")
        list.push(i);
        DEBUG_PRINT(<< "\tlist.push("<< i<<")\n")
        assert(list.peek() == 0);
        DEBUG_PRINT(<< "\tlist.peek() == 0\n")
        assert(list.length == i + 1);
        DEBUG_PRINT(<< "\tlist.length == "<<i+1<<"\n")
    }

    DEBUG_PRINT(<< "Popping\n")

    for (unsigned long i = 0; i < test_count; ++i) {
        DEBUG_PRINT(<< "==== Loop " << i << "\n")
        assert(list.peek() == i);
        DEBUG_PRINT(<< "\tlist.peek() == "<<i<<"\n")
        assert(list.length == test_count-i);
        DEBUG_PRINT(<< "\tlist.length == "<<test_count-i<<"\n")
        list.pop();
        DEBUG_PRINT(<< "\tlist.pop()\n")
    }

    assert(list.length == 0);

    DEBUG_PRINT(<< "Done\n")

    return 0;
}