# Classes
## ```lstax::Stack<typename T>```
Parent class and interface for ```lstax::Filo_Link<typename T>``` and ```lstax::Fifo_Link<typename T>```
### Constructors
#### ```Stack()```
Default constructor. Empty.

#### ```~Stack()```
Empty destructor.

### Members
No members.
### Methods
#### ```virtual size_t length() = 0```
Returns the length

#### ```virtual void push(const T* _data) = 0```
Adds a link with the given data.

#### ```virtual void push(const T& _data) = 0```
Adds a link with the given data.

#### ```virtual T* top() = 0```
Views the top element.

#### ```virtual void pop() = 0```
Removes the top element.

#### ```virtual T* popOff() = 0```
Returns the held data. Requires 1 additional pointer.

#### ```virtual T* operator[](size_t _index) = 0```
Indexing operator