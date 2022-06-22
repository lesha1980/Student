#pragma once

struct Student {

private:
	char* group;                           //група, до я кої належить студент
	char* last_name;                       //прізвище студента
	int* success;                          //масив оцінок студента

public:

	Student();
	Student(Student&);
	Student(char*, char*);

	void setGroup(char*);
	void setlastName(char*);
	int& operator[](const int&);            //повертає значення оцінки студента відповідно до індексі в масиві
	char* getGroup();
	char* getlastName();  
	int getSuccesIndex(int);
	void printStudent();

	~Student();
};
