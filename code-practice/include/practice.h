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
    bool compare (student* x);
    bool match(student* x, student* y){ return x->age == y->age; }
        
};
bool student::compare(student* x)
{
    return this->age < x->age;
}

void student::display()
{
    cout<<this->name <<"  age: "<<this->age<<std::endl;
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
        this->head = this->head->next;
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

template<class T>
class Queue{
public:
    struct Node
    {
        Node(T* x, Node* y=0):data(x),next(y){}
        T* data;
        Node* next;
    };
    Node* Head;
    Node* Tail;
    int Length;
    Queue();
    ~Queue();
    void enqueue(T* data);
    T* dequeue();
    void reverse();
    void display();
};
template <class T>
Queue<T>::Queue()
{
    Head = Tail = NULL;
    Length = 0;
}
template <class T>
Queue<T>::~Queue()
{
    cout << "Queue is deleted !" <<endl;
}

template <class T>
void Queue<T>::enqueue(T* data)
{
    Node* node = new Node(data);
    if (this->Head == NULL){
        Head = Tail = node;
        node->next = NULL;
    }else {
        node->next = this->Head;
        this->Head = node;
    }
    Length ++;
}
template <class T>
T* Queue<T>::dequeue()
{
    Node* node;
    T*    data;
    if (this->Head == NULL) {
        return NULL;
    }else if (this->Head->next == NULL){
        // only one node in queue
        node = this->Head;
        this->Head = this->Tail = NULL;
        Length = 0;
        data = node->data;
        delete node;
        return data;
    }else {
        node = this->Head;
        this->Head = node->next;
        Length --;
        data = node->data;
        delete node;
        return data;
    }
}
template<class T>
void Queue<T>::display()
{
    Node* node = this->Head;
    if (node == NULL){
        cout<< "Queue is empty, nothing to display !"<<endl;
    }else {
        cout<< "Queue has "<<Length<<" members"<<endl;
        while( node != NULL){
            node->data->display();
            node = node->next; 
        }
    }
}

template<class T>
class Stack : public Queue<T>
{
public:
    Stack(){}
    ~Stack(){}
    T* pop();
    void push(T* data);
};

template<class T>
void Stack<T>::push(T* data)
{
    this->enqueue(data);
}
template<class T>
T* Stack<T>::pop()
{
    return this->dequeue();
}
template<class T>
class Tree
{
public:
    struct Node
    {
        Node(T*x, Node* y = 0, Node* z = 0):data(x),left(y), right(z){} 
        T* data;
        Node* left;
        Node* right;
    };
    Node* root;
    Tree();
    ~Tree();
    void addNode(T* data);
    void delNode(T* data);
    void display(Node* root);
    int nodeCount(Node* root);
    void searchNode(Node* root, T* data);
};
template<class T>
Tree<T>::Tree()
{
    this->root = NULL;
}
template<class T>
Tree<T>::~Tree()
{
    cout<<"Tree is deleted !"<<endl;
}
template<class T>
void Tree<T>::addNode(T* data)
{
    Node* node;
    if (this->root == NULL){
        this->root = new Node(data);
        this->root->left = NULL;
        this->root->right = NULL;
    }else {
        node = this->root;
        while (node != NULL){
            if (data->compare(node->data)){
                if (node->left == NULL){
                    node->left = new Node(data);
                    break;
                }else {
                    node = node->left;
                }
            }else {
                if (node->right == NULL){
                    node->right = new Node(data);
                    break;
                }else {
                    node = node->right;
                }
            }
        }
    }
}
template<class T>
void Tree<T>::display(Node* root)
{
    if (root != NULL){
        root->data->display();
        display(root->left);
        display(root->right);
    }   
}
template<class T>
int Tree<T>::nodeCount(Node* root)
{
    static int numNode = 0;
    if (root != NULL){
        numNode ++;
        nodeCount(root->left);
        nodeCount(root->right);
    }
    return numNode;   
}
template<class T>
void Tree<T>::searchNode(Node* root, T* data)
{
    if (root != NULL){
        if (data->match(root->data, data)){
            root->data->display();
        }
        searchNode(root->left, data);
        searchNode(root->right, data);
    } 
}
#endif