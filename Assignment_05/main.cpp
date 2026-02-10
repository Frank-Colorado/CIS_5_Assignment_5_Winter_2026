#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

/*!
* Function Prototypes
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
	Student students[MAX_STUDENTS];
	int count = 0;  // this keeps track of the students that are in the class
	int choice;     // user input

	/*!
	* Add the students here!
	*/
	//----------------------------------------------------------------------------------------
	Student s1 = { 1001, "Alice", 85.5 };
	Student s2 = { 1002, "Bob", 92.0 };
	Student s3 = { 1003, "Charlie", 78.0 };
	Student s4 = { 1004, "David", 88.5 };
	Student s5 = { 1005, "Eve", 91.0 };

	// Add students to the array
	// Since I won't be modifying any of the students data, I can just copy the struct into the array.
	students[count++] = s1;
	students[count++] = s2;
	students[count++] = s3;
	students[count++] = s4;
	students[count++] = s5;

	//----------------------------------------------------------------------------------------

	// Complete the menu with the associated function
	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();  // we add this to consume the leftover newline

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}

/* TODO: Implement these functions */

// Remeber, if you pass an array into a function, it is a pass by reference!
// Because arrays decay to pointers, so you are getting a pointer to the first element
// which allows you to modify the data. 

void highestGrade(Student students[], int count)
{
	// TODO: Print out all the highest grade in the array
	// Here is a simple check to ensure your code does not break
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	// First I set the highest grade to the first student's grade
	float highest = students[0].studentGrades;

	// Then I loop through the students to find the highest grade
	// I start at the 1st index because highest is set to the grade at the 0th index
	for (int i = 1; i < count; i++) {
		// If the current student's grade is higher than the highest
		if (students[i].studentGrades > highest) {
			// Then I update the highest grade
			highest = students[i].studentGrades;
		}
	}
}
void lowestGrade(Student students[], int count)
{
	// Check to see if there are any students in the record
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	// TODO: Print out all the lowest grade in the array
	// First I set the lowest grade to the first student's grade
	float lowest = students[0].studentGrades;

	// Then I loop through the students to find the lowest grade
	for (int i = 1; i < count; i++) {
		// If the current student's grade is lower than the lowest
		if (students[i].studentGrades < lowest) {
			// Then I update the lowest grade
			lowest = students[i].studentGrades;
		}
	}
}

void averageGrade(Student students[], int count)
{
	// TODO: Print out the average grade of the students
}
void printStudentId(Student students[], int count)
{
	// TODO: Print out all the students id in the array
}
void printStudentName(Student students[], int count)
{
	// TODO: Print out all the students name in the array
}