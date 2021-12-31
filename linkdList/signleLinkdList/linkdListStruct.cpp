#include <iostream>
using namespace std;

struct Student{
	string name;
	int age;
};

struct Node{
	Student std;
	Node *next;
};

void insertAtHead(Node *node, Node *head, string studentName, int studentAge);
void insertAfterNode(Node *node, Node *cursor, string studentName, int studentAge);
void insertAtEnd(Node *node, Node *lastNode, string studentName, int studentAge);
void deleteHead(Node *head, Node *cursor);
void deleteNode(Node *cursor, Node *node);

int main(){
	Node *head, *first, *second, *third, *node, *fourth;
	Student std1, std2, std3, std4;

	head = new Node;
	first = new Node;
	second = new Node;
	third = new Node;
	node = new Node;
	fourth = new Node;


	std1.name = "mohamed";
	std1.age = 20;
	std2.name = "ahmed";
	std2.age = 5;
	std3.name = "ismaiel";
	std3.age = 50;
	std4.name = "mostafa";
	std4.age = 19;

	head = first;

	first->std = std1;
	first->next= second;

	second->std = std2;
	second->next = third;

	third->std = std3;
	third->next = fourth;

	fourth->std = std4;
	fourth->next = NULL;

	string studentName;
	int studentAge;

	cout<<"Enter student name "<<endl;
	cin>>studentName;

	cout<<"Enter student age"<<endl;
	cin>>studentAge;
	
	deleteNode(second, node);
	cout<<"second next address "<< second->next <<endl;
	cout<<"fourth address "<< fourth <<endl;
	return 0;
}


void insertAtHead(Node *node, Node *head, string studentName, int studentAge){
	node->std.name = studentName;
	node->std.age = studentAge;

	node->next = head;
	head = node; 
}

void insertAfterNode(Node *node, Node *cursor, string studentName, int studentAge){
	node->std.name = studentName;
	node->std.age = studentAge;

	node->next = cursor->next;
	cursor->next = node;
}

void insertAtEnd(Node *node, Node *lastNode, string studentName, int studentAge){
	node->std.name = studentName;
	node->std.age = studentAge;

	node->next = NULL;
	lastNode->next = node;
}

void deleteHead(Node *head, Node *cursor){
	cursor = head;
	head = head->next;
	delete cursor;
}

void deleteNode(Node *cursor, Node *node){
	node = cursor->next;
	cursor->next = node->next;
	delete node;
}
