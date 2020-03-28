//
//  Vector.h
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/28.
//

#ifndef Vector_h
#define Vector_h

#include <stdlib.h>

template <typename Object>
class Vector{
public:
    explicit Vector(int initSize=0): theSize(initSize), theCapacity(
        initSize+SPARE_CAPACITY){
        objects = new Object[theCapacity];
    }
    
    Vector(const Vector & rhs): objects(NULL){
        operator=(rhs);
    }
    ~Vector(){
        delete[] objects;
    }
    
    const Vector & operator= (const Vector &rhs){
        if(this != rhs){
            delete [] objects;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;
            
            objects = new Object[capacity()];
            for(int k = 0; k < size(); k++)
                objects[k] = rhs.objects[k];
        }
        
        return *this;
    }
    
    Object & operator[] (int index){
        return objects[index];
    }
    const Object & operator[](int index) const{
        return objects[index];
    }
    
    bool empty(){
        return size()==0;
    }
    
    int resize(int newSize){
        if(newSize > theCapacity)
            reserve(newSize*2+1);
        theSize = newSize;
    }
    
    void reserve(int newCapacity){
        if(newCapacity < theSize)
        {
            return ;
        }
        Object *oldArray = objects;
        objects = new Object[newCapacity];
        for(int k = 0; k < theSize; k++){
            objects[k] = *(oldArray+k);
        }
        theCapacity = newCapacity;
        delete [] oldArray;
    }
    
    int capacity() const {
        return theCapacity;
    }
    
    int size() const {
        return theSize;
    }
    
    void push_back(const Object &x){
        if(theSize == theCapacity)
            reserve(2*theCapacity +1);
        objects[theSize++] = x;
    }
    
    void pop_back(){
        theSize--;
    }
    
    const Object & back() const {
        return objects[theSize-1];
    }
    
    typedef Object * iterator;
    typedef const Object * const_iterator;
    
    iterator begin(){
        return &objects[0];
    }
    const iterator begin() const {
        return &objects[0];
    }
    iterator end(){
        return &objects[size()];
    }
    const iterator end() const{
        return &objects[size()];
    }
    
    enum { SPARE_CAPACITY = 16 };
    
private:
    int theSize = 0;
    int theCapacity = 0;
    Object *objects;
};


#endif /* Vector_h */
