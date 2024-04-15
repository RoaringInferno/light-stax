# light-stax
Lightweight stack classes for C++

## TODO
filo -> stack
fifo -> queue

stack -> bucket
stack.hpp -> data_structure.hpp


New naming convention:
- fifo_list -> queue_list
- filo-stack -> stack_bucket

### Add
- Heap
Stack and Heap base classes

## Class Contents
All classes contain a defaut constructor, the ```push```, ```pop```, and ```peek``` member methods, and a ```length``` variable.

Link destructors delete their associated data, but not connected links. If the data is a pointer, the Link will not destroy it.

Stack destructors delete all links and data. See Link Destructors for data deletion for reference values.
