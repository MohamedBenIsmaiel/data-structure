#include <iostream>
using namespace std;

struct dic{
	string word;
	int count;
};

struct Node{
	dic di;
	Node *next;
};

int main(){
	Node *a, *b;
	dic dic1, dic2;

	dic1.word =  "ismaiel";
	dic1.count = 2;

	dic2.word = "if";
	dic2.count = 3;

	a = new Node;
	b = new Node;

	a->di = dic1;
	a->next = b;

	b->di = dic2;
	b->next = NULL;

	cout<<a->di.word<<endl;
	cout<<b->di.word<<endl;

	return 0;
}
