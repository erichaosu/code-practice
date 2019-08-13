//============================================================================
// Name        : practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <memory>
#include <iomanip>
#include <float.h>
#include <algorithm>
#include "../include/practice.h"
using namespace std;

singleton* singleton::instance = NULL;
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
//check a number in a array that only odd occurrence
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
//check if all character in string is unique
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
//remove duplicate element of a array without memory allocation
// return number of items in the array.
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

int sqr(int k)
{
return k*k;
}

//nth fibnacci
// solution 1
int getNthFib(int n) {
  // Write your code here.
	if (n == 1){
		return 0;
	}
	else if (n == 2){
		return 1;
	}
	else {
		return getNthFib(n-1)+ getNthFib(n-2);
	}
}
// solution 2
int getNthFib2(int n, std::unordered_map<int,int> cache)
{    
    if (cache.find(n) != cache.end()){
        return cache[n];
    }else {
        cache[n] = getNthFib2(n-1, cache) + getNthFib2(n-2,cache);
    }
    return cache[n];
	
}
// solution 3
int getNthFib3(int n, std::vector<int> lasttwo)
{
    if(n == 1) return lasttwo[0];
    if (n ==2) return lasttwo[1];
    for(int i = 3; i <= n; i++){
        int nextfib = lasttwo[0]+lasttwo[1];
        lasttwo[0] =lasttwo[1];
        lasttwo[1] =nextfib;
    }
    return lasttwo[1];
}

struct params{
        int h;
        int w;
        int aRiverSize[1];
};
void printvector(vector<int>& vec)
{
    cout<<"{ ";
    for (auto it = vec.begin(); it !=vec.end(); it++){
        cout<<*it<<",";
    }
    cout<<" }"<<endl;
}
void getARiversize(vector<vector<int>> matrix, 
                   vector<vector<bool>>& visitedNode,
                   int i,
                   int j, 
                   params& aRiver)
{
    //riversize should be at least +1, mark this node as visited
    aRiver.aRiverSize[0] ++;
    visitedNode[i][j] = true;
    //check upper node
    if (((i-1) >= 0) && !visitedNode[i-1][j] 
         && matrix[i-1][j]){    
        //keep going until to end
        getARiversize(matrix, visitedNode, i-1, j, aRiver);
    }
    //check left node
    if (((j-1) >= 0) && !visitedNode[i][j-1] 
        && matrix[i][j-1]){
        //keep going until to end
        getARiversize(matrix, visitedNode,i,j-1, aRiver);
    }
    //check right node
   if (((j+1) < aRiver.w) && !visitedNode[i][j+1] 
        && matrix[i][j+1]){
        //keep going until to end
        getARiversize(matrix, visitedNode,i,j+1, aRiver);
    }
    //check below node
    if (((i+1) < aRiver.h) && !visitedNode[i+1][j] 
         && matrix[i+1][j]){
        //keep going until to end
        getARiversize(matrix, visitedNode,i+1,j, aRiver);
    }
}
void printVisitedNode(int h,int w, vector<vector<bool>>& visitedNode)
{
    for (int i=0; i<h; i++){
        for(int j=0;j<w;j++){
            cout<<visitedNode[i][j]<<",";
        }
        cout<<endl;
    }
}

