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

   void fill(){
     int fillLength;
     cout<<"Plz enter fill length "<<endl;
     cin>>fillLength;

     if(fillLength > size){
        cout<<"Length can not be greater than size "<<endl;
	      return;
     }

     for(int i=0; i<fillLength; i++){
     	cout<<"Plz Enter array value "<<i<<endl;
	    cin>>items[i];
	    length++;
     }
   }

   void traverse(){
    cout<<"[*] Print array elements ";
    for(int i=0; i<length; i++){
      cout<<items[i]<<"\t";
    } 
    cout<<endl;
   }

   int getArrayLength(){
     return length;
   }

   int getArraySize(){
     return size;
   }

   int search(float key){
     int index = -1;
     for(int i=0; i<length; i++){
       if(items[i] == key){
         index = i;
         break;
       }
     }
     return index;
   }

   void append(float item){
    if(length < size){
      items[length] = item;
      length++;
    } else
      cout<<"Array is Full "<<endl;
   }

   void insert(int index, float value){
     if(length >= size){
      cout<<"Array is Full"<<endl;
     }

     if(index >=0 && index < size){
      for(int i=length; i>index; i--){
       items[i] = items[i-1];
      }
      items[index] = value;
      length++;
     }else{
      cout<<"Out of Range"<<endl;
     }
   }

  void deleteItem(int index){
    if(index >= 0 && index < size){
      for(int i=index; i<length -1; i++){
         items[i] = items[i+1];
      }
      length--;
    }else{
      cout<<"Out of Range "<<endl;
    }
  }

  void enLarge(int newSize){
    float *old = items;
    size = newSize;
    items = new float[size];

    for(int i=0; i<length; i++){
      items[i] = old[i];
    }
    delete []old;
  }

  void merge(Items other){
    int newSize = size + other.getArraySize();
    size = newSize;
    float *old = items;

    items = new float[size];
    int i;
    for(i=0; i<length; i++){
      items[i] = old[i];
    }

    delete []old;

    int j = i;
    for(int i=0; i<other.getArrayLength(); i++){
      items[j++] = other.items[i];
      length++;
    }
    
  }

};

int main(){
  cout<<"Enter array size "<<endl;
  int size; 
  cin>>size;

  Items items(size);
  items.fill();
  items.traverse();
  cout<<"Array Size is : "<<items.getArraySize()<<" Array Length is : "<<items.getArrayLength()<<endl;
/*
  float key; 
  cout<<"Enter key you want to search for "<<endl;
  cin>>key;

  int keyIndex = items.search(key);
  if(keyIndex == -1)
    cout<<"Key does not exist"<<endl;
  else
   cout<<"Key exist and its index in array is "<<keyIndex<<endl;
*/

//  float appendItems;
 // cout<<"Enter new Items "<<endl;
  //cin>>appendItems;
  //items.append(appendItems);
  //items.traverse();

//  cout<<"[**] array size is "<<items.getArraySize()<<endl;
 // cout<<"[**] array length is "<<items.getArrayLength()<<endl;

/*
 int index, value;
 cout<<"Plz Enter Index and value "<<endl;
 cin>>index>>value;
 items.insert(index, value);
 */
 /*
 int item;
 cout<<"Plz Enter Index for item you want to delete "<<endl;
 cin>>item;
 items.deleteItem(item);
 */

/*
 int newSize;
 cout<<"Enter new size "<<endl;
 cin>>newSize;

 items.enLarge(newSize);
 */

Items array(3);
array.fill();
items.merge(array);
 items.traverse();
 cout<<"Array Size is : "<<items.getArraySize()<<" Array Length is : "<<items.getArrayLength()<<endl;
 return 0;
}
