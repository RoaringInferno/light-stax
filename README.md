# light-stax
Lightweight stack classes for C++

## TODO
### Add
- Heap
Stack, Bucket, and Heap base classes

## Class Contents
All classes contain a defaut constructor, the ```push```, ```pop```, and ```peek``` member methods, and a ```length``` variable.

Link destructors delete their associated data, but not connected links. If the data is a pointer, the Link will not destroy it.

Stack destructors delete all links and data. See Link Destructors for data deletion for reference values.
