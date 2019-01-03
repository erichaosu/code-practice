//============================================================================
// Name        : praactice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include "../include/practice.h"
using namespace std;

class solution{

public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    bool isUnique(const std::string &str);
    bool isBigEndian();
    int findOdd(vector<int>&x);
    void swap(int &x, int &y);
    void reverseStr(char *str);
    void itoa(int num, char* str, int base);

};
typedef solution* solutionPtr;
//itoa
void solution::itoa(int num, char* str, int base)
{
    bool negative = false;
    int i=0;
    if (num ==0) {
        str[i] = '0';
        str[i++] = '\0';
    }
    if (num < 0){
        negative = true;
        num = -num;
    }
    while (num > 0){
        int rem = num % base; 
        str[i] = (rem > 9)? (rem -10)+ 'a':rem + '0';
        i++;
        num = num/base;
    }
    if (negative){
        str[i++] = '-';
    }
    str[i] ='\0';
    reverseStr(str);
}

// reverse string
void solution::reverseStr(char * str)
{
    const char* strPtr = str;
    char tem;
    int length = 0;
    while (*strPtr != '\0'){
        length ++;
        strPtr ++ ;
    }
    if ((length == 0) || (length == 1)) return;
    for (int i =0; i < length/2; i ++){
        tem = str[i];
        str[i] = str[length - i - 1];
        str[length- i -1] = tem; 
    }
}
// swap two number without using temporary number
void solution::swap(int &x, int &y)
{
    x = x^y;
    y = x^y;
    x = x^y;
}
//check a number in a array that only odd occurance
int solution::findOdd(vector<int>&x)
{
    int n = x.size();
    int result;
    for (int i=0;i < n; i++){
        result ^= x[i];
    }
    return result;
}

//check if this computer is big endian
bool solution::isBigEndian()
{
    uint32_t i = 12345678;
    uint8_t *j= (uint8_t*)&i;
    cout<<(*j-48)<<endl;
    return (*j == 0);
}
// find any two number sum which equal to target
vector<int> solution::twoSum(vector<int>& nums, int target) {
    int i;
    vector<int> v(2);
    std::unordered_map<int,int> *lookupMap = new std::unordered_map<int,int>();
    //for each number 
    for (i =0; i< nums.size(); i++){
        //find its compliment     
        int compliment = target - nums[i];
        //search map of this compliment
        auto it = lookupMap->find(compliment);
        // if complement >0 and found num in map
        if (compliment > 0 && it != lookupMap->end() ){
            //create vector with two member, number and it compliment
            v = {nums[i], compliment};
            delete lookupMap;
            return v;
        }else {
            //
            lookupMap->insert({nums[i],i});
        }
    }
    v = {0,0};
    delete lookupMap; 
    return  v;      
}
//check if all chaaracter in string is unique
bool isUnique(const string &str)
{
    //
    int str_size = str.size();
    for (int i = 0; i <str_size; i++){
        for (int j=i+1; j < str_size; j ++){
            if (str[j] == *(str.end())) break;
            if (str[i] == str[j]) return false;
        }
    }
    return true;
}

int extractUniqueChar(string s){
    // get the string length
    int str_len = s.size();
    cout<<"len "<<str_len<<endl;;
    string::iterator it = s.begin();

    // new char vector, and int vector
    vector<char> ch(str_len);
    vector<int>  num(str_len, 0);
    int i,j,k;
    bool dup;
    // start from first char, save into char vector, +1 in int vect
    for( i =0; i < str_len && it!= s.end() ; i++){
        ch[i] = *it;
        num[i] ++;
        // start from next char, until end str, if there is duplicate
        // num[i]++ find number of duplicate
        // this is to forward check if there is dup 
        for (j = distance(s.begin(), it)+1; j < str_len; j++){
            if (ch[i] == s.at(j)){
                num[i] ++;
            }
        }
        it ++;
        // check backward if there is dup
        // if there is dup, skip it
        while (it != s.end()){
            for(k =0; k<=i; k++){
                if (ch[k]==*it) {
                    dup = true;
                }
            }
            if (dup) {
            	it++;
            	dup = false;
            }else {
            	break;
            }
        }
    }
    // char[] vect will have only unique char
    // num[]has number of dup for that char
    for (i=0; i<str_len;i++){
        if(num[i] !=0){
            for (j =0; j<num[i]; j++){
                cout<<ch[i];
            }
            cout<<" "<<num[i];
            cout<<endl;
        }
    }
    //form a str from char vector
    std::string str(ch.begin(), ch.end());
    cout<< "ch str "<<str<<endl;

    return 0;
    
}
// remove a value from a array inplace, return new length
int rmElement(int array[], int n, int num)
{
    int i;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (num == array[i]) {
            continue;
        }
        array[j] = array[i];
        j ++; 
    }
    return j;
}
//remove duplicate element of a array
int rmDuplicate(int array[], int n)
{
    int i;
    int j = 0;
    for (i = 1; i < n; i ++) {
        if (array[j] != array[i]){
            array[++j] = array[i];
        } 
    }
    return j +1;
}


