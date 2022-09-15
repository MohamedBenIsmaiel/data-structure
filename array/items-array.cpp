#include <iostream>
using namespace std;

class Items{
  private:
   int length = 0;
   int size = 0;
   float *items;

  public:
   Items(int arraySize){
     size = arraySize;
     items = new float[size];
   }

   void fill(int fillLength){
     if(fillLength > size){
        cout<<"Length can not be greater than size "<<endl;
	return;
     }

     cout<<"Plz Enter array value "<<endl;
     for(int i=0; i<fillLength; i++){
	float value;
	cin>>value;

	items[i] = value;		
	length++;
     }
   }

   void traverse(){
    for(int i=0; i<length; i++){
      cout<<"[*] Print array elements ";
      cout<<items[i]<<endl;
    } 
   }

   int getArrayLength(){
     return length;
   }

   int getArraySize(){
     return size;
   }
};

int main(){
  cout<<"Enter array size "<<endl;
  int size; 
  cin>>size;

  Items items(size);

  cout<<"Enter Fill length"<<endl;
  int length;
  cin>>length;

  items.fill(length);
  items.traverse();
  cout<<"[**] array size is "<<items.getArraySize()<<endl;
  cout<<"[**] array length is "<<items.getArrayLength()<<endl;
  return 0;
}
