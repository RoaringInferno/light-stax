# light-stax
Lightweight stack classes for C++

## Class Naming Convention
Class and file naming follows:

Class: ```${PUSH/PULL_CONVENTION}_${STORAGE_CONVENTION}```

File: ```${PUSH/PULL_CONVENTION}_${STORAGE_CONVENTION}.hpp```

## DISCLAIMER
In this library, each class/struct is exposed IN ITS ENTIRETY. THIS IS INTENTIONAL. Members that would normally be private or protected are denoted with an underscore("_") at the beginning of their names. This is in the interest of modularity, and done because this library is intended to maximize efficiency and be fully mutable.

## POP NOTE
Pop does not always call the destructor for the object being popped. For buffer allocators, the destructor is not called until the buffer is destructed.

Please read the documentation to verify whether or not the data is destructed when popped.

### Push/Pull Conventions:
#### Stack
First-In-Last-Out
#### Queue
First-In-First-Out

### Storage Conventions
#### Linked List/List
Each datapoint is recorded as a member value on a ```Link```, which stores a pointer to the next ```Link``` in the list.
Push involves creating a new ```Link```.
Pop involves destructing a ```Link```.
2 pointer individual overhead; 1-2 pointer global overhead.
No unused memory.
#### Bucket
Each datapoint is recorded as an array entry.
Push involves dynamic allocation of an additional array space (does not actually allocate new memory).
Pop involves dynamic freeing of the array space (does not actually free memory).
No individual overhead; 2 ```Size_T``` global overhead.
```Stack_Size``` - ```length``` unused memory space.

## Class Contents
All classes contain a defaut constructor, the ```push```, ```pop```, and ```peek``` member methods, and a ```length``` variable.

Link destructors delete their associated _data, but not connected links. If the _data is a pointer, the Link will not destroy it.

Stack destructors delete all links and data. _Data destructor handles lvalue vs rvalue distinctions by template overloading.

lstax allocations use the stack.