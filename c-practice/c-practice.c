#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include "c-practice.h"
#include <stdint.h>

//member functions of student
int compareStudent(const student *s1, const student *s2)
{
    return strcmp(s1->name,s2->name);
}

int compareStudentage(const student *s1, const student *s2)
{
    return (s1->age > s2->age)? 1:-1;
}
void displayStudent(const student *s)
{
    printf("%s\t%d\n",s->name,s->age);
}
typedef int (*COMPARE)(const void *, const void*);
typedef void (*DISPLAY)(const void *);

//1 single linklist
typedef struct _element{
    void   *data;
    struct _element *next;
}element;

typedef struct _linklist{
    element *head;
    element *tail;
    element*current;
}linklist;

void init_linklist(linklist *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(linklist* list, void *data)
{
    element *node = (element*)malloc(sizeof(element));
    node->data = data;
    if (list->head == NULL){
        // new list
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }else {
        //list already exist
        node->next = list->head;
        list->head = node;
    }
}

void reverselinklist(linklist *list)
{   
    element *node1 = list->head;
    element *node2 = NULL;
    while(list->head != NULL){
        node1 = list->head;
        list->head = list->head->next;
        node1->next = node2;
        node2 = node1;
    }
    list->head = node1;
}

void displayLinklist(linklist *list, DISPLAY display)
{
    if (list->head == NULL) return;
    element *node = list->head;
    while (node){
        display(node->data);
        node = node->next;
    }
}
//2 big endian 
static inline bool bigEndian()
{
    uint32_t i = 1;
    uint8_t *j = (uint8_t *)&i;
    return (*j == 0);
}
//3 queue implementation is using linklist
// enqueue to add node at head
//dequeue to take node from tail
typedef linklist queue;

void enqueue(queue *q, void *node)
{
    addHead(q, node);
}
void *dequeue(queue *q)
{
    element *node = NULL;
    void *dat;
    element *secondLastNode = NULL;
    // empty queue
    if ((q->head == NULL)&&(q->tail==NULL)) return NULL;
    node = (element *)q->head;
    if (node->next == NULL) {
        q->head = NULL;
        q->tail = 0;
        dat = node->data;
        free (node);
        return dat;
    }
    secondLastNode = node;
    node = node->next;
    while (node){
        if (node->next == NULL){
            q->tail = secondLastNode;
            q->tail->next = NULL;
            dat = node->data;
            free(node);
            return dat;
        }
        secondLastNode = node;
        node = node->next;
    }
    //last one is NULL
    q->tail = NULL;
    q->head = NULL;
    q->current = NULL;
    dat = secondLastNode->data;
    free(secondLastNode);
    return dat; 
}

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
    q->current = NULL;
}
//4  stack also use linklist
// stack is FILO
//push addHead
//pop  get from 
typedef linklist stack;
void init_stack(stack *stk)
{
    init_linklist(stk);
}

void push(stack* stk, void*data)
{
    addHead(stk,data);
}

void *pop(stack *stk)
{
   element*node = stk->head;
   // 3 cases 1.stack is empty
   // 2. stack has only one elemnet
   //3. stack 
   if(node == NULL){
       return NULL;
   }else if(node == stk->tail) {
       stk->head = stk->tail = NULL;
       void *data = node->data;
       free(node);
       return data;
   }else {
       stk->head = stk->head->next;
       void *data = node->data;
       free(node);
       return data;
   }
}

//5 tree
//binary search tree(BST) all left child less than parent node
// all right child greater parent node
typedef struct tree_{
    void *data;
    struct tree_ *left;
    struct tree_ *right;
}treenode;

