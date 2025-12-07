#include<iostream>
#define MAX 20
using namespace std;

class InfixtoPostfix{
	private:
		char stackArr[MAX];
		int top;
	public:
		InfixtoPostfix(){
			top=-1;
		}
		
	void push(char c){
		stackArr[++top]=c;
	}
	
	char pop(){
		return stackArr[top--];
	}
	
	char peek(){
		return stackArr[top];
	}
	
	bool isEmpty(){
		return top==-1;
	}
	
	
		bool isOperand(char c){
	return (c>='A' && c<= 'Z')||
			(c >='a' && c<='z')||
			(c >='0' && c<='9');
	}
	
	int precedence(char c){
		if(c=='$') return 3;
		if(c=='*'|| c=='/') return 2;
		if(c=='+'|| c=='-') return 1;
		return -1;
	}
	
	string convert(string infix){
		string postfix="";
		
		for (int i=0 ; i<infix.length(); i++){
			char c= infix[i];
			if(isOperand(c)){
				postfix+=c;
			}
			else if(c=='('){
				push(c);
			}
			else if(c==')'){
				while(!isEmpty() && peek() !='('){
					postfix+=pop();
				}
				pop();
			}
			else{
				while(!isEmpty() && precedence(peek())>= precedence(c)){
					postfix+=pop();
				}
				push(c);
			}
		}
		while(!isEmpty()){
			postfix +=pop();
		}
		return postfix;
	}
};

int main(){
	InfixtoPostfix obj;
	string infix;
	
	cout<<"Enter infix operation:\n";
	cin>>infix;
	
	cout<<"Postfix Expression:"<<obj.convert(infix)<<endl;
	
	return 0;
}