int main() {
    
    // add two students to a linklist
    
    LinkList<student>* class18 = new LinkList<student>();
    
    student* s1 = new student();
    student* s2 = new student();
    student* s3 = new student();
    s1->name = "Tom Cruze";
    s1->age = 19;
    s2->name = "Mary Cruze";
    s2->age = 18;
    s3->name = "kevin Durrant";
    s3->age = 17;
    class18->push_front(s1);
    class18->add_tail(s2);
    class18->display();
    class18->add_tail(s3);
    class18->display();
    class18->reverseList();
    class18->display();
    class18->delete_list();
    class18->display();
    
    delete s1;
    delete s2;
    delete s3;
    delete class18;
    cout<<endl;
    // queue test
    Queue<student>* class19 = new Queue<student>();
    
    s1 = new student();
    s2 = new student();
    s3 = new student();
    student* s;
    s1->name = "Tom Cruze";
    s1->age = 19;
    s2->name = "Mary Cruze";
    s2->age = 18;
    s3->name = "kevin Durrant";
    s3->age = 17;
    class19->enqueue(s1);
    class19->enqueue(s2);
    class19->enqueue(s3);
    class19->display();
    s = class19->dequeue();
    cout << "dequeue  ";
    s->display();
    class19->display();
    s = class19->dequeue();
    cout << "dequeue  ";
    s->display();
    class19->display();
    s = class19->dequeue();
    cout << "dequeue  ";
    s->display();
    class19->display();
    delete s1;
    delete s2;
    delete s3;
    delete class19;
    cout<<endl;
    //stack inherit queue
    Stack<student>* class20 = new Stack<student>();
    s1 = new student();
    s2 = new student();
    s3 = new student();
    s1->name = "Tom Cruze";
    s1->age = 19;
    s2->name = "Mary Cruze";
    s2->age = 18;
    s3->name = "kevin Durrant";
    s3->age = 17;
    class20->push(s1);
    class20->push(s2);
    class20->push(s3);
    class20->display();
    cout << "pop  ";
    s = class20->pop();
    s->display();
    cout << "pop  ";
    s = class20->pop();
    s->display();
    cout << "pop  ";
    s = class20->pop();
    s->display();
    class20->display();
    delete s1;
    delete s2;
    delete s3;
    delete class20;

    // binary tree
    Tree<student>* class21 = new Tree<student>();
    s1 = new student();
    s2 = new student();
    s3 = new student();
    student* s4 = new student();
    student* s5 = new student();
    s1->name = "Tom Cruze";
    s1->age = 18;
    s2->name = "Mary Cruze";
    s2->age = 19;
    s3->name = "kevin Durrant";
    s3->age = 17;
    s4->name = "stephen Cury";
    s4->age = 16;
    s5->name = "dremon green";
    s5->age = 20;
    class21->addNode(s1);
    class21->addNode(s2);
    class21->addNode(s3);
    class21->addNode(s4);
    class21->addNode(s5);
    class21->display(class21->root);
    cout<<"number of students = "<<class21->nodeCount(class21->root)<<endl;
    cout<<"find node ";
    class21->searchNode(class21->root, s5);
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete class21;
    // hash table 
    cout<<endl;
    HashTable<student>* class22 = new HashTable<student>();
    s1 = new student();
    s1->name = "Tom Cruze";
    s1->age = 18;
    s2 = new student();
    s2->name = "Mary Cruze";
    s2->age = 19;
    s3 = new student();
    s3->name = "kevin Durrant";
    s3->age = 17;
    s4 = new student();
    s4->name = "stephen Cury";
    s4->age = 18;
    class22->addEntry(s1);
    class22->addEntry(s2);
    class22->addEntry(s3);
    class22->addEntry(s4);
    class22->display();
    class22->search(s4);
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete class22;

    // twosum one-pass hash lkup solution
    vector<int> vec;
    vector<int> testVector;
    solution sol;
    testVector ={8,7,6,5,4,3,2,1};
    int array[] = {1,2,2,3,4};
    cout<<"new array size " << rmDuplicate(array, sizeof(array)/sizeof(array[0]))<< endl;
    vec = sol.twoSum(testVector, 9);
    cout<<"sum of {" <<vec[0]<<","<<vec[1]<<"}"<<endl;

    //check if string is unique
    string str = "banana ";
    cout<< str<<"is "<<(isUnique(str)?"unique":"not unique")<<endl;

    //check if bigEndian
    if (sol.isBigEndian()){
        cout<<"this is big endian architecture"<<endl; 
    }else {
        cout<<"this is small endian architecture"<<endl;
    }
    // find odd occurance number in a array
    vec={12,12,90,14,14,14,14};
    cout<<"odd number is "<<sol.findOdd(vec)<<endl;
    // swap two number without using temprary
    int a = 10;
    int b = 30;
    cout<<"swap "<<a<<" and "<<b;
    sol.swap(a, b);
    cout<< "  = "<<a<<" "<<b<<endl;  
    // reverse string
    char *word = new (char);
    snprintf(word, 6, "hello");
    sol.reverseStr(word);
    cout<<word<<endl;
    //itoa
    int n = -77;
    char str1[5];
    sol.itoa(n, str1, 16);
    cout<<str1<<endl;
}
