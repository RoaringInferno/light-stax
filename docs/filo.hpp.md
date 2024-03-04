# Classes
## ```lstax::Filo_Link<typename T>```
A data structure to hold a data pointer and a pointer to another ```Filo_Link<T>```.

### Members
```T* data```
Pointer to the data stored by the link.

```Filo_Link<T>* next```
Pointer to the next link in the chain.
### Constructors
#### ```Filo_Link(T* _data, Filo_Link<T>* _next = nullptr)```
(```O(1)```)
Constructs a ```Filo_Link``` with the provided data pointer behind the provided link pointer. It's ```next``` member will be a ```nullptr```. If a pointer is provided, sets the ```next``` member of that link to ```this```.


#### ```~Filo_Link()```
(```O(1)```)
Deletes ```data```.
### Methods
None.

## ```lstax::Filo<typename T> : public Stack<typename T>```
A first-in-last-out stack of ```Filo_Link<T>```s.

### Constructors
#### ```Filo()```
(```O(1)```)
Constructs a stack with no data.

#### ```Filo(T* _data)```
(```O(1)```)
Constructs a stack with a single piece of data. More efficient that making an empty stack and pushing a value, as the ```Filo_Link``` constructor is embedded in ```Filo(T* _data)```.

#### ```~Filo()```
(```O(length)```)
Deletes all links and all data.

### Members
#### ```size_t length```
Length of the stack.

#### ```Filo_Link<T>* top```
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