vector<int> riverSizes(vector<vector<int>> matrix)
{   
   
    vector<int> allRiverSize;
    params aRiver;
    
    
    //get matrix width and height
    int h = matrix.size();
    int w = matrix[0].size();
    vector<vector<bool>> visitedNode(h, vector<bool>(w, false));
    cout<<"height ="<<h<<" width ="<<w<<endl;
    aRiver.h = h;
    aRiver.w = w;
    for (int i=0; i<h; i++){
        for(int j=0;j<w;j++){
            if ((matrix[i][j] == 1) && (!visitedNode[i][j])){      
                aRiver.aRiverSize[0] =0;
                getARiversize(matrix, visitedNode, i,j,aRiver);
                cout<< "this river = "<<aRiver.aRiverSize[0]<<endl;
                printVisitedNode(h,w,visitedNode);
                allRiverSize.push_back(aRiver.aRiverSize[0]);
            }
            else {
                visitedNode[i][j] = true;
                continue;
            }
        }
    }
    return allRiverSize;
}
int partition(vector<int>& array, int left, int right)
{
    int i,j, tmp;
    int midline = left +(right - left)/2;
    i = left;
    j = right;
    while (i <= j){
        while (array[i] < array[midline]){
            i++;
        }
        while ( array[j] > array[midline])
        {
            j--;
        }
        if (i <= j) {
            tmp = array[i];
            array[i]=array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
}

void quicksort(vector<int>& array, int left, int right)
{

    if (left < right){
        int midindex = partition(array, left, right);
        quicksort(array, left , midindex-1);
        quicksort(array, midindex, right);
    }
}


//twosum using O(nlogn)time|O(1) space

vector<int> twosum(vector<int>& array, int target)
{
    vector<int> result;
    //sort array using quick sort
    quicksort(array, 0, array.size()-1);
    int left, right;
    left = 0;
    right = array.size() -1 ;
    while ((left != array.size() -1) && ( right != 0)){
        if ((array[left] + array[right]) < target){
            left ++;
        }
        else if ((array[left] + array[right]) > target){
            right --;
        }
        else {
            result.push_back(array[left]);
            result.push_back(array[right]);
            return result;
        }
    }
    return {};
}
template <class T>
class btree
{
    public:
    struct node{
        T data;
        node* left;
        node* right;
        node(T d, node* y = 0, node* z = 0):data(d), left(y),right(z){}
    };
    node* root;
    btree(){}
    ~btree(){}
    void insert(node* tree, T data);
    void display(node* tree, int space);
};
template<class T>
void btree<T>::insert(node* tree, T val)
{
    node* newnode = new node(val, NULL, NULL);
    node* newnode_parent;
    if (tree == NULL) {
        this->root = newnode;
        return;
    }
    // use iteration to insert the data
    node* current = tree;
    while (current != NULL){
        newnode_parent = current;
        if (val < current->data){
            current = current->left;
        }
        else if (val > current->data){
            current = current->right;
        }
    }
    if (val < newnode_parent-> data){
        newnode_parent->left = newnode;
    }else {
        newnode_parent->right = newnode;
    }
}
template <class T>
void btree<T>::display(node* tree, int space)
{
    if (tree == NULL) return;
    space += 5;
    display(tree->right, space);
    // print data
    cout<<endl;
    cout<<std::setfill(' ')<<std::setw(space);
    cout<<tree->data;
    
    display(tree->left, space);
}

//find closest value in BST
#include <float.h>
#include <cmath>

class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};
int findClosestValueInBstHelper(BST* tree, int target, float closestValue);

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
	return findClosestValueInBstHelper(tree, target, DBL_MAX);
}

int findClosestValueInBstHelper(BST* tree, int target, float closestValue)
{
	int currentValue = tree->value;
	if (abs(target - currentValue) < abs(target - closestValue)){
		closestValue = currentValue;
	}
	while ((tree != NULL) && (closestValue != target)){
		if(currentValue < target){
			findClosestValueInBstHelper(tree->right, target, closestValue);
		}
		else if (currentValue > target){
			findClosestValueInBstHelper(tree->left, target, closestValue);
		}
	}
	return closestValue;
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	unordered_map<int, int> cache;
	vector<int> result;
	int len = array.size();
	for (int num : array){
		int reminder = abs(targetSum - num);
		if(cache.find(reminder) != cache.end()){
			result.push_back (num);
			result.push_back(reminder);
			return result;
		}else {
			cache.insert({num, 1});
		}
	}
	return {};
}

class Node {
  public:
    string name;
    vector<Node*> children;

    Node(string str) {
      name = str;
    }

