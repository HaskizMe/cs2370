// Original

#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include <cstddef>
#include<stdexcept>
using namespace std;
using std::size_t;


// My class called Vector
class Vector
{
    enum{
        CHUNK = 10
    };

    // My attributes for vector class
    size_t capacity; // Size of the current array allocation (total number of ints, in use or not)
    size_t n_elems;  // Number of int spaces currently in use, starting from position 0
    int *data_ptr;   // Pointer to the heap array

    // Used to dynamically grow an array
    void grow(){
        // Growing array by 1.6
        capacity *= 1.6;
        int *temp = new int[capacity];
        // Copying elements to temp array
        for (int i = 0; i < capacity; i++){
            temp[i] = data_ptr[i];
        }
        // Deleting data_ptr and giving it a new memoring address of temp
        delete[] data_ptr;
        data_ptr = temp;
    };

public:
    // Object Mgt.
    Vector(){
        // default constructor that creates a starting array
        data_ptr = new int[CHUNK];
        capacity = CHUNK;
        n_elems = 0;
    }
    // Copy constuctor 
    Vector(const Vector &v){
    // Used to make a deep copy of the array
    capacity = v.capacity;
    data_ptr = new int[capacity];
    n_elems = v.n_elems;
    for(int i = 0;i<v.n_elems;i++){
        data_ptr[i] = v.data_ptr[i];
    }
    };

    // = operator to assign new objects to other objects
    Vector &operator=(const Vector &v){
    // Basically the same thing as the copy constructor
    // Except return the pointer to this object
    capacity = v.capacity;
    data_ptr = new int[capacity];
    n_elems = v.n_elems;
    for(int i = 0;i<v.n_elems;i++){
        data_ptr[i] = v.data_ptr[i];
    }
    return (*this);
    };

    // Deconstructor to not all memory leaks
    ~Vector(){
        delete[] data_ptr;
    }

    // Accessors

    // Returns the front element
    int front() const{
        // If array is empty throw an error
        if (n_elems == 0){
            throw std::range_error("Not valid index");
        }
        // Return the int in position 0, if any
        return data_ptr[0];

    };
    int back() const{
        // If array is empty throw an error
        if (n_elems == 0){
            throw std::range_error("Not valid index");
        }
        // Return last element
        return data_ptr[n_elems - 1];
    };
    int at(size_t pos) const{
        // Return element in position "pos"
        // If within valid index then return element at "pos"
        if(pos>=0 && pos<n_elems){
            return data_ptr[pos];
        }
        // else throw error
        else {
            throw std::range_error("Not valid index");
        }
    };

    size_t size() const{
        // Return n_elems
        return (size_t)n_elems;
    };

    bool empty() const{
        // Return true or false based on if empty
        return n_elems == 0;
    };

    // Mutators
    int &operator[](size_t pos){
        // Same as at but no bounds checking
        return data_ptr[pos];
    };

    // Append a new element at the end of the array
    void push_back(int item){
    // If element reaches capacity then grow the array then add element to back
    if(capacity==n_elems){
        grow();
        data_ptr[n_elems] = item;
        n_elems++;
    }
    // Else just add element to back
    else{
        data_ptr[n_elems++] = item;
    }
    };

    // Delete last element
    void pop_back(){
        // If empty throw an error
        if (n_elems == 0){
            throw std::range_error("Not valid index");
        }
        // Else delete last element in array
        else{
            data_ptr[n_elems-1] = 0;
            n_elems--;
        }
    };

    // Erase element at given position
    void erase(size_t pos){
    // If within index then find element at given position
    // and move all other elements down one
    if(pos >= 0 && pos < n_elems){

        for(int i=pos+1;i<n_elems;i++){
            data_ptr[i-1] = data_ptr[i];
        }
        // remove n_elems by one
        n_elems--;
    }
    // Else throw range error
    else{
        throw std::range_error("Out of bound");    
    }
    };
    
    // Remove item in position pos and shuffles following items left
    void insert(size_t pos, int item){ 
        // If new element reaches capacity grow the array
        if(capacity==n_elems){
            grow();
        }
        // Shuffle items right to make room for a new element
        for(int i=n_elems;i>pos;i--){
            data_ptr[i] = data_ptr[i-1];
        }
        // Add element at given position and increase n_elems
        data_ptr[pos] = item;
        n_elems++;
    };

    // n_elems = 0 (nothing else to do; keep the current capacity)
    void clear(){
        // n_elems = 0;
        for (int i = 0; i < n_elems; i++){
            data_ptr[i] = 0;
            n_elems--;
        }
    };

    // Iterators
    // Return a pointer to 1st element, or nullptr if n_elems == 0
    int *begin(){
        // If array is empty iterator will be null
        if (n_elems == 0){
            return NULL;
        }
        // Else return the pointer the first position of the array
        // Return memory address
        return &data_ptr[0];
    };

    // Return a pointer to 1 past last element, or nullptr if n_elems == 0
    int *end(){
        // If array is empty iterator will be null
        if (n_elems == 0){
            return NULL;
        }
        // Else return the pointer the last position of the array
        // Return memory address
        else{
            return &data_ptr[n_elems];
        }
    };

    // Comparators
    // Compares objects to see if they're equal
    bool operator==(const Vector &v) const{
        // If both objects have the same capacity, number of elements
        // and each element is equal to the corresponding elements from the other object
        // return true
        if(this->capacity!=v.capacity)return false;
        if(this->n_elems!=v.n_elems)return false;
        for(int i=0;i<n_elems;i++){
            if(this->data_ptr[i]!=v.data_ptr[i])return false;
        }
        return true;
    };

    // Calls the == operator to find if not equal
    bool operator!=(const Vector &v) const{
        return !(operator==(v));
    }
};
#endif
