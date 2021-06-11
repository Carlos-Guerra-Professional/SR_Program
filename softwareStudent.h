#pragma once

#include "student.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent(string refiD, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[], Degree refDegree); // Overloaded Constructor
	~SoftwareStudent(); //Destructor

	// Marked as "VIRTUAL" in Abstract Base Class
	Degree GetDegree();
	void Print();

private:
	Degree degree;
};