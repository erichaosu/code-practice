#ifndef PRACTICE_H
#define PRACTICE_H
#include <string>
#include <vector>
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
    bool match2(student* x, student* y) { return x->name == y->name; }
    int getValue(student* x){ return x->age; }
        
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

// hash table implement using vector and linklist
//hash entry is a linklist same hash value can have multiple results 
//hash table is a vector hold many hash entries
#define SIZE 21
template<class T>
class hashEntry : public LinkList<T>
{
public:
    int key;
    T* result;
    hashEntry();
    hashEntry(T* x);
    ~hashEntry();
    int build_key(T* x);
};

template<class T>
hashEntry<T>::hashEntry()
{
    key = 0;
    result = NULL;
}
template<class T>
hashEntry<T>::hashEntry(T* x)
{
    this->key = build_key(x);
    this->result = x;
    this->add_tail(x);
}
template<class T>
int hashEntry<T>::build_key(T* x)
{
    return x->getValue(x) % SIZE;
}

template<class T>
class HashTable
{
public:
    std::vector<hashEntry<T>*> hashTable;
    HashTable();
    ~HashTable();
    void addEntry(T* x);
    void display();
    T* search(T* x);
};
template<class T>
HashTable<T>::HashTable()
{   
    for (int n = 0; n< SIZE; n++){
        hashTable.push_back(NULL);
    }
}

template<class T>
HashTable<T>::~HashTable()
{   
    hashTable.clear();
}
template<class T>
void HashTable<T>::addEntry(T* x)
{
    hashEntry<T>* newEntry = new hashEntry<T>(x);
    hashEntry<T>* oldEntry;
    int index = newEntry->key;
    if (hashTable[index] == NULL) {
        hashTable[index] = newEntry;
    }else {
        oldEntry = hashTable[index];
        oldEntry->add_tail(x);
    }
}
template<class T>
void HashTable<T>::display()
{
    int i = 0;
    hashEntry<T>* entry;
    while( i < SIZE){
        if (this->hashTable[i] != NULL){
            cout<<"entry  "<<i<<"    ";
            entry = this->hashTable[i];
            entry->LinkList<T>::display();
        }
        i++;
    }
}

template<class T>
T* HashTable<T>::search(T* x)
{
    hashEntry<T>* entry;
    int index;
    index = entry->build_key(x);
    entry = this->hashTable[index];
    while (entry->head != NULL){
        if (entry->head->data->match2(entry->head->data, x)){
            cout<<"found ";
            entry->head->data->display(); 
        }
        entry->head = entry->head->next;
    }

}
class singleton
{
private: 
    static singleton* instance;
public:
    static  singleton* getInstance() {
        if (instance == NULL){
            instance = new singleton;
        }
        return instance;
    }
};

class write_only_port
{
    unsigned shadow;
    volatile unsigned int* address;
public:
    write_only_port(unsigned int*);
    ~write_only_port(){}
    void operator|=(unsigned);
    void operator&=(unsigned);
};
write_only_port::write_only_port(unsigned int* portAddr)
{
    address = (unsigned*)portAddr;
    shadow = *address;
    //*address = 0;
}
void write_only_port::operator|=(unsigned val)
{
    shadow |= val;
    *address = shadow;
}
void write_only_port::operator&=(unsigned val)
{
    shadow &= val;
    *address = shadow;
}
#endif