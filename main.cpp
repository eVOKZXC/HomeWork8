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
	cout << "��������� ���������\n\n";

	vector<student> massive;

	while (true) {
		string bufName;
		int userChose = 0;

		cout << "���� ���������\n";
		cout << "1. �������� �������� � ���������: " << endl;
		cout << "2. ������� �������� �� ���������: " << endl;
		cout << "3. ���������� � ��������: " << endl;
		cout << "4. �������� ������ �������� � ���������:  " << endl;
		cout << "5. ����� �� ���������:  " << endl << endl;

		cout << "�������� �������: ";
		cin >> userChose;
		cout << endl;

		switch (userChose)
		{
		case 1:
			cout << "���������� ��������\n";
			massive.push_back(addStudent());
			break;
		case 2:
			cout << "�������� ��������\n";
			cout << "�������� ������� ��������: ";
			cin >> bufName;
			deleteStudent(massive, bufName);
			break;
		case 3:
			cout << "���������� � ��������\n";
			cout << "�������� ������� ��������: ";
			cin >> bufName;
			checkStudent(massive, bufName);
			break;
		case 4:
			cout << "��������� ���������� ��������\n";
			cout << "�������� ������� ��������: ";
			cin >> bufName;
			cout << endl;
			changeStudent(massive, bufName);
			break;
		case 5:
			return 1;
		default:
			cout << "�� ����� �������� �����, ���������.\n\n";
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
			cout << "������� ������ �� ���������" << endl << endl;
			break;
		}
	}
	if (!isFind)
		cout << "������� �� ������ � ������" << endl << endl;
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
		cout << "������� �� ������ � ������" << endl << endl;
}

int changeStudent(vector<student>& massive, string bufName) {
	int findUserFoo = findStudent(massive, bufName);
	int userChose = 0;
	int newCourse = 0;
	int newScholarship = 0;
	string newDirection;
	cout << "���� ��������\n";
	cout << "1. �������� ����: " << endl;
	cout << "2. �������� ����� �����������: " << endl;
	cout << "3. �������� ������ ���������: " << endl;

	cout << "�������� �������: ";
	cin >> userChose;
	cout << endl;
	if (findUserFoo != -1) {
		switch (userChose)
		{
		case 1:
			cout << "������� ����� ���� ��������: ";
			cin >> newCourse;
			cout << endl;
			massive[findUserFoo].sgetterCourse(newCourse);
			break;
		case 2:
			cout << "������� ����� ����������� ��������: ";
			cin >> newCourse;
			cout << endl;
			massive[findUserFoo].sgetterDirection(newDirection);
			break;
		case 3:
			cout << "������� ����� ����������� ��������: ";
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
		cout << "������� �� ������ � ������" << endl << endl;
		return -1;
	}
}