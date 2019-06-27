/*
Program to implement a stack as well as solve 3.2 in CTCI.
Implementing a stack with min in O(1) time.
*/

#include<exception>
#include<iostream>

using namespace std;

class emptyStack : public exception {
	virtual const char* what() const throw() {
		return "ERROR STACK IS EMPTY.";
	}
};

class emptyQueue : public exception {
	virtual const char* what() const throw() {
		return "ERROR Queue IS EMPTY.";
	}
};

//Underlying Container
struct ListNode {
	int val{ 0 };
	ListNode* next{ nullptr };
	ListNode(int x) : val{ x }, next{ nullptr }{}
};


//Stack
struct myStack {
	int nelem{ 0 }; //num of elems
	ListNode* top{ nullptr };

	int pop(); //removes top element and returns it
	void push(int x); //adds elem to top
	int peek();//peeks top elem without popping
	bool is_empty() { return nelem == 0; };
	int size() { return nelem; };
};

int myStack::pop() {
	if (top == nullptr) throw emptyStack();

	--nelem;
	auto temp = top;
	int val = temp->val;
	top = top->next;
	delete temp;
	return val;
}

void myStack::push(int x) {
	auto new_top = new ListNode(x);
	new_top->next = top;
	top = new_top;
	++nelem;
}

int myStack::peek() {
	if (top == nullptr) throw emptyStack();

	return top->val;
}

//Queue
struct myQueue {
	ListNode* first{ nullptr };
	ListNode* last{ nullptr };

	int peek();
	void add(int x);
	bool isEmpty() { return first == last && first == nullptr; }
	int pop();
};

int myQueue::peek() {
	if (first == last) throw emptyQueue();
	else {
		return first->val;
	}
}

void myQueue::add(int x) {
	if (first == last && first == nullptr) {
		first = new ListNode(x);
		last = first;
	}
	else {
		last->next = new ListNode(x);
		last = last->next;
	}
}

int myQueue::pop() {
	if (first == last && first == nullptr) throw emptyQueue();
	else {
		auto temp = first;
		int val = temp->val;
		first = first->next;
		delete temp;
		return val;
	}
}

class myQueueStack {
public:
	int peek();
	int pop();
	bool is_empty();
	void add(int x);

private:
	myStack tempstack;
	myStack qstack;

	void build_queue();
};


//3.4
int myQueueStack::peek() {
	if (tempstack.is_empty() && qstack.is_empty())
		throw emptyQueue();
	else {
		if (!qstack.is_empty())
			return qstack.peek();
		else {
			build_queue();
			return qstack.peek();
		}
	}
}

int myQueueStack::pop() {
	if (tempstack.is_empty() && qstack.is_empty())
		throw emptyQueue();
	else {
		if (!qstack.is_empty())
			qstack.pop();
		else {
			build_queue();
			qstack.pop();
		}
	}
}

bool myQueueStack::is_empty() {
	return tempstack.is_empty() && qstack.is_empty();
}

void myQueueStack::add(int x) {
	tempstack.push(x);
}

void myQueueStack::build_queue() {
	if (tempstack.is_empty() && qstack.is_empty()) throw emptyQueue();
	else if (!qstack.is_empty()) return; //queue already exists

	while (!tempstack.is_empty())
		qstack.push(tempstack.pop());
}