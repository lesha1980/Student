#pragma once

/*
������� ��������
*/

#include <iostream>
#include <string.h>
#include <ctime>
#include <conio.h>


using namespace std;

/*
���������� �������
*/
#include "Student.h"

/*
��������� �������
*/

template<typename T> T* dyn_arr_change(T*, size_t, size_t);
Student* lstExcelentStudents(Student*, size_t);
Student* lstBadStudents(Student*, size_t);

