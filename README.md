# light-stax
Easy memory allocators for C++.

## Naming Conventions
Class and file naming follows:

Internal classes: ```_<snake_case>```

Data Structure classes: ```<push/pull convention>_<storage convention>```

File containing final class: ```<push/pull convention>_<storage convention>.hpp```

Public variables: ```<snake_case>```

Private variables: ```_<snake_case>```

Const variables: ```<MACRO_CASE>```

Template arguments: ```<PascalCase>```

Public methods: ```<snake_case>```

Private methods:
- ```_<snake_case>``` denotes methods that would typically be made private or protected that reasonably abstract class behavior.
- ```_<camelCase>``` denotes methods that would typically be made private or protected that serve to ease maintainability.

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
#### Batcher
Allocates buffers along a linked list.
1/(```BatchSize```) individual overhead ; 1-2 pointer global overhead.

## Efficiency Notes
Buckets are best for problems with a high push/pop requirement with a fixed ceiling.

Batchers are best for problems with a high push/pop requirement with a heavily mutable ceiling.

Lists are best for problems with a low push/pop requirement with a mutable ceiling, where high memory efficiency is required.

None of these data structures are indexable. If an indexable data structure is needed, use a ```std::vector<T>```. If rapid access is required, save pointers to objects as you push them.