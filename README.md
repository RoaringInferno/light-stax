# light-stax
Lightweight stack classes for C++

## Class Contents
All classes contain a defaut constructor, the ```push```, ```pop```, and ```peek``` member methods, and a ```length``` variable.

Link destructors delete their associated _data, but not connected links. If the _data is a pointer, the Link will not destroy it.

Stack destructors delete all links and data. _Data destructor handles lvalue vs rvalue distinctions by template overloading.
