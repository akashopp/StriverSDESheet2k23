#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    LinkedListNode<int>* temp = node, *prev; 
    while(temp->next != NULL){
        prev = temp; 
        temp = temp->next;
        prev->data = temp->data;
    }
    prev->next = NULL; 
}
