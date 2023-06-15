/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* Merge(Node* l1, Node* l2){
	Node* temp = new Node(0);
	Node* res = temp; 
	while(l1 != NULL && l2 != NULL){
		if(l1->data < l2->data){
			temp->child = l1;
			temp = temp->child;
			l1 = l1->child; 
		}else{
			temp->child = l2; 
			temp = temp->child; 
			l2 = l2->child;
		}
		// temp->next = NULL; 
	}
	if(l2 != NULL) temp->child = l2; 
	else temp->child = l1;
	return res->child; 
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head->next == NULL) return head; 
	Node* root = head->next; 
	head->next = NULL;
	root = flattenLinkedList(root); 
	head = Merge(head, root);
	return head; 
}
