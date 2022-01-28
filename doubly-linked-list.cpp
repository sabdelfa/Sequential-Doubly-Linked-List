#include "doubly-linked-list.h"
#include <cstddef>
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data): value(data), next(NULL), prev(NULL)
{
}

DoublyLinkedList::DoublyLinkedList() // Constructor
{
    size_ = 0;

    head_ = NULL;
    tail_ = NULL;
}

DoublyLinkedList::~DoublyLinkedList() // Destructor
{
    // Free all dynamically allocated memory, if any.

    Node* cur = head_;
    Node* prev;
    while( cur != NULL )
    {
        prev = cur;
        cur = cur->next;
        delete prev;
    }

    head_ = NULL;
    tail_ = NULL;
}

unsigned int DoublyLinkedList::size() const
{
    // Return the number of element nodes in the list
    return size_;

}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if( size_ == 0 ) return true;
    else return false;
}

bool DoublyLinkedList::full() const
{
    if( size_ == CAPACITY ) return true;
    else return false;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    // Returns the value at the given index in the list.

    if( index < 0 || index > (size_-1) || empty() ) return tail_->value;

    Node* temp = head_;

    int count = 0; //index variable will be used to keep track of the index number

    while( temp != NULL )
    {
        if( count == index ) return temp->value;

        temp = temp->next;
        count++;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const
{

    // Search a given value (from head to tail). Return index of this value if found.

    if( empty() ) return size_; // If list is empty, return the size of the list

    Node* temp = head_;

    int index = 0; //index variable will be used to keep track of the index number

    while( temp != NULL )
    {
        if( temp->value == value ) return index;

        temp = temp->next;
        index++;
    }
    return size_;

}

void DoublyLinkedList::print() const
{
    Node* temp = head_;

    while( temp != NULL )
    {
        cout << "[" << temp->value << "], ";
        cout << endl;
        temp = temp->next;
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    // Returns a pointer to the node at index.

    if( index < 0 || index > (size_-1) ) return NULL;

    Node* temp = head_;
    int count = 0;

    while( temp != NULL )
    {
        if( index == count ) return temp;

        temp = temp->next;
        count++;
    }

}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    // Insert a value into the list at a given index.

    if( index < 0 || index > size_ || full() ) return false;

    // Empty:
    Node* newNode = new Node( value );
    newNode->next = NULL;
    newNode->prev = NULL;

    if( head_ == NULL )
    {
        head_ = newNode;
        tail_ = newNode;
        size_++;
        return true;
    }

    // Insert at front of list:
    if( index == 0 )
    {
        newNode->next = head_;
        head_->prev = newNode;

        head_ = newNode;
        size_++;
        return true;
    }

    // Insert at back of list:
    if( index == size_ )
    {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;

        size_++;
        return true;
    }

    // General case:
    Node* temp = head_;     // Node temp is the counting node
    int count = 0;

    while( temp != NULL )
    {
        if( count == (index-1) )
        {
            newNode->next = temp->next;
            temp->next->prev = newNode;

            temp->next = newNode;
            newNode->prev = temp;
            size_++;
            return true;
        }
        temp = temp->next;
        count++;
    }
}

bool DoublyLinkedList::insert_front(DataType value)
{
    return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
      return insert( value, size_ );
}

bool DoublyLinkedList::remove(unsigned int index)
{
    // Delete the value from the list at the given index.

    Node* temp = head_;

    // Empty list or bad index:
    if( size_ == 0 || index < 0 || index > size_ ) return false;

    // Remove front:
    if( index == 0 )
    {
        // If there's only 1 node:
        if( temp->next == NULL )
        {
            head_ = NULL;
            tail_ = NULL;
        }
        else
        {
            // If there is more than 1 node:
            head_ = temp->next;
            head_->prev = NULL;
        }

        size_--;
        delete temp;
        return true;
    }


    // Remove back & general case:
    int count = 0;
    while( temp != NULL )
    {
        if( count == index )
        {
            // Remove back:
            if( temp->next == NULL )     // If temp->next == NULL, remove the tail.
            {
                tail_ = tail_->prev;
                tail_->next = NULL;
                size_--;
                delete temp;
                return true;
            }
            else
            {
                // General case:
                Node* countingNode;

                countingNode = temp->prev;
                countingNode->next = temp->next;

                countingNode = temp->next;
                countingNode->prev = temp->prev;

                size_--;
                delete countingNode;
                delete temp;
                return true;
            }
        }
        temp = temp->next;
        count++;
    }
}

bool DoublyLinkedList::remove_front()
{
    return remove(0);
}

bool DoublyLinkedList::remove_back()
{
    return remove(size_-1);
}


bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    // Replaces the value at the given index with the given value

    if( index < 0 || index > (size_-1) || empty() ) return false;

    Node* temp = head_;
    int count = 0;

    while( temp != NULL )
    {
        if( count == index )
        {
            temp->value = value;

            return true;
        }

        temp = temp->next;
        count++;
    }
    return false;
}