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
	// All the functions in the menu will simply be reading the data
	students[count++] = s1;
	students[count++] = s2;
	students[count++] = s3;
	students[count++] = s4;
	students[count++] = s5;

	// If I needed to modify the students data, like adding bonus points to their grades like previous assignments , then I would need to use pointers to modify the data in place.
	// I would have to create the array like this:
	// Student* students[MAX_STUDENTS];
	// Then I would need every student added to be a reference to the original struct, like this:
	// students[count++] = &s1;
	// students[count++] = &s2;
	// etc...
	// This way if I modify the data in the array I would be modifying the original struct data
	// Then when I call the functions in the menu, I would have to dereference the pointer to access the data, like this:
	// (*students[i]).studentGrades in my functions instead of students[i].studentGrades


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
	// I also hold the index of the student with the highest grade, so I can print out their name and id later
	int highestIndex = 0;

	// Then I loop through the students to find the highest grade
	// I start at the 1st index because highest is set to the grade at the 0th index
	for (int i = 1; i < count; i++) {
		// If the current student's grade is higher than the highest
		if (students[i].studentGrades > highest) {
			// Then I update the highest grade
			highest = students[i].studentGrades;
			// I also update the index of the student with the highest grade
			highestIndex = i;
		}
	}
	// After the loop, I can print out the highest grade and the student information
	cout << students[highestIndex].studentName << " (ID: " << students[highestIndex].studentId << ") has the highest grade: " << highest << "\n";
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
	// I hold the index of the student with the lowest grade
	int lowestIndex = 0;

	// Then I loop through the students to find the lowest grade
	for (int i = 1; i < count; i++) {
		// If the current student's grade is lower than the lowest
		if (students[i].studentGrades < lowest) {
			// Then I update the lowest grade
			lowest = students[i].studentGrades;
			// I also update the index of the student with the lowest grade
			lowestIndex = i;
		}
	}
	// After the loop, I can print out the lowest grade and the student information
	cout << students[lowestIndex].studentName << " (ID: " << students[lowestIndex].studentId << ") has the lowest grade: " << lowest << "\n";
}

void averageGrade(Student students[], int count)
{
	// Check to see if there are any students in the record
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	// TODO: Print out the average grade of the students
	// First I initialize a variable to hold the sum of the grades
	float sum = 0.0;
	// Then I loop through the students to calculate the sum of the grades
	for (int i = 0; i < count; i++) {
		sum += students[i].studentGrades;
	}

	// After the loop, I can calculate the average by dividing the sum by the count of students
	float average = sum / count;

	// Finally, I print out the average grade
	cout << fixed << setprecision(2); // Set the precision to 2 decimal places
	cout << "The average grade in the class is: " << average << "\n";


}
void printStudentId(Student students[], int count)
{
	// Check to see if there are any students in the record
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	// TODO: Print out all the students id in the array
	cout << "Student IDs:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentId << "\n";
	}
}
void printStudentName(Student students[], int count)
{
	// Check to see if there are any students in the record
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	// TODO: Print out all the students name in the array
	cout << "Student Names:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentName << "\n";
	}
}