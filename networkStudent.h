#pragma once

#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent(string refiD, string refFirstName, string refLastName, string refEmail, int refAge, int refDays[], Degree refDegree); // Overloaded Constructor
	~NetworkStudent(); //Destructor

	// Marked as "VIRTUAL" in Abstract Base Class
	Degree GetDegree();
	void Print();

private:
	Degree degree;
};