#pragma once


#include <array>
#include <vector>

#include "student.h"

class Roster {
public:
	Roster();  //Constructor
	Roster(int maxSize);
	~Roster();  //Virtual Destructor

	Student* GetStudentID(int index);

	void ParseThenAdd(string row);

	void Add(string refID, string refFirstName, string refLastName, string refEmail, int refAge, int refDays1, int refDays2, int refDays3, Degree refDegree);

	void Remove(string refID);

	void PrintAll();

	void PrintAverageDays(string refID);

	void PrintInvalidEmails();

	void PrintByDegree(Degree refDegree);

private:

	Student* classRosterArray[5];
	int lastIndex;
	//int maxSize;
};