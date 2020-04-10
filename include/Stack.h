/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/3/2020, 5:37:56 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/3/2020, 5:38:02 PM 
 * Description:
 * C++ 使用List实现的栈
 * 因为栈的空间大小总是不固定的，而且仅仅pop和push
 *
*/ 

#include "List.h"

template <typename Object>
class Stack{

    public:
    

    public:
    Stack(){

    }

    ~Stack(){

    }

    Stack(const Stack & rhs){
        *this = rhs;
    }

    const Stack & operator=(const Stack & rhs){
        clear();
        _list = rhs.SList();
        return *this;
    }


public:
    size_t size() const{
        return _list.size();
    }

    void clear(){
        _list.clear();
    }
// 将元素x压入栈，返回它的引用
    Object push(Object x){
        _list.push_back(x);
        return _list.back();
    }
    // 返回栈顶元素 并在队列中删除之
    Object pop(){
        Object temp = _list.back();
        _list.pop_back();
        return temp;
    }

    bool empty() const {
        return _list.empty();
    }

    void print(std::ostream &out) const {
        out << "Stack_(id" << (this) << ") :";
        typename List<Object>::const_iterator it;
        for(it = _list.begin(); it!=_list.end(); ++it){
            out << *it << " ";
        }
        out << std::endl;
    }

    const List<Object> & SList() const {
        return _list;
    }

    private:
    List<Object> _list;

};


