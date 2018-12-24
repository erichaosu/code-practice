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
void student::display()
{
    cout<<"student name: "<<this->name <<"  age: "<<this->age<<std::endl;
}

template <class T>
class LinkList{
public:
    struct Node
    {
        Node(T* x, Node* y = 0):data(x), next(y){}
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
    void add_tail(T* x);
    void delete_front(T* x);
    void delete_front();
    void delete_list();
    void reverseList();
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
    this->length ++;
}
template <class T>
void LinkList<T>::add_tail(T* x)
{
    Node* node = new Node(x);
    //empty list
    if (this->tail == NULL){
        this->head = this->current = this->tail = node;
        node->next = NULL;
    } else {
        this->tail->next = node;
        this->tail = node;
        node->next = NULL;
    }
    this->length ++;
}

//del node with matching data value
template<class T>
void LinkList<T>::delete_front()
{
    Node* node;
    if (this->head != NULL){
        node = this->head;
        this->head = node->next;
        delete (node);
        this->length --;
    }
}
template <class T>
void LinkList<T>::delete_list()
{
    while (this->head != NULL){
        delete_front();
    }
}
template<class T>
void LinkList<T>::display()
{
    Node* node= this->head;
    if(node == NULL){
        cout<<"This is empty linkedlist"<<endl;
    }else{
        cout <<"There is "<<this->length << " nodes on linklist" <<endl;
        while (node != NULL){
            node->data->display();
            node = node->next;
        }
    }
}
template <class T>
void LinkList<T>::reverseList()
{
    Node* node1 = this->head;
    Node* node2 = NULL;
    this->tail = node1;
    while(this->head != NULL){
        node1 = this->head;
        this->head = this->head->next;
        node1->next = node2;
        node2 = node1;
    }
    this->head = node1;
}
#endif