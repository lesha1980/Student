#include "general.h"

Student::Student()
{
	this->group = nullptr;
	this->last_name = nullptr;
	this->success = new int[5];
}

Student::Student(Student& student)
{
	this->group = new char[strlen(student.getGroup())];
	strcpy_s(this->group, strlen(student.getGroup()) + 1, student.getGroup());
	this->last_name = new char[strlen(student.getlastName())];
	strcpy_s(this->last_name, strlen(student.getlastName()) + 1, student.getlastName());
	this->success = new int[5];
	for (size_t i = 0; i < 5; i++) {
		this->success[i] = student[i];
	}
	
}

Student::Student(char* group, char* lastName)
{
	this->group = new char[strlen(group) + 1];
	strcpy_s(this->group, strlen(group) + 1, group);
	this->last_name = new char[strlen(lastName) + 1];
	strcpy_s(this->last_name, strlen(lastName) + 1, lastName);
	this->success = new int[5];
	
	
}

void Student::setGroup(char* group)
{
	if (this->group != NULL) {
		delete[] this->group;
	}
	this->group = new char[strlen(group)];
	strcpy_s(this->group, strlen(group), group);
}

void Student::setlastName(char* lastName)
{
	if (this->last_name != NULL) {
		delete[] this->last_name;
	}

	this->last_name = new char[strlen(lastName)];
	strcpy_s(this->last_name, strlen(lastName), lastName);
}

int& Student::operator[](const int& index)
{
	return this->success[index];
}


char* Student::getGroup()
{
	return this->group;
}

char* Student::getlastName()
{
	return this->last_name;
}

int Student::getSuccesIndex(int index)
{
	return this->success[index];
}

void Student::printStudent()
{
	cout << "Студент: " << this->last_name << endl;
	cout << "Група: " << this->group << endl;
	cout << "Оцінки: ";

	for (size_t i = 0; i < 5; i++) {
		cout << this->success[i] << ", ";
	}
	cout << endl;
}

Student::~Student()
{
	this->group = nullptr;
	delete[] this->group;
	this->last_name = nullptr;
	delete[] this->last_name;
	this->success = nullptr;
	delete[] this->success;
}
