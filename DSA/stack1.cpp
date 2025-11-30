#include <iostream>
using namespace std;

#define MAX 10

int stackArr[MAX];
int top = -1;

void push();
void pop();
void peek();
void display();
void isEmpty();
void isFull();
void traverse();

int main() {
    int choice;

    while (true) {
        cout << "\n STACK MENU \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Traverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
			push();
			 break;
            case 2:
			 pop();
			  break;
            case 3:
			 peek();
			  break;
            case 4: 
			display(); 
			break;
            case 5: 
			isEmpty();
			 break;
            case 6: 
			isFull();
			 break;
            case 7: 
            traverse();
            break;
            case 8:
			break;

            default: cout << "Invalid choice!\n";
        }
    }
}

void push() {
    int value;
    if (top == MAX - 1) {
        cout << "Stack Overflow! (Full)\n";
    } else {
        cout << "Enter value to push: ";
        cin >> value;
        stackArr[++top] = value;
        cout << "Pushed " << value << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! (Empty)\n";
    } else {
        cout << "Popped " << stackArr[top--] << endl;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        cout << "Top element: " << stackArr[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Stack is Not Empty\n";
}

void isFull() {
    if (top == MAX - 1)
        cout << "Stack is Full\n";
    else
        cout << "Stack is Not Full\n";
}
void traverse(){
	if (top==-1 ){
		cout<< "Stack is empty.\n";
	}else{
		cout<< "Traversing:\n";
		for(int i=top;i>=0;i--){
			cout<< stackArr[i]<<" "<<endl;
		}
	}
}
