#pragma once

#include <string>
using namespace std;

#include "degree.h"

class Student {
public:
	const static int numDaysSize = 3;

private:
	string iD;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[numDaysSize];

public:
	Student(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[]); // Overloaded Constructor
	~Student(); //Destructor

	//Mutators (i.e., Setters)
	void SetID(string studentID);
	void SetFirstName(string nameFirst);
	void SetLastName(string nameLast);
	void SetEmail(string emailAddress);
	void SetAge(int studentAge);
	void SetDays(int numDays[]);

	//Accessors (i.e., Getters)
	string GetID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int  GetAge() const;
	int* GetDays();
	virtual Degree GetDegree() = 0;

	virtual void Print() = 0;




};