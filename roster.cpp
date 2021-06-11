#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;


Roster::Roster() {
	this->lastIndex = -1;
}

Roster::Roster(int maxSize) {
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
	return;
}

Student* Roster::GetStudentID(int index) {
	return classRosterArray[index];

}

void Roster::ParseThenAdd(string row) {
	if (lastIndex < 5) {
		lastIndex++;

		Degree degree = NETWORK;

		int rhs = row.find(",");
		string refID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string refFirstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string refLastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string refEmail = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int refAge = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int refDays1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int refDays2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int refDays3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lastString = row.substr(lhs, rhs - lhs);

		if (lastString == "NETWORK") {
			degree = NETWORK;
		}

		if (lastString == "SECURITY") {
			degree = SECURITY;
		}

		if (lastString == "SOFTWARE") {
			degree = SOFTWARE;
		}

		Add(refID, refFirstName, refLastName, refEmail, refAge, refDays1, refDays2, refDays3, degree);

		


	}
}

void Roster::Add(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays1, int refDays2, int refDays3, Degree refDegree ) {
	int refDays[Student::numDaysSize];
	refDays[0] = refDays1;
	refDays[1] = refDays2;
	refDays[2] = refDays3;
	if (refDegree == NETWORK) {
		classRosterArray[lastIndex] = new NetworkStudent(refID, refFirstName, refLastName, refEmail, refAge, refDays, refDegree);
	}
	if (refDegree == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(refID, refFirstName, refLastName, refEmail, refAge, refDays, refDegree);
	}
	if (refDegree == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(refID, refFirstName, refLastName, refEmail, refAge, refDays, refDegree);
	}
}

void Roster::Remove(string refID) {
	bool removed = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (refID == classRosterArray[i]->GetID()) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				removed = true;
				cout << "Student with ID number " << refID << " has been successfully removed. \n";
				break;
			}
		}
	}
	if (!removed) {
		cout << "Student with ID number " << refID << " not found. \n";
	}

}

void Roster::PrintAll() {
	for (int i = 0; i < 5; ++i) {
		(this->classRosterArray)[i]->Print();
	}
}

void Roster::PrintAverageDays(string refID) {
	for (int i = 0; i < 5; ++i) {
		double averageDays = 0.0;
		if (classRosterArray[i]->GetID() == refID) {
			cout << "Average for student " << refID << " is: ";
			averageDays = (classRosterArray[i]->GetDays()[0] + classRosterArray[i]->GetDays()[1] + classRosterArray[i]->GetDays()[2]) / (3.0);
			cout << averageDays << endl;
		}
	}
}

void Roster::PrintInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		bool hasAt = false;
		bool hasPeriod = false;
		bool hasSpace = false;
		string emailAddress = classRosterArray[i]->GetEmail();
		for (char& c : emailAddress) {
			if (c == '@') {
				hasAt = true;
			}
			if (c == '.') {
				hasPeriod = true;
			}
			if (c == ' ') {
				hasSpace = true;
			}
		}
		if (hasAt == false || hasPeriod == false || hasSpace == true) {
			cout << emailAddress << "\n";
		}
	}
}

void Roster::PrintByDegree(Degree refDegree) {
	for (int i = 0; i < 5; ++i) {
		if (this->classRosterArray[i]->GetDegree() == refDegree) {
			this->classRosterArray[i]->Print();
		}
	}
}



int main() {
	cout << "Course Title: C867 Scripting and Programming - Applications, Programming Language: C++, Student ID: #000227252, Student Name: Carlos Guerra \n";
	cout << endl;
	cout << endl;

	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Carlos,Guerra,cguerr2@wgu.edu,24,10,11,12,SOFTWARE"
	};

	Roster classRoster;

	cout << "Parsing data and adding students: \n";
		for (int i = 0; i < 5; i++) {
		classRoster.ParseThenAdd(studentData[i]);
	}
	cout << "Done.\n";
	cout << endl;
	cout << endl;

	cout << "Displaying all students: \n";
	classRoster.PrintAll();
	cout << endl;
	cout << endl;

	cout << "The following emails are invalid: \n";
	classRoster.PrintInvalidEmails();
	cout << endl;
	cout << endl;

	cout << "Printing Average Days for Courses: \n";
	for (int i = 0; i < 5; ++i) {
		classRoster.PrintAverageDays(classRoster.GetStudentID(i)->GetID());
	}
	cout << endl;
	cout << endl;	

	cout << "Printing out student data by degree program... \n";
	classRoster.PrintByDegree(SOFTWARE);
	cout << endl;
	cout << endl;

	cout << "Removing student: \n";
	classRoster.Remove("A3");
	cout << endl;
	cout << endl;

	cout << "Removing student again: \n";
	classRoster.Remove("A3");
	cout << endl;
	cout << endl;

	//classRoster.~Roster();

	return 0;
	
}
