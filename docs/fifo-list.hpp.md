# Classes
## ```lstax::FifoLink<typename T>```
A data structure to hold a data pointer and a pointer to another ```FifoLink<T>```.

### Members
```T* data```
Pointer to the data stored by the link.

```FifoLink<T>* next```
Pointer to the next link in the chain.
### Constructors
#### ```FifoLink(T* _data, FifoLink<T>* _previous = nullptr)```
(```O(1)```)
Constructs a ```FifoLink``` with the provided data pointer behind the provided link pointer. It's ```next``` member will be a ```nullptr```. If a pointer is provided, sets the ```next``` member of that link to ```this```.


#### ```~FifoLink()```
(```O(1)```)
Deletes ```data```.
### Methods
None.

## ```lstax::FifoList<typename T> : public Stack<typename T>```
A first-in-first-out stack of ```FifoLink<T>```s.

### Constructors
#### ```FifoList()```
(```O(1)```)
Constructs a stack with no data.

#### ```FifoList(T* _data)```
(```O(1)```)
Constructs a stack with a single piece of data. More efficient that making an empty stack and pushing a value, as the ```FifoLink``` constructor is embedded in ```FifoList(T* _data)```.

#### ```~FifoList()```
(```O(length)```)
Deletes all links and all data.

### Members
#### ```size_t length```
Length of the stack.

#### ```FifoLink<T>* top```
Pointer to the top link (pop target).

#### ```FifoLink<T>* bottom```
Pointer to the bottom link (push target).

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
