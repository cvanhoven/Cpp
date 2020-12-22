#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Nodes
struct Node {
	int data;
	Node* next;
	Node();
	Node(int, Node* add_on = nullptr);
};

Node::Node() {
	data = 0;
	next = nullptr;
}

Node::Node(int item, Node* add_on) {
	data = item;
	next = add_on;
}

void print(Node* p) {
	cout << p->data << endl;
}
// Stack
class Stack {
public:
	Stack();
	void push(int);
	void pop();
	void printStack();
private:
	Node* top;
};

Stack::Stack() {
	top = nullptr;
}

void Stack::push(int num) {
	Node* p = new Node(num, top);
	if (p == nullptr) {
		cout << "overflow";
	}
	else {
		top = p;
		cout << "success";
	}
}

void Stack::pop() {
	Node* p = top;
	if (top == nullptr) {
		cout << "underflow";
	}
	else {
		top = p->next;
		delete p;
		cout << "success";
	}
}

void Stack::printStack() {
	Node* p = top;
	if (p != nullptr) {
		cout << p->data << endl;
		while (p->next != nullptr) {
			p = p->next;
			cout << p->data << endl;
		}
	}
}
// Queue
class Queue {
public:
	Queue();
	void append(int);
	void serve();
	void printQueue();
	void getFront();
private:
	Node* front;
	Node* rear;
};

Queue::Queue() {
	front = nullptr;
	rear = nullptr;
}

void Queue::append(int num) {
	Node* p = new Node(num);
	if (front == nullptr) {
		front = p;
		rear = p;
		cout << "overflow";
	}
	else {
		rear->next = p;
		rear = p;
		cout << "success";
	}
}

void Queue::serve() {
	Node* p = front;
	if (front == nullptr) {
		cout << "underflow";
	}
	else {
		front = front->next;
		delete p;
		cout << "success";
	}
}

void Queue::printQueue() {
	Node* p = front;
	if (p != nullptr) {
		cout << p->data << endl;
		while (p->next != nullptr) {
			p = p->next;
			cout << p->data << endl;
		}
	}
}

void Queue::getFront() {
	if (front != nullptr) {
		cout << front->data;
	}
	else {
		cout << "---";
	}
}

int main() {
	Stack s;
	Queue q;
	fstream file;
	string fileName;
	string op;
	int data;

	cout << "What is the file name you wish to be read?" << endl;
	cin >> fileName;
	file.open(fileName);
	while (!file.good()) {
		cout << "Sorry. That file could not be opened. Please try again." << endl << endl;
		cin >> fileName;
		file.open(fileName);
	}

	cout << "Operation\t" << "Stack\t" << "Value\t" << "Result" << endl << endl;

	while (!file.eof()) {
		file >> op;
		
		if (op == "append") {
			file >> data;
			cout << "append\t" << "queue\t" << data << "\t";
			q.append(data);
			cout << endl;
		}
		else if (op == "serve") {
			cout << "serve\t" << "queue\t";
			q.getFront();
			cout << "\t";
			q.serve();
			cout << endl;
		}
		else if (op == "push") {
			file >> data;
			cout << "push\t" << "stack\t" << data << "\t";
			s.push(data);
			cout << endl;
		}
		else if (op == "pop") {
			cout << "pop\t" << "stack\t" << "---\t";
			s.pop();
			cout << endl;
		}
	}
	file.close();

	cout << endl << "Stack" << endl;
	s.printStack();

	cout << endl << "Queue" << endl;
	q.printQueue();
}