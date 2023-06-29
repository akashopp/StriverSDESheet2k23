#include <bits/stdc++.h> 
struct Node{
    int key, value, cnt;
    Node *prev, *next;
    Node(int _key, int _value){
        key = _key, value = _value, cnt = 1;
    }
};
struct List{
    int size; 
    Node *head, *tail; 
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0; 
    }
    void addFront(Node *node){
        Node *temp = head->next;
        node->next = temp; 
        node->prev = head; 
        head->next = node;
        temp->prev = node;
        size++; 
    }
    void removeNode(Node *node){
        Node* prevNode = node->prev; 
        Node* nextNode = node->next; 
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--; 
    }
};
class LFUCache
{
    map<int, Node*>mppKey; 
    map<int, List*>mppList; 
    int curSize, maxCapacity, minFreq;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        curSize = minFreq = 0; 
        maxCapacity = capacity; 
    }
    void update(Node* node){
        mppKey.erase(node->key);
        mppList[node->cnt]->removeNode(node);
        if(mppList[node->cnt]->size == 0 && node->cnt == minFreq) minFreq++;
        List *newList = new List(); 
        if(mppList.find(node->cnt + 1) != mppList.end()) newList = mppList[node->cnt + 1]; 
        node->cnt += 1; 
        newList->addFront(node);
        mppList[node->cnt] = newList;
        mppKey[node->key] = node;
    }
    int get(int key)
    {
        // Write your code here.
        if(mppKey.find(key) != mppKey.end()){
            Node *node = mppKey[key]; 
            update(node); 
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(maxCapacity == 0) return;
        if(mppKey.find(key) != mppKey.end()){
            Node* node = mppKey[key];
            node->value = value;
            update(node);
        }else{
            if(curSize == maxCapacity){
                List *newList = mppList[minFreq];
                mppKey.erase(newList->tail->prev->key);
                mppList[minFreq]->removeNode(newList->tail->prev);
                curSize--; 
            }
            curSize++; 
            minFreq = 1; 
            List *newList = new List();
            if(mppList.find(key) != mppList.end()) newList = mppList[key]; 
            Node *node = new Node(key, value);
            newList->addFront(node);
            mppKey[key] = node;
            mppList[minFreq] = newList;
        }
    }
};
