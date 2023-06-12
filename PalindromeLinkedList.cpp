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
LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* nex = NULL; 
    while(head != NULL){
        nex = head->next; 
        head->next = prev; 
        prev = head; 
        head = nex;
    }
    return prev; 
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL) return 1; 
    LinkedListNode<int>* slow = head, * fast = head; 
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next, fast = fast->next->next; 
    }
    slow->next = reverse(slow->next); 
    slow = slow->next; 
    LinkedListNode<int>* temp = head; 
    while(slow != NULL){
        if(slow->data != temp->data) return 0;
        slow = slow->next; 
        temp = temp->next; 
    }
    return 1; 
}