void inserttreenode(treenode **root, COMPARE compare, void *data )
{
    treenode* node = (treenode*)malloc(sizeof(treenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if (*root == NULL) {
        *root = node;
        return;
    }
    while (1) {
        if (compare((*root)->data, data)>0) {
            //data is smaller
            if ((*root)->left !=NULL){
                *root = (*root)->left;
            }else {
                (*root)->left = node;
                break;
            }
        }else {
            // data is larger than root
            if ((*root)->right !=NULL){
                *root = (*root)->right;
            }else {
                (*root)->right = node;
                break;
            }
        }
    }
}
void displaytree(treenode **root, DISPLAY display)
{
    if ((*root)->data == NULL){
        return;
    }
    display((*root)->data);
    if ((*root)->left != NULL){
        displaytree(&((*root)->left), display);
    }
    if ((*root)->right != NULL){
        displaytree(&((*root)->right), display);
    }
}

void displaytree2(treenode **root, DISPLAY display)
{
    treenode* node1;
    treenode* node2;
    if ((*root) == NULL) return;
    display((*root)->data);
    if ((*root)->left != NULL) {
        node1 = (*root)->left;
    }
    if ((*root)->right != NULL) {
        node2 = (*root)->right;
    }
    while(1){
        if (node1 != NULL){
            display(node1->data);
            node1 = node1->left;
        }else if ((*root)->right != NULL){
            *root = (*root)->right;
            display((*root)->data);
        }else {
            break;
        }
    }
}
//6  hash table
//using array and linklist
// linklist hold same hash key entries

#define SIZE 20

typedef struct hashentry{
    int key;
    int result;
    struct hashentry *next;
}hashentry_t;

//allocate static hashTable as a array
hashentry_t *hashTable[SIZE];

int init_hashtable()
{
    for (int i =0; i<SIZE; i++){
        hashTable[i] = NULL;
    }
}

int hash_build_key(int val)
{
    return val % SIZE;
}
void hash_table_add(int value, int result)
{
    int hash_index = hash_build_key(value);
    hashentry_t *ent = (hashentry_t*)malloc(sizeof(hashentry_t));
    if (hashTable[hash_index]==NULL){
        hashTable[hash_index]=ent;
        ent->next = NULL;
        return;
    }
    //hash collision, link ent to tail of linklist
    hashentry_t *head = hashTable[hash_index];
    while(head){
        if (head->next == NULL){
            head->next = ent;
            ent->next = NULL;
            return;
        }
        head = head->next;
    }
}
// hash table show
// hash table lookup


//7 integer to ascii
void reverse_str(char *str)
{
    int i = 0;
    int len = 0 ;
    while (str[i++]!= '\0'){
        len ++;
    }
    char tmp;
    if (len == 1) return;
    for(i=len-1; i >= len/2; i--){
        tmp = str[i];
        str[i] = str[len-1 - i];
        str[len-1-i]=tmp;
    }
}

char* itoa(int num, char *str, int base)
{
    int i =0;
    bool isNegative = false;
    if (!str) {
        printf("no buffer allocated \n");
        return NULL;
    }
    //set 0 for num=0
    if(num == 0) {
        str[i] = '0';
        str[++i] = '\0';
        return str;
    }
    //if negative number and base is 10
    if (num <0 && base ==10){
        isNegative =true;
        num = -num;
    }
    while (num != 0){
        int rem = num % base;
        str[i++] = (rem > 9)? (rem - 10)+'a':rem + '0';
        num = num /base;
    }
    if (isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse_str(str);

    return str;
}
 
//8 get common members(intersection) of two array
int intersect()
{
    int v1[] = {10,3,5,6,7,8};
    int v2[] = {2,4,5,7,8};
    int ret[6];
    int i=0,j=0, k=0;
    int v1size = sizeof(v1)/sizeof(int);
    int v2size = sizeof(v2)/sizeof(int);
    int big = v1size>v2size?v1size:v2size;
    int small = v1size<v2size?v1size:v2size;

    for (i=0; i<big;i++){
        for(j=0;j<small;j++){
            if (v1[i]== v2[j]){
                ret[k]=v1[i];
                k++;
            }
        }
    }
    for (int i =0; i <k; i++)
    printf("%d \n",ret[i]);
}

//9 another singly linklist implementation
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode{
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val){
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}
//10 delete odd node in singly linklist
LinkedListNode* deleteOdd(LinkedListNode* list) {
    LinkedListNode *curr = list;
    LinkedListNode *head = list; // the new list head
    LinkedListNode *list_even;
    LinkedListNode *odd_node;
    //find the first even node
    while (curr != NULL && curr->val%2 != 0){
        odd_node = curr;
        curr = curr->next;
        //free odd node
        free(odd_node);
    }
    if (curr == NULL) {
        printf ("no odd node found \n");
        return NULL;
    }
    //the new list head starts here
    head = curr;
    list_even = curr;
    curr = curr->next;
    //do remove odd until the end
    while(curr != NULL){
        if (curr->val%2 ==0){
            list_even->next = curr;
            list_even = curr;
            curr = curr->next;
        }else{
            //this is odd node
            odd_node = curr;
            curr = curr->next;
            free(odd_node); 
        }  
    }
    list_even->next = NULL;
    return head;
}

int bitXor(int x, int y) 
{
    int a = x & y;
    int b = ~x & ~y;
    int z = ~a & ~b;
    return z;
} 

// get a integer array, remove the odd member
// first input is list size
// then input member value for each node   
int getIntArray_removeOdd()
{
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    LinkedListNode* res;
    
    int _list_size = 0;
    int _list_item;
    LinkedListNode* _list = NULL;
    LinkedListNode* _list_tail = NULL;
    scanf("%d\n", &_list_size);
    int _list_i;
    for(_list_i = 0; _list_i < _list_size; _list_i++) {
        scanf("%d", &_list_item);
        if(_list_i == 0) {
    	_list = _insert_node_into_singlylinkedlist(_list, _list_tail, _list_item);
    	_list_tail = _list;
    	}
        else {
    	    _list_tail = _insert_node_into_singlylinkedlist(_list, _list_tail, _list_item);
        }
    }
    
    res = deleteOdd(_list);
    while (res != NULL) {
        printf("%d\n", res->val);
        
        res = res->next;
    }
    
    fclose(f);
    return 0;
}

//11 get max xor value given a range of left and right
int maxXor(int left, int right) {
    int maxXor_val = 0;
    //get xor with left,right
    int lxor = left ^ right;
    int i =0;
    // get the bit position of lxor
    while (lxor){
        i++;
        lxor >>= 1;
    }
    int j =1;
    while (i--){
        maxXor_val += j;
        j <<=1;
    }
    return maxXor_val;
} 

int* two_sum(const int* array, int array_length, int target)
{
    int i, j, k = 0;
    int reminder;
    static int result[2];
    int temp_len = 0;
    bool found = false;

    int temp[array_length];
    for (i = 0; i < array_length; i++){
        reminder = target - array[i];
        // search temp array for reminder
        for (j = 0; j < temp_len; j++){
            if (reminder == temp[j]){
                found = true;
            }
        }
        if (found) {
            result[0] = array[i];
            result[1] = reminder;
            return result;
        } else {
            temp[k++] = array[i];
            temp_len = k;
        }   
    }
}
int main()
{
    int test_array[6] = {1,2,3,5,6,4};
    int* result;
    int arr_len;
    arr_len = sizeof(test_array)/sizeof(test_array[0]);
    result = two_sum(test_array, arr_len, 9);
    printf("result = { %d, %d} \n", result[0], result[1]);
    // endian check
    printf(" this system is %s\n", bigEndian()?"big endian":"small endian");
    // linklist
    linklist list;
    student s1 ={"tom",20};
    student s2 ={"Jerry", 24};
    student s3 ={"mary", 19};
    init_linklist(&list);
    addHead(&list, &s1);
    addHead(&list, &s2);
    addHead(&list, &s3);
    displayLinklist(&list, (DISPLAY)displayStudent);
    reverselinklist(&list);
    displayLinklist(&list, (DISPLAY)displayStudent);

    //queue using linklist addHead, retrieve tail
    queue q;
    init_queue(&q);
    enqueue(&q, &s1);
    enqueue(&q, &s2);
    enqueue(&q, &s3);
    student *elm = (student*)dequeue(&q);
    while (elm){
    printf("queue out {%s, %d} \n", ((student*)elm)->name, ((student*)elm)->age);
    elm = (student*)dequeue(&q);
    }
    
    // stack also use linklist
    // push = addHead, pop= get from head

    // tree
    treenode *tree = NULL;
    inserttreenode(&tree, (COMPARE)compareStudentage, &s1);
    inserttreenode(&tree, (COMPARE)compareStudentage, &s2);
    inserttreenode(&tree, (COMPARE)compareStudentage, &s3);
    displaytree2(&tree, (DISPLAY)displayStudent);

    //intersection of two array
    intersect();

    // get a integer array and remove odd member
    //getIntArray_removeOdd();
    // print max xor value of two given values
    printf("%d \n", maxXor(3,4));
    char* chr = "hello";
    reverse_str(chr);
    printf(" reverse str = %s \n", chr);
    return 0;
}
