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
};

int main(){
	return 0;
}
