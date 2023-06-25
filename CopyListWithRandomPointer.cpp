#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*>mpp;
    LinkedListNode<int>* temp = head;
    while(temp){
        mpp[temp] = new LinkedListNode<int>(temp->data); 
        temp = temp->next;
    }
    temp = head;
    while(temp){
        mpp[temp]->next = mpp[temp->next]; 
        mpp[temp]->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}
