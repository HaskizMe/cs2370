#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

// comment these 3 lines out later
#include <iostream>
// #include <vector>
// using namespace std;
// uncomment this later
using std::size_t;

class Vector
{
    enum
    {
        CHUNK = 10
    };
    size_t capacity; // Size of the current array allocation (total number of ints, in use or not)
    size_t n_elems;  // Number of int spaces currently in use, starting from position 0
    int *data_ptr;   // Pointer to the heap array
    void grow()
    {
        // Growing array by 1.6
        capacity *= 1.6;
        int *temp = new int[capacity];
        // Copying elements to temp array
        for (int i = 0; i < capacity; i++)
        {
            temp[i] = data_ptr[i];
        }
        // Deleting data_ptr and giving it a new memoring address of temp
        delete[] data_ptr;
        data_ptr = temp;
    };

public:
    // Object Mgt.
    Vector()
    {
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
    }
    Vector(const Vector &v){
        // Copy constructor
        // data_ptr = v.data_ptr;
        std::cout << "copy constructor called" << std::endl;

        this->n_elems = v.n_elems;
        this->data_ptr = new int [this->n_elems];
        for(int i = 0; i < this->n_elems; ++i){
            this->data_ptr[i] = v.data_ptr[i];
        }
    };            // Copy constructor
    Vector &operator=(const Vector &v){
        std::cout << "operator= called" << std::endl;
        // (*this->data_ptr) = (*v.data_ptr);
        // data_ptr = v.data_ptr;
        this->n_elems = v.n_elems;
        delete[] this->data_ptr;
        this->data_ptr =  new int[this->n_elems];
        for(int i = 0; i < this->n_elems; ++i){
            this->data_ptr[i] = v.data_ptr[i];
        }
        return *this;
    }; // Copy assignment operator

    ~Vector()
    {
        delete[] data_ptr;
    }

    // Accessors
    int front() const
    {
        if (n_elems == 0)
        {
            throw std::range_error("Not valid index");
        }
        // Return the int in position 0, if any
        return data_ptr[0];
    };
    int back() const
    {
        if (n_elems == 0)
        {
            throw std::range_error("Not valid index");
        }
        // Return last element (position n_elems-1)
        return data_ptr[n_elems - 1];
    };
    int at(size_t pos) const
    {
        // Return element in position "pos" (0-based)
        if (pos > capacity || n_elems == 0)
        {
            throw std::range_error("Not valid index");
        }
        return data_ptr[pos];
    };

    size_t size() const
    {
        // Return n_elems
        return n_elems;
    };
    bool empty() const
    {

        return n_elems == 0;
    };

    // Mutators
    int &operator[](size_t pos)
    {
        // Same as at but no bounds checking
        return data_ptr[pos];
    };
    void push_back(int item)
    {
        if (n_elems == capacity)
        {
            grow();
        }
        data_ptr[n_elems] = item;
        ++n_elems;
    }; // Append a new element at the end of the array
    void pop_back()
    {
        // --n_elems (nothing else to do; returns nothing)
        if (n_elems == 0)
        {
            throw std::range_error("Not valid index");
        }
        n_elems--;
    };
    void erase(size_t pos)
    {
        if (pos > n_elems || n_elems == 0)
        {
            throw std::range_error("Not valid index");
        }
        for (int i = pos; i < n_elems; i++)
        {
            data_ptr[i] = data_ptr[i + 1];
        }
        n_elems--;

    }; // Remove item in position pos and shuffles following items left
    void insert(size_t pos, int item)
    {
        if ((pos >= n_elems) || (pos < 0))
        {
            throw std::range_error("Not valid index");
        }
        // n_elems++;
        if(pos == 0){
            int *temp = new int[capacity];
            // Copying elements to temp array
            for (int i = 0; i < capacity; i++)
            {
                temp[i+1] = data_ptr[i];
            }
            data_ptr = temp;
            data_ptr[pos] = item;

            // for(int i = n_elems; i >= pos; i--){
            //     data_ptr[i] = data_ptr[i-1];
            // }
            // data_ptr[pos] = item;
            ++n_elems;
        }
        else if (n_elems != capacity){
            std::cout << "inserting" << std:: endl;
            for (int i = n_elems; i >= pos; i--)
            {
                data_ptr[i + 1] = data_ptr[i];
                // data_ptr[i] = data_ptr[i - 1];
            }
            data_ptr[pos] = item;
            ++n_elems;
        }
        else{
            grow();
            insert(pos, item);
        }

        data_ptr[pos] = item;
    }; // Shuffle items right to make room for a new element
    void clear()
    {
        n_elems = 0;
        for (int i = 0; i < n_elems; i++)
        {
            data_ptr[i] = 0;
        }
    }; // n_elems = 0 (nothing else to do; keep the current capacity)

    // Iterators
    int *begin()
    {
        int *ptr = data_ptr;
        if (n_elems = 0)
        {
            return nullptr;
        }
        // ptr = &data_ptr[0];
        ptr = data_ptr + n_elems;
        return &data_ptr[0];
    }; // Return a pointer to 1st element, or nullptr if n_elems == 0
    int *end()
    {
        // int* ptr;
        if (n_elems = 0)
        {
            return nullptr;
        }
        // ptr = &data_ptr[n_elems-1];
        return &data_ptr[n_elems - 1];
    }; // Return a pointer to 1 past last element, or nullptr if n_elems == 0

    // void print(){
    //     for(int i; i < n_elems; i++){
    //         std::cout << data_ptr[i] << std::endl;
    //     }

    // };
    // Comparators
    bool operator==(const Vector &v) const{
        bool valid = false;
        for(size_t i = 0; i < n_elems; i++){
            if(data_ptr[i] == v.data_ptr[i]){
                valid = true;
            }
            else {
                valid = false;
            }
        }
        return valid;
    };
    bool operator!=(const Vector &v) const{
        bool notvalid = true;
        for(size_t i = 0; i < n_elems; i++){
            if(data_ptr[i] != v.data_ptr[i]){
                notvalid = false;
            }
            else{
                notvalid = true;
            }
    };
            return notvalid;

    }
};

#endif