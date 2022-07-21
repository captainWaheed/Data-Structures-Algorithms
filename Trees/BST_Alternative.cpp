#include <iostream>
using namespace std;

class node{
	public:
		int key;
		node* leftChild;
		node* rightChild;
		
	node(int val){
		key = val;
		leftChild = NULL;
		rightChild = NULL;
		
	}
	display(){
		cout<<" key is "<< key << endl;
	}
};

class BST{
	public:
		node* root;
		
	BST(){
		root = NULL;
	}
	public:
	insertionBST(node* bstNode){
		if(root == NULL){
			root = bstNode;
			
		}
		else{
			node* curr = root;
			node* parent;
			bool goleft = false;
			while(curr != NULL){
				parent = curr;
				if(bstNode -> key < curr->key){
					curr = curr->leftChild;
					goleft = true;
				}
				else{
					curr = curr->rightChild;
					goleft = false;
				}
			}
			if(goleft){
				parent->leftChild = bstNode;
			}
			else{
				parent -> rightChild = bstNode;
			}
		}
	}
	inorder(node* root){
		if(root != NULL){
			inorder(root -> leftChild);
			cout<< root ->key;
			inorder(root->rightChild);
		}
	}
};
