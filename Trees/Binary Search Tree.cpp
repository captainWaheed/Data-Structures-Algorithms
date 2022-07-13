#include<iostream>

using namespace std;

struct tree{
	char data;
	tree* parent;
	tree* left;
	tree* right;
};
class BT{
	private:
		tree* root;
		BT(tree* r){
			root=r;
		}
	public:
        BT(){
			root=NULL;
		}
		void InsertRootdata(char data){
			if(root==NULL){
				root=new tree;
				root->parent=NULL;
				root->data=data;
				root->left=NULL;
				root->right=NULL;
			}
			else
			cout<<"Root is already present\n";
		}
		void AddLeftChild(char data){
			tree* t=new tree;
			t->data=data;
			t->left=NULL;
			t->right=NULL;
			t->parent=root;
			root->left=t;
		}
		void AddRightChild(char data){
			tree* t=new tree;
			t->data=data;
			t->left=NULL;
			t->right=NULL;
			t->parent=root;
			root->right=t;
		}
		BT* MakeLeftRoot(){
			return new BT(root->left);
		}
		BT* MakeRightRoot(){
			return new BT(root->right);
		}
		tree* returnroot(){
			return this->root;
		}
		tree* Min(tree* r){
			if(r!=NULL){
				while(r->left!=NULL){
				    r=r->left;
			    }
			    return r;
			}
		}
		tree* Successor(tree* r){
			tree* p;
			if(r->right!=NULL){
				return Min(r->right);
			}
			else{
				p=r->parent;
				while(p!=NULL && p->right==r){
					r=p;
					p=p->parent;
				}
				return p;
			}
		}
		char Delete(tree* d){
			char x=d->data;
			if(d->left==NULL && d->right==NULL){
				d=NULL;
			}
			else{
				tree* p;
				tree* c;
				if(d->left==NULL && d->right!=NULL){
					p=d->parent;
					c=d->right;
					if(d==p->right){
						p->right=c;
					}
					else{
						p->left=c;
					}
					d=NULL;
				}
				else if(d->left!=NULL && d->right==NULL){
					p=d->parent;
					c=d->left;
					if(d==p->right){
						p->right=c;
					}
					else{
						p->left=c;
					}
					d=NULL;
				}
				else if(d->left!=NULL && d->right!=NULL){
					tree* s=Successor(d);
					d->data=s->data;
					if(s->left!=NULL){
						s->data=s->left->data;
						s->left=NULL;
					}
					else{
						tree* p=s->parent;
						if(s==p->left){
							p->left=NULL;
						}
						else{
							p->right=NULL;
						}
					}
				}
			}
			return x;
		}
		void Inorder(){
			Inorder(root);
			cout<<endl;
		}
		void Preorder(){
			Preorder(root);
			cout<<endl;
		}
		void Postorder(){
			Postorder(root);
			cout<<endl;
		}
	private:
		void Inorder(tree* r){
			if(r!=NULL){
				Inorder(r->left);
				cout<<r->data<<" ";
				Inorder(r->right);
			}
		}
		void Preorder(tree* r){
			if(r!=NULL){
				cout<<r->data<<" ";
				Preorder(r->left);
				Preorder(r->right);
			}
		}
		void Postorder(tree* r){
			if(r!=NULL){
				Postorder(r->left);
				Postorder(r->right);
				cout<<r->data<<" ";
			}
		}
		public:
		void Insert(char data){
			Insert(data,root);
		}
		bool Search(char data){
			return Search(data,root);
		}
		private:
		void Insert(char data,tree* r){
			BT* b;
			if(r==NULL){
				InsertRootdata(data);
			}
			else{
			    if(data > root->data){
				    if(root->right==NULL){
					    AddRightChild(data);
				    }
				    else{
					    b=MakeRightRoot();
					    b->Insert(data,b->root);
				    }
			    }
			    else if(data < root->data){
				    if(root->left==NULL){
					    AddLeftChild(data);
				    }
				    else{
					    b=MakeLeftRoot();
					    b->Insert(data,b->root);
				    } 
			    }
		    }
		}
		
		bool Search(char data, tree* r){
			if(r!=NULL){
				if(data == r->data){
					return true;
				}
				else if(data > r->data){
					Search(data,r->right);
				}
				else if(data < r->data){
					Search(data,r->left);
				}
			}
			else{
			    return false;
		    }
		}
		
};
