#include <iostream>
using namespace std;

struct Node{

	int data;
	Node* next;
		
	Node(int value){
		data = value;
		next = NULL;
	}
};

class LinkedList{
	public:
		Node* head;
		LinkedList(){
			head = NULL;
		}
		insertTop(Node* i){
			head = i;
		}
		insertEnd(Node* i){
			if(head == NULL){
				head = i;
			}
			else{
				Node* curr = head;
				while(curr != NULL){
					curr = curr -> next;
				}
				curr->next = i;
				cout<<" Value is inserted at End of the linked list!"<<endl;
			}
		}
		displayList(){
			if(head == NULL){
				cout<<" No value to display !"<<endl;
				
			}
			else{
				Node* curr = head;
				while(curr != NULL){
					cout<<curr->data;
					curr = curr->next;
				}
			}
		}
		
		deleteHead(){
			if(head == NULL){
				cout<<" List is empty!!"<<endl;
				
			}
			else{
				Node* curr = head;
				head = head->next;
				delete curr;
				cout<< "Node has been deleted!! "<<endl;
			}
		}
		deleteTail(){
			if(head == NULL){
				cout<<" list is empty..."<<endl;	
			}
			else{
				Node* curr = head;
				Node* prev;
				while(curr->next != NULL){
					prev = curr;
					curr = curr->next;
				}
				prev->next = NULL;
				delete curr;
			}
		}
		search(int value){
			Node* curr = head;
			while ( curr != NULL){
				if(curr->data == value){
					cout<<" Value found!... "<<curr->data<<endl;
					curr = curr->next;
				}
			}
		}
};

int main(){
	LinkedList* list = new LinkedList();
	Node* n1 = new Node(12);
	list ->insertTop(n1);	list->search(12);
	list ->displayList();
	list->deleteHead();
	list ->displayList();
	return 0;
}




