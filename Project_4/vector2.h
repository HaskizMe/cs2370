//This works

#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include <cstddef>
#include<stdexcept>
using namespace std;
using std::size_t;

class Vector
{
    enum
    {
        CHUNK = 10
    };
    int *data_ptr;   // Pointer to the heap array
    size_t capacity; // Size of the current array allocation (total number of ints, in use or not)
    size_t n_elems;  // Number of int spaces currently in use, starting from position 0
    void grow();

public:
    // Object Mgt.
    Vector();
    Vector(const Vector &v);            // Copy constructor
    Vector &operator=(const Vector &v); // Copy assignment operator
    ~Vector();

    // Accessors
    int front() const;        // Return the int in position 0, if any
    int back() const;         // Return last element (position n_elems-1)
    int at(size_t pos) const; // Return element in position "pos" (0-based)
    size_t size() const;      // Return n_elems
    bool empty() const;       // Return n_elems == 0

    // Mutators
    int &operator[](size_t pos);       // Same as at but no bounds checking
    void push_back(int item);          // Append a new element at the end of the array
    void pop_back();                   // --n_elems (nothing else to do; returns nothing)
    void erase(size_t pos);            // Remove item in position pos and shuffles following items left
    void insert(size_t pos, int item); // Shuffle items right to make room for a new element
    void clear();                      // n_elems = 0 (nothing else to do; keep the current capacity)

    // Iterators
    int *begin(); // Return a pointer to 1st element, or nullptr if n_elems == 0
    int *end();   // Return a pointer to 1 past last element, or nullptr if n_elems == 0

    // Comparators
    bool operator==(const Vector &v) const;
    bool operator!=(const Vector &v) const;
};
Vector::Vector(){
    data_ptr = new int[CHUNK];
    capacity = CHUNK;
    n_elems = 0;
}
Vector::Vector(const Vector &v){
    this->capacity = v.capacity;
    this->data_ptr = new int[this->capacity];
    this->n_elems = v.n_elems;
    for(int i = 0;i<v.n_elems;i++){
        this->data_ptr[i] = v.at(i);
    }
}
Vector& Vector::operator=(const Vector &v){
    this->capacity = v.capacity;
    this->data_ptr = new int[this->capacity];
    this->n_elems = v.n_elems;
    for(int i = 0;i<v.n_elems;i++){
        this->data_ptr[i] = v.at(i);
    }
    return (*this);
}
Vector::~Vector(){
    delete[] data_ptr;
}

void Vector::grow(){
    capacity = (capacity*16)/10;
    int* temp_ptr = new int[capacity];
    for(int i=0;i<capacity;i++){
        temp_ptr[i] = data_ptr[i];
    } 
    delete[] data_ptr;
    data_ptr = temp_ptr;
    }

int Vector::front() const{// Return the int in position 0, if any
    if(this->n_elems==0){
        throw range_error("Out of bound");
    }else{
        return data_ptr[0];
    }
}        
int Vector::back() const{         // Return last element (position n_elems-1)
    if(this->n_elems==0){
        throw range_error("Out of bound");
    }else{
        return data_ptr[n_elems-1];
    }
}
int Vector::at(size_t pos) const{ // Return element in position "pos" (0-based)
    if(pos>=0 && pos<n_elems){
        return data_ptr[pos];

    }else{
        throw range_error("Out of bound");
    }
}
size_t Vector::size() const{      // Return n_elems
    return (size_t)n_elems;
}
bool Vector::empty() const{
    return n_elems==0;
}
int& Vector::operator[](size_t pos){       // Same as at but no bounds checking
    return this->data_ptr[pos];
} 
void Vector::push_back(int item){          // Append a new element at the end of the array
    if(capacity==n_elems){
        grow();
        data_ptr[n_elems] = item;
        n_elems++;
    }else{
        data_ptr[n_elems++] = item;
    }
}
void Vector::pop_back(){                   // --n_elems (nothing else to do; returns nothing)
    if(n_elems==0){
        throw range_error("Out of bound");
    }else{
        n_elems--;
    }
}
void Vector::erase(size_t pos){            // Remove item in position pos and shuffles following items left
    if(pos>=0 && pos<n_elems){
        for(int i=pos+1;i<n_elems;i++){
            data_ptr[i-1] = data_ptr[i];
        }
        n_elems--;
    }else{
        throw range_error("Out of bound");    
    }
}
void Vector::insert(size_t pos, int item){ // Shuffle items right to make room for a new element
    if(capacity==n_elems){
        grow();
    }
    for(int i=n_elems;i>pos;i--){
        data_ptr[i] = data_ptr[i-1];
    }
    data_ptr[pos] = item;
    n_elems++;
}
void Vector::clear(){
    delete[] data_ptr;
    data_ptr = new int[CHUNK];
    capacity = CHUNK;
    n_elems = 0;
}

