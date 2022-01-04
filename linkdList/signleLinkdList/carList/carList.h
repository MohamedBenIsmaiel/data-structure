#ifndef carList_h
#define carList_h

#include <iostream>
#include <cstring>

using  namespace std;

class CarList{
    private:
        class Car{
            public:
                string name;
                string model;
                Car *next;
        };
        Car *Head , *Cursor , *Prev;
    public:
        typedef Car* CarType;

        CarList();
        CarList(string name, string model);

        void insertFirst(const string name, const string model);
        void traverse();
        void toFirst();
        void advance();

        bool isCurrentEmpty()const;
        bool isCarNameFound(string name);
        int size()const;       

        CarType createCar(string name, string model);

};

#endif