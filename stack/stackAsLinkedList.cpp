#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;

    Node(){
      data = 0;
      next = NULL;
    }
};

class Stack{
  public:
     Node *top;

    Stack(){
      top = NULL;
    }

    bool isEmpty(){
      return (top == NULL);
    }

    void push(int data){
      Node *node = new Node();
      node->data = data;
      if(isEmpty()){
	top = node;
	return;
      }else{
        node->next = top;
	top = node;
      }

    }

    void traverse(){
      if(isEmpty()){
        cout<<"Stack is Empty !"<<endl;
      }else{
	Node *temp = top;
	while(temp != NULL){
	  cout<<temp->data<<" , ";
	  temp = temp->next;
	}
	cout<<endl;
	delete temp;
      }
    }

    int pop(){
      Node *delPtr;
      delPtr = top;
      top = top->next;
      int result = delPtr->data; 
      delete delPtr;
      return result;
    }

    int peek(){
      return top->data;
    }

    int count(){
      int counter = 0;
      Node *temp = top;
      while(temp != NULL){
        counter += 1;
	temp = temp->next;
      }
      delete temp;
      return counter;
    }

    bool isExist(int data){
      bool exist = false;
      Node *temp = top;
      while(temp != NULL){
        if(data == temp->data){
          exist = true;
	  break;
	}
	temp = temp->next;
      }
      delete temp;
      return exist;
    }

    bool isFull(){
      bool full = false;
      Node *node = new Node();
      if(node == NULL){
        full = true;
      }
      delete node;
      return full;
    }

};

int main(){
  Stack stack;
  for(int i=0; i<3; i++){
   cout<<"Plz Enter a value "<<endl;
   int value;
   cin>>value;

   stack.push(value);
   stack.traverse();
  }
  cout<<"\n";
  cout<<"pop element "<<stack.pop()<<endl;
  stack.traverse();

  cout<<"Peek "<<stack.peek()<<endl;
  cout<<"counter "<<stack.count()<<endl;

  int searchItem;
  cout<<"Plz Enter data you want to search "<<endl;
  cin>>searchItem;
  if(stack.isExist(searchItem)){
    cout<<"Item Exist"<<endl;
  }else{
    cout<<"Item dose not exist"<<endl;
  }

  if(stack.isFull()){
     cout<<"stack is Full "<<endl;
  }else{
     cout<<"stack is not Full"<<endl;
  }
  return 0;
}
