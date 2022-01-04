#include "carList.h"

CarList::CarList(){
    Head = Cursor = Prev = NULL;
}

CarList::CarType CarList::createCar(string name, string model){
    CarType q = new Car; 
    q->name = name;
    q->model = model;
    return q;
}

CarList::CarList(string name, string model){
    CarType q = createCar(name, model);
    q->next = Head;
    Head = q;
    Cursor = Head;
}

void CarList::insertFirst(const string name, const string model){
    CarType q = createCar(name, model);
    q->next = Head;
    Head = q;
    toFirst();
}

void CarList::toFirst(){
   Cursor = Head;
   Prev   = NULL; 
}

bool CarList::isCurrentEmpty() const{
    return (Cursor == NULL);
}

void CarList::advance(){
    Prev = Cursor;
    Cursor = Cursor->next;
}

void CarList::traverse(){
    toFirst();
    while(!isCurrentEmpty()){
        cout<<"Car name is "<< Cursor->name <<endl;
        cout<<"Car model is "<< Cursor->model <<endl;

        advance(); 
        
    }
}

int CarList::size() const{
    int count = 0;

    if(Head == NULL) return 0;

    CarType q;
    q = Head;

    while(q->next != NULL){
        count++;
        q = q->next;
    }
    return count;
}

bool CarList::isCarNameFound(string name){
    toFirst();
    while(!isCurrentEmpty()){
        if(Cursor->name == name) return true;
        advance();
    }
    return false;
}