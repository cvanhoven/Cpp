#include <fstream>
#include <iostream>
#include <string>
using namespace std;
typedef int Node_entry;

// Nodes
struct Node {
	Node_entry entry;
	Node * next;
	Node * prev;
	Node();
	Node(Node_entry, Node* add_on = nullptr);
	Node(Node_entry, Node* next, Node* prev);
};

Node::Node() {
	next = nullptr;
}

Node::Node(Node_entry item, Node* add_on) {
	entry = item;
	next = add_on;
}

Node::Node(Node_entry item, Node* follow, Node* previous) {
	entry = item;
	next = follow;
	prev = previous;
}

void print(Node * p) {
	cout << p->entry << endl;
}

// Single Linked List
class SingleList {
public:
	SingleList();
	void insert(int);
	void traversePrint(void (*visit)(Node * p));
	int getData();
private:
	int count = 0;
	Node* head;
};

// Constructor
SingleList::SingleList() {
	count = 0;
	head = nullptr;
}

// Inserts the value at the end of the list.
void SingleList::insert(int n) {
	if (head == nullptr) {
		head = new Node(n);
		head->next = nullptr;
	}
	else {
		Node * p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new Node(n);
	}
	count++;
}

// Goes through the linked list and prints each value
void SingleList::traversePrint(void (*visit)(Node * p)) {
	Node* p;
	p = head;
	while (p != nullptr) {
		(*visit)(p);
		p = p->next;
	}
}

int SingleList::getData() {
	Node* p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	return p->entry;

}

// Double Linked List
class DoubleList {
public:
	DoubleList();
	void orderedInsert(int);
	void traversePrint(void (*visit)(Node * p));
private:
	int count = 0;
	Node* head;
};

// Constructor
DoubleList::DoubleList() {
	count = 0;
	head = nullptr;
}

// Inserts the value into the double linked list in numerical order
void DoubleList::orderedInsert(int n) {
	Node* node = new Node(n);
	if (head == nullptr) {
		head = new Node(n);
		head->next = nullptr;
	}
	else {
		Node * p = head;
		Node * q = nullptr;
		while (p != nullptr && n > p->entry) {
			q = p;
			p = p->next;
		}
		if (q == nullptr) {
			node->next = p;
			p->prev = node;
			head = node;
		}
		else {
			if (p == nullptr) {
				q->next = node;
				node->prev = q;
			}
			else {
				node->next = p;
				node->prev = q;
				p->prev = node;
				q->next = node;
			}
		}
	}
	count++;
}

// Goes through Double list and prints each value there. 
void DoubleList::traversePrint(void (*visit)(Node * p)) {
	Node * p;
	p = head;
	while (p != nullptr) {
		(*visit)(p);
		p = p->next;
	}
}

// Main function
int main() {
	cout << "Chris Vanhoven" << endl << "CS 2420, Section 1" << endl << "Program 2 - Linked Lists" << endl << endl;

	fstream input;
	string fileName;
	cout << "Enter the file name you would like to use:" << endl << endl;
	cin >> fileName;
	input.open(fileName);
	while (!input.good()) {
		cout << "Sorry. That file could not be opened. Please try again." << endl << endl;
		cin >> fileName;
	}

	int data;
	SingleList sList;
	DoubleList dList;

	input >> data;
	while (!input.eof()) {
		sList.insert(data);
		dList.orderedInsert(sList.getData());
		input >> data;
	}
	
	cout << "Single Linked List contents:" << endl;
	sList.traversePrint(print);

	cout << endl << "Double Linked List contents:" << endl;
	dList.traversePrint(print);

	input.close();
}