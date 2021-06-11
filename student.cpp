#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "student.h"

Student::Student(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[]) {
	this->iD = refID;
	this->firstName = refFirstName;
	this->lastName = refLastName;
	this->email = refEmail;
	this->age = refAge;
	for (int i = 0; i < numDaysSize; ++i) {
		this->days[i] = refDays[i];
	}
}

Student::~Student() {}

//Setters

void Student::SetID(string studentID) {
	this->iD = studentID;
	return;
}

void Student::SetFirstName(string nameFirst) {
	this->firstName = nameFirst;
	return;
}

void Student::SetLastName(string nameLast) {
	this->lastName = nameLast;
	return;
}

void Student::SetEmail(string emailAddress) {
	this->email = emailAddress;
	return;
}

void Student::SetAge(int studentAge) {
	this->age = studentAge;
	return;
}

void Student::SetDays(int numDays[]) {
	for (int i = 0; i < numDaysSize; ++i) {
		this->days[i] = numDays[i];
	}
	return;
}

//Getters

string Student::GetID() const {
	return iD;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int *Student::GetDays() {
	return days;
}