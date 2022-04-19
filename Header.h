#ifndef Header
#define Header

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class student {
	string name;
	int course;
	string direction;
	int scholarship;
public:
	student(string name = "����������", int course = 0, string direction = "����������", int scholarship = 0) {
		this->name = name;
		this->course = course;
		this->direction = direction;
		this->scholarship = scholarship;
	}

	string sgetterName() { return name; }
	void sgetterName(string name) { this->name = name; }

	int sgetterCourse() { return course; }
	void sgetterCourse(int course) { this->course = course; }

	string sgetterDirection() { return direction; }
	void sgetterDirection(string direction) { this->direction = direction; }

	int sgetterScholarship() { return scholarship; }
	void sgetterScholarship(int scholarship) { this->scholarship = scholarship; }

	friend ostream& operator<<(ostream& os, const student& other);
	friend istream& operator>>(istream& is, student& other);

};

ostream& operator<<(ostream& os, const student& other) {
	os << "�������: " << other.name << "\n";
	os << "����: " << other.course << "\n";
	os << "����� �����������: " << other.direction << "\n";
	os << "���������: " << other.scholarship << "\n";
	cout << endl;
	return os;
}

istream& operator>>(istream& is, student& other) {
	cout << "�������� ������� ��������: ";
	is >> other.name;
	cout << "�������� ���� ��������: ";
	is >> other.course;
	cout << "�������� ����� ����������� ��������: ";
	is >> other.direction;
	cout << "�������� ������ ��������� ��������: ";
	is >> other.scholarship;
	cout << endl;

	return is;
}

#endif Header