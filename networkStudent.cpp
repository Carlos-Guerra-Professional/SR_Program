#include <iostream>
using namespace std;

#include "student.h"
#include "networkStudent.h"

NetworkStudent::NetworkStudent(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[], Degree refDegree)
	:Student(refID, refFirstName, refLastName,refEmail, refAge, refDays) {
	degree = Degree::NETWORK;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}

Degree NetworkStudent::GetDegree() {
	return degree;
}

void NetworkStudent::Print() {
	cout << GetID();
	cout << "\t First Name : " << GetFirstName();
	cout << "\t Last Name : " << GetLastName();
	cout << "\t Age : " << GetAge();
	cout << "\t Days In Course : {";
	cout << GetDays()[0] << ", ";
	cout << GetDays()[1] << ", ";
	cout << GetDays()[2] << "} ";
	cout << "\t Degree Program : " << "NETWORK \n";
}