// Iterators
    int* Vector::begin(){// Return a pointer to 1st element, or nullptr if n_elems == 0
        if(n_elems==0)return nullptr;
        return &data_ptr[0];
    } 
    int* Vector::end(){// Return a pointer to 1 past last element, or nullptr if n_elems == 0
        if(n_elems==0)return nullptr;
        return &data_ptr[n_elems];
    }   

    // Comparators
    bool Vector::operator==(const Vector &v) const{
        if(this->capacity!=v.capacity)return false;
        if(this->n_elems!=v.n_elems)return false;
        for(int i=0;i<n_elems;i++){
            if(this->data_ptr[i]!=v.data_ptr[i])return false;
        }
        return true;
    }
    bool Vector::operator!=(const Vector &v) const{
        return !(operator==(v));
    }

#endif




// original

// #ifndef VECTOR_H
// #define VECTOR_H
// #include<iostream>
// #include <cstddef>
// #include<stdexcept>
// using namespace std;
// using std::size_t;

// class Vector
// {
//     enum
//     {
//         CHUNK = 10
//     };
//     size_t capacity; // Size of the current array allocation (total number of ints, in use or not)
//     size_t n_elems;  // Number of int spaces currently in use, starting from position 0
//     int *data_ptr;   // Pointer to the heap array
//     void grow()
//     {
//         // Growing array by 1.6
//         capacity *= 1.6;
//         int *temp = new int[capacity];
//         // Copying elements to temp array
//         for (int i = 0; i < capacity; i++)
//         {
//             temp[i] = data_ptr[i];
//         }
//         // Deleting data_ptr and giving it a new memoring address of temp
//         delete[] data_ptr;
//         data_ptr = temp;
//     };

// public:
//     // Object Mgt.
//     Vector()
//     {
//         data_ptr = new int[CHUNK];
//         capacity = CHUNK;
//         n_elems = 0;
//     }
//     Vector(const Vector &v){
//         // Copy constructor
//         this->capacity = v.capacity;
//         this->data_ptr = new int [this->capacity];
//         for(int i = 0; i < this->n_elems; ++i){
//             this->data_ptr[i] = v.data_ptr[i];

//         }
//     };
//     Vector &operator=(const Vector &v){
//         // Copy assignment operator
//         this->capacity = v.capacity;
//         // delete[] this->data_ptr;
//         this->data_ptr =  new int[this->capacity];
//         for(int i = 0; i < this->n_elems; ++i){
//             this->data_ptr[i] = v.data_ptr[i];
//         }
//         return *this;
//     };

//     ~Vector()
//     {
//         delete[] data_ptr;
//     }

//     // Accessors
//     int front() const
//     {
//         if (n_elems == 0)
//         {
//             throw std::range_error("Not valid index");
//         }
//         // Return the int in position 0, if any
//         return data_ptr[0];

