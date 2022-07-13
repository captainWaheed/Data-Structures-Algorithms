#include <iostream>
using namespace std;

struct Stack{
	private:
		int top;
		int arr[];
	public:
		Stack(){
			top = -1;
			arr[5];
		}
		void push(int val){
			if(top == val -1){
				cout<<" Stack overflow condition..!"<<endl;	
			}
			else{
				top++;
				arr[top] = val;
				cout<<val<<" the value is pushed at index "<<top<<endl;
			}
		}
		void pop(){
			if(top == -1){
				cout<<" Stack underflow condition..!"<<endl;
			}
			else{
				cout<<arr[top]<<" popped"<<endl;
				top--;
				
			}
		}
		int Top(){
			if( top == -1){
				cout<<" Nothing to display..!"<<endl;
				return -1;
			}
			else{
				return arr[top];
			}
		}
		bool empty(){
			return top == -1;
		}
};

int main(){
	Stack stk;
    stk.push(34);
    stk.push(54);
    stk.push(90);
    stk.push(22);
//    stk.pop();
    cout<<" Is empty: "<<stk.empty()<<endl;
    cout<<" The top of stack is: "<<stk.Top()<<endl;
    
}
