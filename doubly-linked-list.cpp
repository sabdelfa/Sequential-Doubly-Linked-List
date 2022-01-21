#include "doubly-linked-list.h"
#include <cstddef>
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    //DataType tData;
   // Node *next;
   // Node *prev;
    
}

DoublyLinkedList::DoublyLinkedList()
{
   // Node *head;
   // Node *tail;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

unsigned int DoublyLinkedList::size() const
{
    //Node *tempNode = head;

  //  int size = 0;
  //  while( tempNode != NULL )
  //  {
  //     tempNode = tempNode->next;
  //     size++;
  // }
  // return size;
}

unsigned int DoublyLinkedList::capacity() const
{

}

bool DoublyLinkedList::empty() const
{
  // Node *newNode;
  // if( newNode->next == NULL ) return true;
  // else return false;
}

bool DoublyLinkedList::full() const
{
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    // returns the value at the given index;
    
  // Node *tempNode = head;
  // int searchingIndex = 0; // searchingIndex is used to keep track of the index

  // if( tempNode->next == NULL ) return -999;

  // while( tempNode != NULL )
  //  {
  //      if( searchingIndex == index ) return tempNode->data;
  //      tempNode = tempNode->next;
  //      searchingIndex++;
  //  }
}

unsigned int DoublyLinkedList::search(DataType value) const
{
 //  Node *tempNode = head;
 //  int index = 0; //index variable will be used to keep track of the index number

 //  while( tempNode != NULL )
 //  {
 //      if( tempNode->data = value ) return index;

 //      tempNode = tempNode->next;
 //      index++;
 //  }
 //   return index; // returning the side of the list?
}

void DoublyLinkedList::print() const
{
  // Node *tempNode = head;
  // if( tempNode != NULL )
  // {
  //     while( tempNode->next != NULL )
  //     {
  //         cout << "[" << tempNode->data << "], ";
  //         tempNode = tempNode->next;
  //     }
  //     cout << endl;
  // }
  // else
  // {
  //     cout << "This list is empty." << endl;
  // }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{

}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{

}

bool DoublyLinkedList::insert_front(DataType value)
{
}

bool DoublyLinkedList::insert_back(DataType value)
{
}

bool DoublyLinkedList::remove(unsigned int index)
{
}

bool DoublyLinkedList::remove_front()
{
}

bool DoublyLinkedList::remove_back()
{
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
}

