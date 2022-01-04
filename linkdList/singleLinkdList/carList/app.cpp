#include <iostream>
#include <cstring>
#include "carList.h"
#include "carList.cpp"

int main(){
    CarList carList = CarList("bmw", "2020");
    carList.insertFirst("jeep", "2000");
    carList.insertFirst("kia", "2001");
   // carList.traverse();
   cout<<carList.isCarNameFound("ss")<<endl;

    return 0;
}