//     };
//     int back() const
//     {
//         if (n_elems == 0)
//         {
//             throw std::range_error("Not valid index");
//         }
//         // Return last element (position n_elems-1)
//         return data_ptr[n_elems - 1];
//     };
//     int at(size_t pos) const
//     {
//         // Return element in position "pos" (0-based)
//         if(pos>=0 && pos<n_elems){
//             return data_ptr[pos];
//         }
//         else{
//             throw std::range_error("Not valid index");
//         }
//     };

//     size_t size() const
//     {
//         // Return n_elems
//         return (size_t)n_elems;
//     };
//     bool empty() const
//     {
//         return n_elems == 0;
//     };

//     // Mutators
//     int &operator[](size_t pos)
//     {
//         // Same as at but no bounds checking
//         return data_ptr[pos];
//     };
//     void push_back(int item){          // Append a new element at the end of the array
//     if(capacity==n_elems){
//         grow();
//         data_ptr[n_elems] = item;
//         n_elems++;
//     }else{
//         data_ptr[n_elems++] = item;
//     }
// };

//  // Append a new element at the end of the array
//     void pop_back()
//     {
//         // --n_elems (nothing else to do; returns nothing)
//         if (n_elems == 0)
//         {
//             throw std::range_error("Not valid index");
//         }
//         else{
//             n_elems--;
//         }
//     };
//     void erase(size_t pos)
//     {
//     if(pos >= 0 && pos < n_elems){

//         for(int i=pos+1;i<n_elems;i++){
//             data_ptr[i-1] = data_ptr[i];
//         }

//         n_elems--;
//     }else{
//         throw std::range_error("Out of bound");    
//     }
//     }; // Remove item in position pos and shuffles following items left
//     void insert(size_t pos, int item)
//     {
//         if ((pos >= n_elems) || (pos < 0))
//         {
//             throw std::range_error("Not valid index");
//         }
//         // n_elems++;
//         if(pos == 0){
//             int *temp = new int[capacity];
//             // Copying elements to temp array
//             for (int i = 0; i < capacity; i++)
//             {
//                 temp[i+1] = data_ptr[i];
//             }
//             data_ptr = temp;
//             data_ptr[pos] = item;
//             ++n_elems;
//         }
//         else if (n_elems != capacity){
//             std::cout << "inserting" << std:: endl;
//             for (int i = n_elems; i >= pos; i--)
//             {
//                 data_ptr[i + 1] = data_ptr[i];
//                 // data_ptr[i] = data_ptr[i - 1];
//             }
//             data_ptr[pos] = item;
//             ++n_elems;
//         }
//         else{
//             grow();
//             insert(pos, item);
//         }

//         data_ptr[pos] = item;
//     }; // Shuffle items right to make room for a new element
//     void clear()
//     {
//         // n_elems = 0;
//         for (int i = 0; i < n_elems; i++)
//         {
//             data_ptr[i] = 0;
//             n_elems--;
//         }
//     }; // n_elems = 0 (nothing else to do; keep the current capacity)

//     // Iterators
//     int *begin(){
//         if (n_elems = 0){
//             return NULL;
//         }
//         return &data_ptr[0];
//     }; // Return a pointer to 1st element, or nullptr if n_elems == 0
//     int *end(){
//         if (n_elems == 0){
//             return NULL;
//         }
//         else{
//             return &data_ptr[n_elems];
//         }
//     }; // Return a pointer to 1 past last element, or nullptr if n_elems == 0

//     // Comparators
//     bool operator==(const Vector &v) const{
//         if(this->capacity!=v.capacity)return false;
//         if(this->n_elems!=v.n_elems)return false;
//         for(int i=0;i<n_elems;i++){
//             if(this->data_ptr[i]!=v.data_ptr[i])return false;
//         }
//         return true;
//     };
//     bool operator!=(const Vector &v) const{
//         bool notvalid = true;
//         for(size_t i = 0; i < n_elems; i++){
//             if(data_ptr[i] != v.data_ptr[i]){
//                 notvalid = false;
//             }
//             else{
//                 notvalid = true;
//             }
//     };
//             return notvalid;

//     }
// };

// #endif
