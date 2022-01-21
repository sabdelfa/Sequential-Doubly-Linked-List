#include <iostream>
#include <list>
#include "sequential-list.h"
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    size_ = 0;

    data_= new DataType[ capacity_ ];

}

SequentialList::~SequentialList()
{
    delete[] data_; // To free up data.

    data_ = NULL; // To prevent dangling pointer.
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if( size_ == 0 ) return true;
    else return false;
}

bool SequentialList::full() const
{
    if( size_ == capacity_ ) return true;
    else return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if( index < 0 || index > size_ || index > capacity_ || size_ == 0 ) return data_[size_];  // If the index is invalid (outside array) return the last element.

    return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    if( size_ == 0 ) return size_;

    for (int i = 0; i < size_; ++i)
    {
        if(data_[i] == val) return i;
    }
    return size_;
}

void SequentialList::print() const
{
    if( size_ == 0 ) cout << "Nothing to display. The array is empty.";
    cout << "[";
    for (int i = 0; i <= size_; ++i)
    {
        cout << data_[i];
        cout << "] ";
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if( full() ) return false;
    if( index < 0 || index > size_ ) return false;

    for (int i = size_; i > index; --i)
    {
        data_[i] = data_[i-1];
    }

    data_[index] = val;
    size_++;
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    if( full() ) return false;

    insert(val, 0);
    return true;

}

bool SequentialList::insert_back(DataType val)
{
    if( full() ) return false;

    insert(val, size_);
    return true;

}

bool SequentialList::remove(unsigned int index)
{

    if (size_ == 0) return false;
    if (index < 0 || index > size_) return false;

    for (int i = index; i < (size_-1) ; ++i)
    {
        data_[i] = data_[i + 1];
    }
    DataType temp;
    data_[size_-1] = temp;
    size_--;
    return true;
}

bool SequentialList::remove_front()
{
    if (size_ == 0) return false;

    remove(0);
    return true;
}

bool SequentialList::remove_back()
{
    if (size_ == 0) return false;

    remove(size_);
    return true;
}

bool SequentialList::replace(unsigned int index, DataType val)
{

    if( index > size_ || index > capacity_ ) return false; // If there is no data at that index or it has surpassed the array, then return false.

    data_[index] = val;
    return true;
}

