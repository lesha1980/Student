#include "general.h"

int main() {

	time(NULL);
	setlocale(LC_ALL, "");
	cout << "��������" << endl;

	Student student0(new char[] {"�����1"}, new char[] {"�������1"});
	for (size_t i = 0; i < 5; i++) {
		student0[i] = rand() % 5 + 1;
	}
	Student student1(new char[] {"�����1"}, new char[] {"�������2"});
	for (size_t i = 0; i < 5; i++) {
		student1[i] = rand() % 5 + 1;
	}
	Student student2(new char[] {"�����1"}, new char[] {"�������3"});
	for (size_t i = 0; i < 5; i++) {
		student2[i] = rand() % 5 + 1;
	}
	Student student3(new char[] {"�����2"}, new char[] {"�������4"});
	for (size_t i = 0; i < 5; i++) {
		student3[i] = rand() % 5 + 1;
	}

	Student student4(new char[] {"�����2"}, new char[] {"�������5"});
	for (size_t i = 0; i < 5; i++) {
		student4[i] = rand() % 5 + 1;
	}
	Student student5(new char[] {"�����2"}, new char[] {"�������6"});
	for (size_t i = 0; i < 5; i++) {
		student5[i] = rand() % 5 + 1;
	}
	Student student6(new char[] {"�����2"}, new char[] {"�������7"});
	for (size_t i = 0; i < 5; i++) {
		student6[i] = rand() % 5 + 1;
	}

	Student student7(new char[] {"�����1"}, new char[] {"�������8"});
	for (size_t i = 0; i < 5; i++) {
		student7[i] = rand() % 5 + 1;
	}

	Student student8(new char[] {"�����2"}, new char[] {"�������9"});
	for (size_t i = 0; i < 5; i++) {
		student8[i] = rand() % 5 + 1;
	}
	Student student9(new char[] {"�����1"}, new char[] {"�������10"});
	for (size_t i = 0; i < 5; i++) {
		student9[i] = rand() % 5 + 1;
	}

	Student* students = new Student[10]{
		student0,
		student1,
		student2,
		student3,
		student4,
		student5,
		student6,
		student7,
		student8,
		student9
	};

	cout << "�������� ��������" << endl;

	Student* exStudents = lstExcelentStudents(students, 10);

	if (exStudents != NULL) {
		int j = 0;

		while (exStudents->getSuccesIndex(j) != NULL) {
			exStudents->printStudent();
			j++;
		}
	}
	else {
		cout << "���� ��������" << endl;
	}
	cout << "�������� ������� ��������" << endl;

	Student* badStudents = lstBadStudents(students, 10);

	if (badStudents != NULL) {

		int k = 0;
		while (badStudents->getSuccesIndex(k) != NULL) {
			badStudents->printStudent();
			k++;
		}
	}
	else {
		cout << "���� �⳺�����" << endl;
	}

	_getch();

	return 0;
}

template<typename T>
inline T* dyn_arr_change(T* arr, size_t size, size_t nsize)
{
	bool ctrl = false;
	T* temp = new T[size];
	if (arr != NULL) {

		ctrl = true;
		for (size_t i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		arr = nullptr;
		delete[] arr;
	}

	arr = new T[nsize];
	if (ctrl) {
		for (size_t i = 0; i < size; i++) {
			arr[i] = temp[i];
		}
	}
	temp = nullptr;
	delete[] temp;
	return arr;
}


Student* lstExcelentStudents(Student* students, size_t size) {

	Student* stud = nullptr;
	int s = 0;
	for (size_t i = 0; i < size; i++) {

		float sum = 0;
		for (size_t j = 0; j < 5; j++) {
			int a = students->getSuccesIndex(j);

			if (a == 5) {
				sum++;
			}

		 }

		if ((sum / 5.0) * 100 > 75) {
			stud = dyn_arr_change(stud, s, ++s);
			stud[s - 1] = students[i];
		}
	}

	return stud;
}

Student* lstBadStudents(Student* students, size_t size) {

	Student* stud = nullptr;
	int s = 0;
	for (size_t i = 0; i < size; i++) {

		float sum = 0;
		for (size_t j = 0; j < 5; j++) {
			int a = students->getSuccesIndex(j);

			if (a == 2 || a == 3) {
				sum++;
			}

		}

		if ((sum / 5.0) * 100 > 25) {
			stud = dyn_arr_change(stud, s, ++s);
			stud[s - 1] = students[i];
		}
	}

	return stud;

}