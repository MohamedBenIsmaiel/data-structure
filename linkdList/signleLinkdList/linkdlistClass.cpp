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

		void setAfter(Node *cursor, int k, char d){
			Node *getNode = createNode(k, d);
			getNode->next = cursor->next;
			cursor->next = getNode;
			//move forward
			advance();	
		}

		void backWard(Node *point){
			Cursor = point;
		}

		void setBefore(Node *cursor, int k, char d){
			Node *getNode = createNode(k, d);
			getNode->next = Prev->next;
			Prev->next = getNode;
			backWard(getNode);

		}

		void deleteFirstNode(){
			Node *q = Head;
			Head = Head->next;
			toFirst();	
			delete q;
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

		int listSize() const{
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
};

int main(){
	return 0;
}
