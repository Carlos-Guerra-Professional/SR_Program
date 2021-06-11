#pragma once

#include "student.h"

class SecurityStudent : public Student {
public:
	SecurityStudent(string refiD, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[], Degree refDegree); // Overloaded Constructor
	~SecurityStudent(); //Destructor

	// Marked as "VIRTUAL" in Abstract Base Class
	Degree GetDegree();
	void Print();

private:
	Degree degree;
};
