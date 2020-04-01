//
//  List.h
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/28.
//

#ifndef List_h
#define List_h

template <typename Object>
class List{
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;
        Node(const Object & d = Object(), Node *p = NULL, Node *n = NULL ):
        data(d), prev(p), next(n){}
    };
public:
    class const_iterator{
    public:
        const_iterator(): current(NULL){}
        const Object & operator* () const{
            return retrieve();
        }
        const_iterator & operator++ () {
            current = current->next;
            return *this;
        }
        
        const_iterator operator++ (int){
//            不是通过new 申请heap 后缀运算符先要使用原来的对象，使用完后自加
            const_iterator old = *this;
            // 调用重载过的++运算符
            ++( *this);
            return old;
        }
        
        bool operator== (const const_iterator & rhs) const{
            return current == rhs.current;
        }
        
        bool operator!= (const const_iterator &rhs) const{
            return !(*this==rhs);
        }
        
    protected:
        Node *current;
        
        Object & retrieve() const {
            return current->data;
        }
        const_iterator(Node *p):current(p){}
        
        friend class List<Object>;
    };
    class iterator:public const_iterator{
    public:
        iterator(){}
        Object & operator *(){
            return this->retrieve();
        }
        const Object & operator*() const{
            return const_iterator::operator*();
        }

        iterator & operator++ (){
            this->current = this->current->next;
            return *this;
        }
        
        iterator & operator-- (){
            this->current = this->current->prev;
            return *this;
        }
        
        iterator operator++ (int){
            iterator old = *this;
            ++(*this);
            return old;
        }
        iterator operator-- (int){
            iterator old = *this;
            --(*this);
            return old;
        }
        
        
    protected:
        iterator(Node *p):const_iterator(p){}
        friend class List<Object>;
        
    };
    
    List(){
        init();
    }
    ~List(){
        clear();
        delete head;
        delete tail;
    }
    List(const List & rhs){
        init();
//        使用重载的=运算符
        *this = rhs;
    }
    
//  const 修饰返回地址不可变
    const List & operator= (const List & rhs){
//        判断地址是否相同来决定是否是同一个对象
        if(this == &rhs){
            return *this;
        }
        clear();
        for(const_iterator it = rhs.begin(); it != rhs.end(); ++it){
            push_back(*it);
        }
        
        return *this;
    }
    
    iterator begin(){
        return iterator(head->next);
    }
    const_iterator begin() const{
        return const_iterator(head->next);
    }
    
    iterator end(){
        return iterator(tail);
    }
    const_iterator end() const{
        return const_iterator(tail);
    }
    
    int size() const{
        return theSize;
    }
    bool empty(){
        return size() == 0;
    }
    
    Object & front(){
        return *begin();
    }
    const Object & front() const{
        return *begin();
    }
    Object & back(){
        //        end是界外起始位置 back返回最后一个有效元素
        return *(--end());
    }
    const Object & back() const{
        return *(--end());
    }
    void push_front(const Object & x){
        insert(begin(), x);
    }
    void push_back(const Object & x){
        insert(end(), x);
    }
    void pop_front(){
        erase(begin());
    }
    void pop_back(){
        erase(back());
    }
    iterator insert(iterator it, const Object & x){
        Node *p = it.current;
        theSize++;
        //        插入prev节点的next 即p节点的prev位置
        Node *temp = new Node;
        temp->data = x;
        temp->next = p;
        temp->prev = p->prev;
        p->prev->next = temp;
        p->prev = temp;
        //        浓缩成一句话就是
        //        return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
        return iterator(temp);
    }
    
    iterator erase(iterator it){
        Node *p = it.current;
        iterator rtnitr(p->next);
        
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return rtnitr;
    }
    iterator erase(iterator start, iterator end){
        iterator it;
        for(it = start; it != end;){
            earse(it);
        }
        return it;
    }
    
    void clear(){
        while(!empty()){
            pop_front();
        }
    }
    
private:
    int theSize;
    Node *head;
    Node *tail;
    
    void init(){
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    
};



#endif /* List_h */