    vector<string> depthFirstSearch(vector<string>* array) {
      // Write your code here.
			array->push_back(this->name);
			for(int i = 0; i<this->children.size(); i++ ){
				children[i]->depthFirstSearch(array);
			}
			return *array;
    }

    Node* addChild(string name) {
      Node* child = new Node(name);
      children.push_back(child);
      return this;
    }
};

// algoexpert findthreelargest num

void outputShift(int position, vector<int>& output, int num);
void updateLargest(vector<int>& output, int num);

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
	vector<int> output = {INT32_MIN, INT32_MIN, INT32_MIN};
	for (int i = 0; i<array.size(); i++){
		updateLargest(output, array[i]);
	}
	return output;
}

void updateLargest(vector<int>& output, int num)
{	
	if (num > output[2]){
		outputShift(2, output, num);
	}
	else if (num > output[1]){
		outputShift(1, output, num);
	}
	else if (num > output[0]){
		outputShift(0, output, num);
	}
}

void outputShift(int position, vector<int>& output, int num)
{
	if(position == 0){
		output[0] = num;
	}
	else if (position == 1){
		output[0] = output[1];
		output[1] = num;
	}
	else if (position == 2){
		output[0] = output[1];
		output[1] = output[2];
		output[2] = num;
	}

}

class Node1 {
  public:
    int value;
    Node1* prev;
    Node1* next;

    Node1(int value);
};

Node1::Node1(int value) {
  this->value = value;
  prev = NULL;
  next = NULL;
};
// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
  public:
    Node1* head;
    Node1* tail;

    DoublyLinkedList() {
      head = NULL;
      tail = NULL;
    }

	  void insertBefore(Node1* node, Node1* nodeToInsert) {
      // Write your code here.
			//remove(nodeToInsert);
			if (node == head){
				nodeToInsert->next = head;
				head->prev = nodeToInsert;
				head = nodeToInsert;
			}
			else if (node == tail){
				tail->prev->next = nodeToInsert;
				nodeToInsert->prev = tail->prev;
			}
			else {
				node->prev->next = nodeToInsert;
				nodeToInsert->prev = node->prev;
				nodeToInsert->next = node;
				node->prev = nodeToInsert;
			}
    }

    void setHead(Node1* node) {
      // Write your code here.
			if(head == NULL){
				head = node;
				tail = node;
				return;
			}
			insertBefore(head,node);
			
    }

    void setTail(Node1* node) {
      // Write your code here.
			if (tail == NULL){
				setHead(node);
				return;
			}
			insertAfter(tail,node);
    }


    void insertAfter(Node1* node, Node1* nodeToInsert) {
      // Write your code here.
			if ((nodeToInsert == head) && (nodeToInsert == tail)) return;
			remove(nodeToInsert);
			nodeToInsert->prev = node;
			nodeToInsert->next = node->next;
			if (node  == tail){
				tail = nodeToInsert;
			}else {
				node->next->prev = nodeToInsert;
			}
			node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node1* nodeToInsert) {
      // Write your code here.
			if (position == 1) {
				setHead(nodeToInsert);
			}
			int currentPosition = 1;
			Node1* node = head;
			while ((node != NULL) && (currentPosition != position)){
				node = node->next;
				currentPosition++;
			}
			if (node == NULL){
				setTail(node);
			}
			else {
				insertBefore(node, nodeToInsert);
			}
			
    }

    void removeNodesWithValue(int value) {
      // Write your code here.
			Node1* node = head;
			while ((node != NULL) && (node->value != value)){
				node = node->next;
			}
			if (node != NULL){
				remove(node);
			}
			
    }

    void remove(Node1* node) {
      // Write your code here.
			if (node == head) {
				head = head->next;
			}
			else if (node == tail) {
				tail = tail->prev;
			}
			if (node->prev != NULL) node->prev->next = node->next;
			if (node->next != NULL) node->next->prev = node->prev;
			node->prev = NULL;
			node->next = NULL;
    }

    bool containsNodeWithValue(int value) {
      // Write your code here.
			Node1* node = head;
			while (node != NULL){
				if (node->value == value) return true;
				node = node->next;
			}
			return false;
    }

};
// binary search
int helper(vector<int> array, int start, int end,int target);
int binarySearch(vector<int> array, int target) {
  // Write your code here.
	// recursive time = O(logn) space = O(1)
	return helper(array, 0, array.size()-1, target);
}

