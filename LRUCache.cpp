#include<unordered_map>
class Node{
public:     
    int key, data;
    Node* next, * prev; 
    Node(){
        data = 0, next = prev = NULL;
    }
    Node(int k, int value){
        data = value, key = k, next = prev = NULL;
    }
};
class LRUCache
{
public:
    unordered_map<int, Node*>mpp;
    Node* head = new Node(), * tail = new Node();
    int n, cnt;
    LRUCache(int capacity)
    {
        // Write your code here
        n = capacity, cnt = 0; 
        head->next = tail; 
        tail->prev = head; 
    }
    void add(Node* node){
        mpp[node->key] = node; 
        Node* temp = head->next; 
        head->next = node; 
        temp->prev = node; 
        node->prev = head; 
        node->next = temp; 
    }
    void remove(Node* node){
        mpp.erase(node->key); 
        Node* prevNode = node->prev;
        Node* nextNode = node->next; 
        prevNode->next = nextNode; 
        nextNode->prev = prevNode; 
        delete(node); 
    }
    int get(int k)
    {
        if(mpp.find(k) == mpp.end()) return -1; 
        Node* temp = mpp[k]; 
        int val = temp->data; 
        remove(temp); 
        Node* node = new Node(k, val); 
        add(node); 
        return val;
    }
    void put(int k, int value)
    {
        // Write your code here
        Node* node = new Node(k, value); 
        if(mpp.find(k) != mpp.end()){
            Node* temp = mpp[k]; 
            remove(temp);
        }else{
            if(cnt == n){
                Node* temp = tail->prev; 
                remove(temp); 
            }else{
                cnt++; 
            }
        }
        add(node); 
    }
};
