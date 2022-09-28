#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

class LinkedList{
  public:
   Node *Head;
   Node *temp;

   LinkedList(){
     Head = NULL;
   }

   bool isEmpty(){
     return (Head == NULL);
   }

   void insertFirst(int data){
     Node *node = new Node();
     node->data = data;
     
     if(isEmpty()){
       node->next = NULL;
       Head = node;
     }else{
       node->next = Head;
       Head = node;
     }
   }

   void goNext(){
    temp = temp->next; 
   }

   void display(){
     temp = Head;
     while(temp != NULL){
       cout<<"Node : "<<temp->data<<endl;
       goNext();
     }
   }

  int count(){
     int counter = 0;
     temp = Head;
     while(temp != NULL){
       counter++;
       goNext();
     }
     return counter;
   }

  bool isExist(int data){
    bool exist = false;
    temp = Head;
    while(temp != NULL){
       if(data == temp->data){
	  exist = true;
	  break;
       }else{
         goNext();
       }
     }
     return exist;
  }

  void insertBefore(int item, int newItem){
    if(!isExist(item)){
      cout<<"Item you want to add before is not exist"<<endl;
      return;
    }

    Node *node = new Node();
    node->data = newItem;

    temp = Head;
    while((temp != NULL && temp->next->data != item) /*|| (temp->next != NULL  && temp->data != item)*/){
      goNext();
    }

    node->next = temp->next;
    temp->next = node;
  }

  void append(int item){
    if(isEmpty())
      insertFirst(item);
    else{
      Node *node = new Node();
      node->data = item;

      temp = Head;
      while(temp->next != NULL){
        goNext();
      }
      
      temp->next = node;
      node->next = NULL;
    }
  }

  void deleteFirst(int item){
     Node *delPtr = Head;
     Head = Head->next;
     delete delPtr;
  }


  void deleteNode(int item){
    if(Head->data == item){
       deleteFirst(item);
       return;
    }else{
      temp = Head;
      while(Head != NULL){
       Node *delPtr = temp->next;

       if(temp->next->data == item && temp->next->next == NULL){
	  temp->next = NULL;
	  delete delPtr;
	  break;
       } 

       if(temp->next->data == item){
	  temp->next = temp->next->next;
	  delete delPtr;
	  break;
       }

       goNext();

      }
    }
  }


};

int main(){
  int itemsLength;
  LinkedList list;  

  cout<<"Plz Enter number of items you want to insert "<<endl; 
  cin>>itemsLength;

  for(int i=0; i<itemsLength; i++){
    int data;
    cin>>data;
    list.insertFirst(data);
  }


  cout<<"#### display linkedlist Nodes ###"<<endl;
  list.display();

  cout<<"####  linkedlist length  ###"<<endl;
  cout<<list.count()<<endl;

  cout<<"Enter key you want to search about"<<endl;
  int key;
  cin>>key;

  if(list.isExist(key) == true){
     cout<<"key is Exist"<<endl; 
  }else{
     cout<<"key is not Exist"<<endl; 
  }

  cout<<"Insert item and value to insert before "<<endl;
  int item;
  int value;
  cin>>item;
  cin>>value;

  list.insertBefore(item, value);
  list.display();

  cout<<"Insert last item in list"<<endl;
  int last;
  cin>>last;
  list.append(last);
  list.display();


  cout<<"ENter item to delete "<<endl;
  int deletedItem;
  cin>>deletedItem;

  list.deleteNode(deletedItem);
  list.display();

  return 0;

}
