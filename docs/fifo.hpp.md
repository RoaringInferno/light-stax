# Classes
## ```lstax::Fifo_Link<typename T>```
A data structure to hold a data pointer and a pointer to another ```Fifo_Link<T>```.

### Members
```T* data```
Pointer to the data stored by the link.

```Fifo_Link<T>* next```
Pointer to the next link in the chain.
### Constructors
#### ```Fifo_Link(T* _data, Fifo_Link<T>* _previous = nullptr)```
(```O(1)```)
Constructs a ```Fifo_Link``` with the provided data pointer behind the provided link pointer. It's ```next``` member will be a ```nullptr```. If a pointer is provided, sets the ```next``` member of that link to ```this```.


#### ```~Fifo_Link()```
(```O(1)```)
Deletes ```data```.
### Methods
None.

## ```lstax::Fifo<typename T>```
A first-in-first-out stack of ```Fifo_Link<T>```s.

### Constructors
#### ```Fifo()```
(```O(1)```)
Constructs a stack with no data.

#### ```Fifo(T* _data)```
(```O(1)```)
Constructs a stack with a single piece of data. More efficient that making an empty stack and pushing a value, as the ```Fifo_Link``` constructor is embedded in ```Fifo(T* _data)```.

#### ```~Fifo()```
(```O(length)```)
Deletes all links and all data.

### Members
#### ```size_t length```
Length of the stack.

#### ```Fifo_Link<T>* top```
Pointer to the top link (pop target).

#### ```Fifo_Link<T>* bottom```
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

#### ```void pop(T* _data)```
(```O(1)```)
Removes the top element. Overwrites the given pointer with a pointer to the data.

#### ```T* pop_off()```
(```O(1)```)
Returns the held data. Requires 1 additional ```T``` pointer.

#### ```T* operator[](size_t _index)```
(```O(length)```)
Indexing operator. Iterates through the chain.
