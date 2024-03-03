/*
* ==================== fifo.hpp ====================
* First In First Out variable-sized memory queue.
* Stores pointers to data.
*/

#pragma once

#define FIFO_TEMPLATE template<typename T>
#define FIFO Fifo<T>

#define FIFO_LINK_TEMPLATE template<typename T>
#define FIFO_LINK Fifo_Link<T>


FIFO_LINK_TEMPLATE
class Fifo_Link {
public:
    T* data; // Pointer to stored data.
    FIFO_LINK* next; // Pointer to the next link.

    // Creates a Fifo_Link with the given data.
    Fifo_Link(T* data);

    // Creates a Fifo_Link behind the given link, with the given data.
    Fifo_Link(T* data, FIFO_LINK* link);

    // Deletes the Fifo_Link.
    // [!] DOES NOT delete the data, nor any other Fifo_Links. [!]
    // [!] MUST free other memory items manually to avoid leaks. [!]
    ~Fifo_Link();
};


FIFO_TEMPLATE
class Fifo {
public:
    size_t length;

    FIFO_LINK* top;
    FIFO_LINK* bottom;

    // Constructs a stack with no data
    Fifo();

    // Constructs a stack with a single piece of data.
    Fifo(T* data);

    // Adds a link with the given data.
    // Returns a pointer to the data.
    void push(const T* data);
    void push(const T& data);

    // Views the top element.
    T* top()

    // Removes the top element.
    T* pop();

    // Indexing operator
    T* operator[](size_t index);

    // Returns the length
    size_t length();
};


#undef FIFO_TEMPLATE
#undef FIFO

#undef FIFO_LINK_TEMPLATE
#undef FIFO_LINK
