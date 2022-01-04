#include <iostream>
using namespace std;

class List{
	private:
		class Node{
			public:
				Node(int k, char d){
					k = k;
					data = d;
					next = NULL;
				}
			public:
				int k;
				char data;
				Node *next;
		};

        	Node *Cursor, *Prev, *Head;
        	List(){
 	   		Cursor = Prev = Head = NULL;
        	}

		bool listIsEmpty(){
			return Head == NULL;
		}

		bool cursorIsEmpty(){
			return Cursor == NULL;
		}

		bool atFirst(){
			return Head == Cursor;
		}

		void toFirst(){
			Cursor = Head;
			Prev = NULL;
		}
	
		void advance(){
			/* or 
			 * Prev = Cursor;
			 * Cursor = Cursor->next
			 */
			Cursor = Cursor->next;
			Prev = Prev->next;
		}

		Node *createNode(int k, char d){
			Node *node = new Node(k, d);
			return node;
		}

		void insertFirst(int k, char d){
			Node *getNode = createNode(k, d);
			getNode->next = Head;
			Head = getNode;
			Cursor = Head;
			Prev = NULL;
		}

		void insertAfter(int k, char d){
			Node *getNode = createNode(k, d);
			getNode->next = Cursor->next;
			Cursor->next = getNode;
			//move forward
			advance();	
		}

		void backWard(Node *point){
			Cursor = point;
		}

		void insertBefore(int k, char d){
			Node *getNode = createNode(k, d);
			getNode->next = Prev->next;
			Prev->next = getNode;
			backWard(getNode);

		}

		void deleteFirstNode(){
			if(!listIsEmpty()){
				Node *q = Head;
				Head = Head->next;
				toFirst();	
				delete q;
			}
		}

		void deleteCurrentNode(){
			Node *q = Cursor;
			advance();	
			delete q;
		}

		void deleteNode(){
			if(!listIsEmpty()){
				if(atFirst()){
					deleteFirstNode();
				}else{
					deleteCurrentNode();
				}
			}
		}

		void deleteFirst(){
				toFirst(); deleteNode();
		}

		void toEnd(){
			Cursor = Head;
			if(!listIsEmpty()){
				while(Cursor->next != NULL){
					advance();	
				}
			}
		}

		void deleteEnd(){
			toEnd();
			deleteNode();
		}

		void makeListEmpty(){
			toFirst(); // go to the head of the linkdlist;
			while(Cursor != NULL){
				deleteNode(); //delete node and go forward
			}
		}

		int listSize() {
			int size = 0;
			toFirst();
			while(Cursor != NULL){
				advance();	
				size++;
			}
			return size;
		}

		bool atEnd(){
			if(listIsEmpty() || Cursor->next == NULL){
				return true;
			}
			return false;
		}

		void updateData(const char d){
			Cursor->data = d;
		}

		void retriveData(int k, char d)const{
			k = Cursor->k;
			d = Cursor->data;
		}

		void retriveKey(int k) const{
			k = Cursor->k;
		}

		void insertEnd(int k , char d){
			if(listIsEmpty()) insertFirst(k, d);
			else{
				toEnd();
				insertAfter(k, d);
			}
		}

		bool isKeyFound(const int k){
			bool isFound = false;
			while(!isFound && Cursor != NULL){
				if(Cursor->k == k){
					return true;
				}
				advance(); // go forward
			}
			return false;
		}

		void traverse(){
			toFirst();
			while(Cursor != NULL){
				cout<<Cursor->data<<endl;
				advance();
			}
		}

		void insertInOrder(int k, char d){
			toFirst();
			while(Cursor != NULL && k > Cursor->k){
				advance();
			}
			if(Prev == NULL) insertFirst(k, d);
			else insertBefore(k, d);
		}
};

int main(){
	return 0;
}
