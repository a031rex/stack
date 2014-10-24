#include<iostream>
using namespace std;

class stack{
protected:
	typedef struct node{
		struct node *next;
		int data;
	}node;
	node *head;
public:
	stack();
	~stack();
	void push(int value);
	int pop();
	void print_stack();
};

stack::stack(){
	head=NULL;
	return;
}
stack::~stack(){
	while(head){
		node *ptr = head->next;
		delete head;
		head = ptr;
	}
	return;
}

void stack::push(int value){
	node *newnode = new node;
	newnode->next = head;
	newnode->data = value;
	head = newnode;
	return;
}

int stack::pop(){
	node *popnode=head;
	int value = head->data;

	if(head == NULL)
		cout<<"NULL"<<endl;
	head = head->next;
	delete popnode;
	return value;
}

void stack::print_stack()
{
	while(head){
		cout<< head->data <<endl;
		head = head->next;
	}
	return;
}

int main()
{
	int a=5,b=10;
	stack s;
	s.push(a);
	s.push(b);
	s.push(15);
	s.pop();
	s.print_stack();
	system("pause");
	return 0;
	
}