int helper(vector<int> array, int start, int end,int target)
{
	int mid = (start+end)/2;
	if (array[mid] == target) return mid;
	else if (array[mid] < target){
		return helper(array, mid+1, end, target);
	}else {
		return helper(array, 0, mid-1, target);
	}
}

// bubble sort time = O(n^2), space = O(1)
vector<int> bubbleSort(vector<int>& array) {
  // Write your code here.
    bool inorder = false;
	 while(!inorder){
        inorder = true;
	    for (int i=0; i<array.size()-1; i++){
	    	if (array[i] > array[i+1]){
	    		int temp = array[i];
	    		array[i] = array[i+1];
	    		array[i+1] = temp;
	    	    inorder = false;	
	    	}	
	    }
    }
    return array;
}

// selection sort time O(n^2)| space O (1)
void swap(int i, int j, vector<int>& array)
{
	int temp = array [i];
	array[i] = array[j];
	array[j] = temp;
}

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
	if (array.empty()){
		return {};
	}
	int currentidx =0;
	while(currentidx < array.size()-1){
		int smallestidx = currentidx;
		for(int i = currentidx +1; i < array.size(); i++ ){
			if(array[i] < array[smallestidx]){
				smallestidx = i;
			}
		}
		swap(currentidx, smallestidx, array);
		currentidx ++;
	}
	return array;
}
//insertion sort time O(n^2)|space O(1)
vector<int> insertionSort(vector<int> array) {
  // Write your code here.
	for (int i = 1; i < array.size(); i ++){
		int j = i;
		while(j > 0 && (array[j] < array[j-1])){
				swap(j, j-1, array);
				j --;
		}
	}
	return array;
}
#if 0
bool isPalindrome(string str) {
  // Write your code here.
	vector<char> reversestr = {};
	for (int i = str.length()-1; i>=0; i--){
		reversestr.push_back(str[i]);
	}
	return str == string(reversestr.begin(), reversestr.end());
}
// O(n) time | O(n) space
bool helper(int start, int end, string& str)
{
	if (start >= end) return true;
	else if (str[start] != str[end]){
		return false;
	}
	else {
		return helper(start+1, end-1, str);
	}
}

bool isPalindrome(string str) 
{
	int first = 0;
	int last = str.length()-1;
	return helper(first, last, str);
}
#endif
// O(n) time| O(1) space
bool isPalindrome(string str) 
{
	int first = 0;
	int last = str.length()-1;
	while (first < last){
		if (str[first] != str[last]){
			return false;
		}
		first ++;
		last --;
	}
	return true;
}	

// important unicode number
// 0-9 48-57
//A-Z  65 - 90
//a-z  97-122
char getnewletter(char letter, int key)
{
	int newletterunicode = letter + key;
	if (newletterunicode <= 'z'){
		return newletterunicode;
	}
	else {
		return ('a'-1) + newletterunicode % 'z';
	}
}

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
	int newkey = key % 26;
	vector<char> newstr={};
	for (int i =0; i < str.length(); i++){
		newstr.push_back(getnewletter(str[i], newkey));
	}
	return string(newstr.begin(), newstr.end());	
}

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	//create result triplet array
	vector<vector<int>> triplet = {};
	//sort array to ascending order
	sort(array.begin(), array.end());
	for (int i =0; i < array.size()-2; i++){
		int left = i+1;
		int right = array.size()-1;
		// left cross right means all array has been checked. 
		while (left < right){
			int threesum = array[i] + array[left] + array[right];
			if (threesum == targetSum){
				triplet.push_back({array[i],array[left],array[right]});
				left ++;
				right --;
			}
			else if (threesum < targetSum){
				left ++;
			}
			else {
				right --;
			}
		}
	}
	return triplet;
}
//foursum
//time O(n^2) | space O(n^2)

