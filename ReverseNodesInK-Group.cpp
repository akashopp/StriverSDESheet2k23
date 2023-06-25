#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(!head) return head;
	Node* dummy = new Node(0);
	dummy->next = head; 
	Node *pre = dummy, *nex = dummy, *cur = dummy;
	int count = 0;
	while(cur->next != NULL) count++, cur = cur->next;
	for(int i = 0; i < n; i++){
		if(pre == NULL || pre->next == NULL) break;
		if(b[i] == 0) continue;
		cur = pre->next;
		nex = cur->next; 
		for(int j = 1; j < b[i] && cur != NULL && cur->next != NULL; j++){
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			nex = cur->next;
		}
		pre = cur;
	}
	return dummy->next;
}
