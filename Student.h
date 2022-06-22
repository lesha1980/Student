#pragma once

struct Student {

private:
	char* group;                           //�����, �� � �� �������� �������
	char* last_name;                       //������� ��������
	int* success;                          //����� ������ ��������

public:

	Student();
	Student(Student&);
	Student(char*, char*);

	void setGroup(char*);
	void setlastName(char*);
	int& operator[](const int&);            //������� �������� ������ �������� �������� �� ������ � �����
	char* getGroup();
	char* getlastName();  
	int getSuccesIndex(int);
	void printStudent();

	~Student();
};
