//
//  Queue.h
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/31.
//

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <cassert>
#include "List.h"

// 使用list实现的队列

template <typename Object>
class Queue {
private:
    List<Object> _list;
    
    
public:
    Queue() = default;
    ~Queue() = default;
    Queue(const Queue<Object> & rhs);
    Queue<Object> & operator=(const Queue<Object> &rhs);
    
    Object dequeue();
    void enqueue(const Object & x);
    
    bool empty();
    int size() const;
    Object & front();
    Object & back();
    
    const List<Object> & list() const;
    
    void print(std::ostream &out);
    void clear();
};

// 返回内部List结构
template <typename Object>
const List<Object> & Queue<Object>::list() const{
    return _list;
}

// 拷贝构造函数
template <typename Object>
Queue<Object>::Queue(const Queue<Object> & rhs){
//    调用可以拷贝rhs的运算符=
    *this = rhs;
}

// 重载=
template <typename Object>
Queue<Object> & Queue<Object>::operator=(const Queue<Object> &rhs){
    clear();
//    调用List结构的=运算符 拷贝rhs的list
    this->_list = rhs.list();
    return *this;
}

template <typename Object>
int Queue<Object>::size() const{
    return _list.size();
}

template <typename Object>
bool Queue<Object>::empty(){
    return _list.empty();
}

template <typename Object>
void Queue<Object>::enqueue(const Object & x){
    _list.push_back(x);
}

template <typename Object>
Object Queue<Object>::dequeue(){
    assert(!empty());
    Object temp = _list.front();
    _list.pop_front();
    return temp;
}

template <typename Object>
Object & Queue<Object>::front(){
    return _list.front();
}

template <typename Object>
Object & Queue<Object>::back(){
    return _list.back();
}

template <typename Object>
void Queue<Object>::clear(){
    _list.clear();
}

template <typename Object>
void Queue<Object>::print(std::ostream &out){
    out << "Queue: ";
    for (typename List<Object>::const_iterator it = _list.begin();
            it != _list.end() ; ++it) {
        out << *it << " ";
    }
    out << std::endl;
}




#endif /* Queue_h */
