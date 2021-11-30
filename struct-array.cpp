#include <iostream>
using namespace std;


string *addressArr;
struct subject{
	int id;
	string name;
	int mark;
};

struct student{
	int id;
	string name;
	string  *address;
	subject *subj;	
};

void print(student *students, int studentsSize, int addressSize, int subjectSize);
void populate(student *students, int studentsSize, int addressSize, int subjectSize);
void initStudent(student *students, subject *sub, string *address, int studentsSize);

int main(){
	int  studentsSize, addressSize, subjectSize;

	cout<<"Enter the size of students array "<<endl;
	cin>>studentsSize;

	cout<<"Enter the size of address array "<<endl;
	cin>>addressSize;

	cout<<"Enter the size of subject array "<<endl;
	cin>>subjectSize;

	addressArr = new string[addressSize];

	subject* sub = new subject[subjectSize];


	student *stud = new student[studentsSize];
	initStudent(stud, sub, addressArr, studentsSize);

	populate(stud, studentsSize, addressSize, subjectSize);
	print(stud, studentsSize, addressSize, subjectSize);
	return 0;
}

void initStudent(student *students, subject *sub, string *address,int studentsSize){
	for(int i=0; i<studentsSize; i++){
		students[i].address = addressArr;
		students[i].subj = sub;
	}
}

void print(student students[], int studentsSize, int addressSize, int subjectSize){
	for(int i=0; i<studentsSize; i++){

		cout<<"Student id is "<<students[i].id<<endl;
		cout<<"Student name is "<<students[i].name<<endl;

		for(int j=0; j<addressSize; j++){
			cout<<"student address  is "<<students[i].address[j]<<endl;
		}

		for(int k=0; k<subjectSize; k++){
			cout<<" subject id is "<<students[i].subj[k].id<<endl;
			cout<<" subject name is "<<students[i].subj[k].name<<endl;
			cout<<" subject mark is "<<students[i].subj[k].mark<<endl;
		}
	}
}

void populate(student students[], int studentsSize, int addressSize, int subjectSize){
	int studentId = 1;
	for(int i=0; i<studentsSize; i++){
		int subjectId = 1;
		students[i].id = studentId;

		cout<<"Enter student name "<<endl;
		cin>>students[i].name;

		for(int j=0; j<addressSize; j++){
			cout<<"Enter Sudent Address "<<endl;
			cin>>students[i].address[j];
		}

		for(int k=0; k<subjectSize; k++){
			students[i].subj[k].id = subjectId;
			cout<<"Enter Subject name "<<endl;
			cin>>students[i].subj[k].name;
			cout<<"Enter subject mark "<<endl;
			cin>>students[i].subj[k].mark;

			subjectId++;
		}

		studentId++;
	}
}
