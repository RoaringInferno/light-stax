# light-stax
Lightweight stack classes for C++

## Class Naming Convention
Class and file naming follows:

Class: ```${PUSH/PULL_CONVENTION}_${STORAGE_CONVENTION}```

File: ```${PUSH/PULL_CONVENTION}_${STORAGE_CONVENTION}.hpp```

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