vector<vector<int>> foursum(vector<int> array, int target)
{
    //return value
    vector<vector<int>> quadruplets {};
    //a unordered-map
    unordered_map<int, vector<vector<int>>> allpairsum;
    for(int i = 1; i<array.size() -1; i ++){
        for(int j = i+1; j<array.size(); j++){
            int bigP = array[i] + array[j];
            int diff = target - bigP;
            if (allpairsum.find(diff) != allpairsum.end()){
                // found the complement in unordered_map
                // push array[i], array[j], and allpair into return vector
                for(vector<int>pair: allpairsum[diff]){
                    pair.push_back(array[i]);
                    pair.push_back(array[j]);
                    quadruplets.push_back(pair);
                }
            }
        }
        // insert pair of array item + array first item
        for(int k = 0; k < i ; k++){
            //add this is after 
            int currentsum = array[i] + array[k];
            //if not find this sum
            if (allpairsum.find(currentsum) == allpairsum.end()){
                // not find this key in allpairsum map, add the key and value
                allpairsum[currentsum] = vector<vector<int>> {{array[k], array[i]}};
            }
            else {
                //the key/value already in allpairsum map, add to the vector back
                allpairsum[currentsum].push_back (vector<int> {array[k], array[i]});
            }
        }
    }
    return quadruplets;
}

//deepest first search og graph
//array remove element
int removeelement(int array[], int length, int element)
{
    int j = 0;
    for (int i =0; i <length; i++){
        if (array[i] == element){
            continue;
        }
        array[j] = array[i];
        j++;
    }
    return j;
}
// remove duplicate array member
int remdup(int array[], int length)
{
    int i = 0;
    int j = 0;
    int k = 0;
    bool duplicate = false;
    for (i = 0; i < length; i++){
        //find if array[i] has duplicate in array
        for (j = 0; j < length; j ++){
            if ((array[j] == array[i]) && ( i != j )){
                duplicate = true;
                break;
            }
        } 
        if (duplicate) {
            duplicate = false;
            continue;
        }
        array[k] = array[i];
        k ++;
    }
    return k;
}

