#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

student addStudent();
void deleteStudent(vector<student>& massive, string bufName);
void checkStudent(vector<student>& massive, string bufName);
int changeStudent(vector<student>& massive, string bufName);

int findStudent(vector<student> massive, string bufName);

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Картотека студентов\n\n";

	vector<student> massive;

	while (true) {
		string bufName;
		int userChose = 0;

		cout << "Меню картотеки\n";
		cout << "1. Добавить студента в картотеку: " << endl;
		cout << "2. Удалить студента из картотеки: " << endl;
		cout << "3. Информация о студенте: " << endl;
		cout << "4. Изменить данные студента в картотеке:  " << endl;
		cout << "5. Выйти из картотеки:  " << endl << endl;

		cout << "Выберите вариант: ";
		cin >> userChose;
		cout << endl;

		switch (userChose)
		{
		case 1:
			cout << "Добавление студента\n";
			massive.push_back(addStudent());
			break;
		case 2:
			cout << "Удаление студента\n";
			cout << "Напишите фамилию студента: ";
			cin >> bufName;
			deleteStudent(massive, bufName);
			break;
		case 3:
			cout << "Информация о студенте\n";
			cout << "Напишите фамилию студента: ";
			cin >> bufName;
			checkStudent(massive, bufName);
			break;
		case 4:
			cout << "Изменение информации студента\n";
			cout << "Напишите фамилию студента: ";
			cin >> bufName;
			cout << endl;
			changeStudent(massive, bufName);
			break;
		case 5:
			return 1;
		default:
			cout << "Вы ввели неверное число, повторите.\n\n";
			break;
		}

	}
}


student addStudent() {
	student newStudent;
	cin >> newStudent;
	return newStudent;
}

void deleteStudent(vector<student>& massive, string bufName) {
	bool isFind = false;
	for (int i = 0; i < massive.size(); ++i) {
		if (massive[i].sgetterName() == bufName) {
			massive.erase(massive.begin() + i);
			isFind = true;
			cout << "Студент удален из картотеки" << endl << endl;
			break;
		}
	}
	if (!isFind)
		cout << "Студент не найден в списке" << endl << endl;
}

void checkStudent(vector<student>& massive, string bufName) {
	bool isFind = false;
	for (int i = 0; i < massive.size(); ++i) {
		if (massive[i].sgetterName() == bufName) {
			cout << massive[i];
			isFind = true;
			break;
		}
	}
	if (!isFind)
		cout << "Студент не найден в списке" << endl << endl;
}

int changeStudent(vector<student>& massive, string bufName) {
	int findUserFoo = findStudent(massive, bufName);
	int userChose = 0;
	int newCourse = 0;
	int newScholarship = 0;
	string newDirection;
	cout << "Меню студента\n";
	cout << "1. Изменить курс: " << endl;
	cout << "2. Изменить номер направления: " << endl;
	cout << "3. Изменить размер стипендии: " << endl;

	cout << "Выберите вариант: ";
	cin >> userChose;
	cout << endl;
	if (findUserFoo != -1) {
		switch (userChose)
		{
		case 1:
			cout << "Введите новый курс студента: ";
			cin >> newCourse;
			cout << endl;
			massive[findUserFoo].sgetterCourse(newCourse);
			break;
		case 2:
			cout << "Введите новое направление студента: ";
			cin >> newCourse;
			cout << endl;
			massive[findUserFoo].sgetterDirection(newDirection);
			break;
		case 3:
			cout << "Введите новое направление студента: ";
			cin >> newScholarship;
			cout << endl;
			massive[findUserFoo].sgetterScholarship(newScholarship);
			break;
		}
	}
}


int findStudent(vector<student> massive, string bufName) {
	bool isFind = false;
	for (int i = 0; i < massive.size(); ++i) {
		if (massive[i].sgetterName() == bufName) {
			isFind = true;
			return i;
		}
	}
	if (!isFind) {
		cout << "Студент не найден в списке" << endl << endl;
		return -1;
	}
}