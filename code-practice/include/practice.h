#ifndef PRACTICE_H
#define PRACTICE_H
#include <string>
using namespace std;
class student
{
public:
    std::string name;
    int age;
    student(){};
    ~student(){};
    void display();
};

template <class T>
class LinkList{
public:
    struct Node
    {
        Node(T* x):data(x){}
        T* data;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* current;
    int length;

    LinkList();
    ~LinkList();
    void push_front(T* x);
    void delete_front(T* x);
    void display();
};
template<class T>
LinkList<T>::LinkList()
{
    this->head = NULL;
    this->tail = NULL;
    this->current = NULL;
    this->length = 0;
}
template<class T>
LinkList<T>::~LinkList()
{
    cout << "linklist deleted !"<<endl;
}
template<class T>
void LinkList<T>::push_front(T* x)
{
    Node* node = new Node(x);
    //list is empty
    if (this->head == NULL){
        this->head = node;
        this->current = node;
        this->tail = node;
        node->next = NULL;        
    }
    else {
        node->next = this->head;
        this->head = node;  
    }
}
/*    
void LinkList::addNode_tail(void* data)
{
    Node* node = new Node();
    node->data = data;
    //empty list
    if (this->tail == NULL){
        this->head = this->current = this->tail = node;
        node->next = NULL;
    } else {
        this->tail = node;
        node->next = NULL;
    }
}*/

//del node with matching data value
template<class T>
void LinkList<T>::delete_front(T* x)
{
    if (this->head != NULL){
        
    }

}
template<class T>
void LinkList<T>::display()
{
    Node* node= this->head;
    if(node == NULL){
        cout<<"This is empty linkedlist"<<endl;
    }else{
        while (node != NULL){
            node->data->display();
            node = node->next;
        }
    }
}

#endif