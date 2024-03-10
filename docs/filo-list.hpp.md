# Classes
## ```lstax::FiloLink<typename T>```
A data structure to hold a data pointer and a pointer to another ```FiloLink<T>```.

### Members
```T* data```
Pointer to the data stored by the link.

```FiloLink<T>* next```
Pointer to the next link in the chain.
### Constructors
#### ```FiloLink(T* _data, FiloLink<T>* _next = nullptr)```
(```O(1)```)
Constructs a ```FiloLink``` with the provided data pointer behind the provided link pointer. It's ```next``` member will be a ```nullptr```. If a pointer is provided, sets the ```next``` member of that link to ```this```.


#### ```~FiloLink()```
(```O(1)```)
Deletes ```data```.
### Methods
None.

## ```lstax::FiloList<typename T> : public Stack<typename T>```
A first-in-last-out stack of ```FiloLink<T>```s.

### Constructors
#### ```FiloList()```
(```O(1)```)
Constructs a stack with no data.

#### ```FiloList(T* _data)```
(```O(1)```)
Constructs a stack with a single piece of data. More efficient that making an empty stack and pushing a value, as the ```FiloLink``` constructor is embedded in ```FiloList(T* _data)```.

#### ```~FiloList()```
(```O(length)```)
Deletes all links and all data.

### Members
#### ```size_t length```
Length of the stack.

#### ```FiloLink<T>* top```
Pointer to the top link (pop and push targets).

### Methods
#### ```size_t length()```
(```O(1)```)
Returns ```length```.

#### ```void push(const T* _data)```
(```O(1)```)
Adds a link with the given data.

#### ```void push(const T& _data)```
(```O(1)```)
Adds a link with the given data.

#### ```T* top()```
(```O(1)```)
Returnsa pointer to the data help by the top element.

#### ```void pop()```
(```O(1)```)
Removes the top element.

#### ```T* popOff()```
(```O(1)```)
Returns the held data. Requires 1 additional ```T``` pointer.

#### ```T* operator[](size_t _index)```
(```O(length)```)
Indexing operator. Iterates through the chain.