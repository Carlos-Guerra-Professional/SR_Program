#include <iostream>
using namespace std;

#include "student.h"
#include "securityStudent.h"

SecurityStudent::SecurityStudent(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[numDaysSize], Degree refDegree)
	:Student(refID, refFirstName, refLastName, refEmail, refAge, refDays) {
	degree = Degree::SECURITY;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}

Degree SecurityStudent::GetDegree() {
	return degree;
}

void SecurityStudent::Print() {
	cout << GetID();
	cout << "\t First Name : " << GetFirstName();
	cout << "\t Last Name : " << GetLastName();
	cout << "\t Age : " << GetAge();
	cout << "\t Days In Course : {";
	cout << GetDays()[0] << ", ";
	cout << GetDays()[1] << ", ";
	cout << GetDays()[2] << "} ";
	cout << "\t Degree Program : " << "SECURITY \n";
}