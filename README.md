# BME-122-Sequential-Doubly-Linked-List
Sequential and doubly linked list code


# Sequential List Implementation

# Purpose of this project:
In this project, you practice your knowledge about array by implementing a data
type called sequential list. The header file sequential-list.h, which is explained below,
provides the structure of the SequentialList class with declarations of member functions.
Do not modify the signatures of any of these functions. You need to implement all of the
public member functions listed in sequential-list.cpp. Note that we set a maximum
capacity for this list. That is, when the capacity is reached, the list cannot take any more
items.

# Description:

The details of the header file sequential-list.h are as follows:
DataType defines the kind of data that the list will contain. Being public, it can be accessed
directly as SequentialList::DataType.

# Member variables:
data : Pointer to the memory of array allocated to store the list data.
capacity : Returns the maximum number of elements the list can hold.
size : Returns the number of elements in the list.

# Constructor and Destructor:

SequentialList(unsigned int cap): Creates a new SequentialList with the given number
of elements.
SequentialList(): Destructor, which frees all dynamically allocated memory.
SequentialList(const SequentialList& rhs): Copy constructor, which copies one list
rhs to another list. For this assignment, you don’t have to implement it. Just leave it blank
in private section.
SequentialList& operator=(const SequentialList& rhs): Assignment operator for the
operations of the form list1 = list2. For this assignment, you don’t have to implement it.
Just leave it blank in private section.

# Constant member functions:

Constant member functions are those function which do not modify class member variables.
unsigned int size() const: Returns the number of elements in the list.
unsigned int capacity() const: Returns the maximum number of elements the list can
hold.
bool empty() const: Returns true if the list is empty, false otherwise.
bool full() const: Returns true if the list is at capacity, false otherwise.
DataType select(unsigned int index) const: Returns the value at the given index in
the list. If index is invalid, return the value of the last element. (When the list is empty,
size is 0, any index for select will be invalid. In this case, you can arbitrarily return a data
item such as the one with index 0 to satisfy the return data requirement. Note that this is
undefined behaviour, so we don’t know what this data value will be. It is the left over after
previous operations at that memory space. In practice, we will need to check this special case
before calling the select method. In this assignment, we will not use any test case related to
this special case.)
unsigned int search(DataType val) const: Searches for the given value, following the
order from head to tail of the list, and returns the index of this value if found (for the first
time the value is found). Returns the size of the list if no such value can be found in the list.
void print() const: Prints all elements in the list to the standard output. You can choose
the printing format, and this will not affect grading.

# Non-constant member functions:

These functions can potentially modify member variable of the class.

bool insert(DataType val, unsigned int index): Inserts a value into the list at a given
index. Returns true if successful and false otherwise.
bool insert front(DataType val): Inserts a value at the beginning of the list. Returns
true if successful and false otherwise.
bool insert back(DataType val): Inserts a value at the end of the list. Returns true if
successful and false otherwise.
bool remove(unsigned int index): Deletes the value from the list at the given index.
Returns true if successful and false otherwise.
bool remove front(): Deletes the value from the beginning of the list. Returns true if
successful and false otherwise.
bool remove back(): Deletes the value at the end of the list. Returns true if successful and
false otherwise.
bool replace(unsigned int index, DataType val): Replaces the value at the given index with the given value. It is considered as an invalid input when no existing data has been
stored at the input index, and in this case it should return false and do nothing. Returns
true if successful and false otherwise.



# Doubly Linked List Implementation

# Purpose of this project:

In this second part, you practice your knowledge about linked list by implementing
a data type called doubly linked list. The header file doubly-linked-list.h, which is
explained below, provides the structure of the DoublyLinkedList class with declarations
of member functions. Do not modify the signatures of any of these functions. You need
to implement all of the public member functions listed in doubly-linked-list.cpp. The
memory used by this list will change dynamically as nodes are inserted and removed from
the list.

# Description:

The details of the header file doubly-linked-list.h are as follows:
DataType defines the kind of data that the list will contain. Being public, it can be accessed
directly as DoublyLinkedList::DataType.


# Member variables:
Node: This is a structure declaration. Node has been declared inside the class as private, to
make sure users do not access nodes directly. Node contains the following member variables:
value: Value of the node.
next: Address of the next element in the list.
prev: Address of the previous element in the list.
head : Pointer to the first node of the list.
tail : Pointer to the last node of the list.
size : Number of elements (nodes) in the list.

# Constructor and Destructor:

DoublyLinkedList(): Initializes an empty doubly linked list.
DoublyLinkedList(): Destructor, which frees all dynamically allocated memory, if any.
DoublyLinkedList(const DoublyLinkedList& rhs): Copy constructor, which copies one
list rhs to another list. For this assignment, you don’t have to implement it. Just leave it
blank in private section.
DoublyLinkedList& operator=(const DoublyLinkedList& rhs): Assignment operator for
the operations of the form list1 = list2. For this assignment, you don’t have to implement
it. Just leave it blank in private section.

# Constant member functions:

Constant member functions are those function which do not modify class member variables.
unsigned int size() const: Returns the number of elements nodes in the list.
unsigned int capacity() const: Returns the maximum number of elements the list can
hold.
bool empty() const: Returns true if the list is empty, false otherwise.
bool full() const: Returns true if the list is at capacity, false otherwise.
DataType select(unsigned int index) const: Returns the value at the given index in
the list. If index is invalid, return the value of the last element. (When the list is empty,
size is 0, any index for select will be invalid. In this case, you can arbitrarily return a
value casted into DataType such as (DataType)-999. In practice, we will need to check this
special case before calling the select method. In this assignment, we will not use any test
case related to this special case.)
unsigned int search(DataType val) const: Searches for the given value, following the
order from head to tail of the list, and returns the index of this value if found (for the first
time the value is found). Returns the size of the list if no such value can be found in the list.
void print() const: Prints all elements in the list to the standard output. You can choose
the printing format, and this will not affect grading.
Node* getNode(unsigned int index) const: Returns a pointer to the node at index. Re2
turn NULL if the index is invalid. This is a helper function. You may or may not need to
use it in your implementation, depending on your preference.

# Non-constant member functions:

These functions can potentially modify member variable of the class.
bool insert(DataType val, unsigned int index): Inserts a value into the list at a given
index. Returns true if successful and false otherwise.
bool insert front(DataType val): Inserts a value at the beginning of the list. Returns
true if successful and false otherwise.
bool insert back(DataType val): Inserts a value at the end of the list. Returns true if
successful and false otherwise.
bool remove(unsigned int index): Deletes the value from the list at the given index.
Returns true if successful and false otherwise.
bool remove front(): Deletes the value from the beginning of the list. Returns true if
successful and false otherwise.
bool remove back(): Deletes the value at the end of the list. Returns true if successful and
false otherwise.
bool replace(unsigned int index, DataType val): Replaces the value at the given index with the given value. Returns true if successful and false otherwise.
Note: All indexes must start from 0