int main() {

//foursum
vector<int> sumarray = {7,8,5,6,-1,2,6};
vector<vector<int>> quadruplet {};
quadruplet = foursum(sumarray, 13);
for (vector<int> result: quadruplet){
    cout<<"{";
    for(int i: result){
        cout<<i<<",";
    }
    cout<<"},";
}
cout<<endl;

//bubble sort
vector<int> bubblearray = {8,5,2,9,5,6,3};
bubbleSort(bubblearray);
for(int num:bubblearray){
    cout<<num<<",";
}
cout<<endl;
// binary search

cout<<binarySearch({1, 5, 23, 111}, 111)<<endl;

//linklist construct
DoublyLinkedList linkedList;
Node1 node1(1);

linkedList.setHead(&node1);
linkedList.remove(&node1);
//find threelargestnumber
vector<int> input = {141,1,17,-7,-17,-27,18,541,8,7,7};
vector<int> output;
output = findThreeLargestNumbers(input);
for (int num:output){
    cout<<num<<"   ";
}
cout<<endl;

int array1[] = {1,2,2,3,2,4};
cout<<"array size after remove "
    <<removeelement(array1,sizeof(array1)/sizeof(array1[0]), 2)
    <<endl;
cout<<"length of array after removeduplicate "
    <<remdup(array1, sizeof(array1)/sizeof(array1[0]))
    <<endl;

Node* node = new Node("a");
node->addChild("b");
node->addChild("c");
node->addChild("d");

node->children[0]->addChild("e");
cout<<node->name;
cout<<node->children[0]->name;
cout<<node->children[1]->name;
cout<<node->children[2]->name;
cout<<node->children[0]->children[0]->name<<endl;
vector<string> nodestr {};
node->depthFirstSearch(&nodestr);
for(string str:nodestr){
    cout<<str<<"    ";
}
cout<<endl;

#if 0    
    vector<vector<int>> matrix = {{1,0,0,1,0},
                                  {1,0,1,0,0},
                                  {0,0,1,0,1},
                                  {1,0,1,0,1},
                                  {1,0,1,1,0}};
#endif
    vector<vector<int>> matrix = {
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 0, 1, 1, 1, 1, 0, 1},
      {0, 1, 1, 0, 0, 0, 1, 1},
    };
    vector<int> river;
    river = riverSizes(matrix);
    printvector(river);
    //std::unordered_map<int,int> cache({
    //                                  {1,0},
    //                                 {2,1}
    //                                   });
    std::vector<int> lasttwo = {0,1};
    cout<<"(";
    for (int i =1; i <= 6; i++){
        cout<<getNthFib3(i,lasttwo)<<",";
    }
    cout<<")"<<endl;
    // quick sort
    vector<int> vec1 = {3,2,6,5,4,7};
    quicksort(vec1, 0, vec1.size()-1);
    printvector(vec1);
    vector<int> result;
    //result = twosum(vec1, 12);
    result = twoNumberSum(vec1, 12);
    cout<<"{"<<result[0]<<","<<result[1]<<"}"<<endl;

    vector<int> bt = {10,5,15,2,5,13,22,1,14};
    btree<int>* btr = new btree<int>();
    for (int i =0; i < bt.size(); i++){
        int j = bt[i];
        btr->insert(btr->root, j);
    }
    btr->display(btr->root, 0);
    cout<<endl;
    if (10 <DBL_MAX) cout<< "10 < DLB_MAX"<<endl;
    return 0;
    //two sum
    // add two students to a linklist
    
    unique_ptr<LinkList<student>> class18 (new LinkList<student>());
    
    student* s1 = new student();
    student* s2 = new student();
    student* s3 = new student();
    LinkList<student>::Node* found_node;
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
    //found_node = class18->find_nth_node_from_tail(3);
    found_node->data->display();
    class18->reverseList();
    class18->display();
    class18->delete_list();
    class18->display();
    
    delete s1;
    delete s2;
    delete s3;
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
    vector<Tree<student>::Node*> parents;
    vector<Tree<student>::Node*>::iterator it;
    //class21->findAncestors(s5, parents);
    for (auto& it:parents) {
        it->data->display();
    }
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
    // find odd occurrence number in a array
    vec={12,12,90,14,14,14,14};
    cout<<"odd number is "<<sol.findOdd(vec)<<endl;
    // swap two number without using temporary
    int a = 10;
    int b = 30;
    cout<<"swap "<<a<<" and "<<b;
    sol.swap(a, b);
    cout<< "  = "<<a<<" "<<b<<endl;  
    // reverse string
    //char *word = new (char);
    //snprintf(word, 6, "hello");
    char word[]="hello";
    sol.reverseStr(word);
    cout<<word<<endl;
    //itoa
    int n = -77;
    char str1[5];
    sol.itoa(n, str1, 16);
    cout<<str1<<endl;
    cout<<"end!"<<endl;
    const int SIZE1 =10;

    int new_array[sqr(SIZE1)*3];
    cout<<sizeof(new_array)<<endl;
    singleton* sin;
    singleton* sin1;
    singleton* sin2;

    cout<<hex<<(uintptr_t)sin->getInstance()<<endl;
    cout<<hex<<(uintptr_t)sin1->getInstance()<<endl;
    cout<<hex<<(uintptr_t)sin2->getInstance()<<endl;
    
    unsigned int a1;
    a1 = 7;
    write_only_port port(&a1);
    cout<<"a = "<<a1<<endl;
    port &= 0x5;
    cout<<"a = "<<a1<<endl;
    exit(0);
}
