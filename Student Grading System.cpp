#include <iostream>
#include<string>

using namespace std;

struct students {
	int count = 0;
	int tempCount = 0;

	int tempNumber = 0;
	int rollNumber[50] = {};

	string studentName[50] = {};
	string tempName = "";

	int studentMarks[50][250] = {};
	int tempMarks = 0;
	double marks = 0;
	double average = 0;
	
};

students student;

bool check(int roll, int count) {
	for (int i = 0; i < count; i++) {
		if (roll == student.rollNumber[i]) {
			return true;
		}
	}
	return false;
}

void studentData(){
	system("cls");
	cout << "--- Entering Data for Student " << student.count + 1 << " ---" << endl;
	cout << endl << "Enter student name: ";
	getline(cin, student.tempName);
	cout << endl << "Enter roll nummber: ";
	cin >> student.tempNumber;
	cin.ignore();

	if (check(student.tempNumber, student.count)) {
		cout << endl << "Roll Number Already Exist" << endl << endl;
	}
	else {
		student.studentName[student.count] = student.tempName;
		student.rollNumber[student.count] = student.tempNumber;
		for(int i = 0; i < 5; i++) {
			do{
				cout << endl << "Enter marks for subject " << i + 1 << " (0 - 100): ";
				cin >> student.tempMarks;
				cin.ignore();
				if (student.tempMarks >= 0 && student.tempMarks <= 100) {
					student.studentMarks[student.count][i] = student.tempMarks;
					student.tempCount++;
				}
				else {
					cout << endl << "Invalid grade" << endl;
				}
			}while (student.tempMarks > 100 || student.tempMarks < 0);
		}
		student.count++;
	}
		
}

void remarks(double range) {
	if (range >= 90) {
		cout << "Remarks: Excellent" << endl;
	}
	else if (range >= 75 && range <= 89) {
		cout << "Remarks: Very Good" << endl;
	}
	else if (range >= 50 && range <= 74) {
		cout << "Remarks: Passed" << endl;
	}
	else{
		cout << "Remarks: Failed" << endl;
	}
}

void studentRecord() {
	system("cls");
	cout << "--- Student Reocrds ---" << endl;
	for (int i = 0; i < student.count; i++) {
		cout << "Name: " << student.studentName[i] << endl;
		cout << "Roll Number: " << student.rollNumber[i] << endl;
		cout << "Marks: " ;
		for (int j = 0; j < 5; j++) {
			cout << student.studentMarks[i][j] << " ";
		}
		student.marks = 0;
		for (int j = 0; j < 5; j++) {
			student.marks = student.marks + student.studentMarks[i][j];
		}
		student.average = 0;
		student.average = student.marks / 5;
		cout << endl << "Average: " << student.average << endl;
		remarks(student.average);
		cout << endl;
	}

}


int main()
{
	int choice = 0;


	do {
		system("cls");
		cout << "===== Student Grading System =====" << endl;
		cout << endl << "1. Add Students Record" << endl;
		cout << endl << "2. View all Students Records" << endl;
		cout << endl << "3. Exit" << endl;
		cout << endl << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice) {
		case 1:
			studentData();
			break;
		case 2:
			studentRecord();
			break;
		case 3:
			return 0;
			break;
		default:
			cout << endl << "Invalid Input" << endl;
			break;
		}
		 
		system("pause");
	} while (choice != 3);
}