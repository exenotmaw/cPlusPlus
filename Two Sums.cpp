#include <iostream>

using namespace std;

struct userInput {
	int numberArray = 0;
	int arrayList[99] = {};
	int sumNumber = 0;
	int temp = 0;
	int givenNumber = 0;
};

userInput input;


int main() {

	cout << "Insert Number of array: ";
	cin >> input.numberArray;
	cin.ignore();

	cout << endl;

	for (int i = 0; i < input.numberArray; i++) {
		cout << "Enter the value of array number " << i + 1 << ": ";
		cin >> input.arrayList[i];
		cin.ignore();
	}

	cout << "Insert Number to find the sum in the list: ";
	cin >> input.givenNumber;
	cin.ignore();

	cout << endl << "list that equal to sum:" << endl;

	for (int i = 0; i < input.numberArray; i++) {
		for (int j = 0; j < input.numberArray; j++) {
			input.sumNumber = input.arrayList[i] + input.arrayList[j];
			if (input.sumNumber == input.givenNumber) {
				cout << input.arrayList[i] << " + " << input.arrayList[j] << " = " << input.sumNumber << endl;
			}

			input.sumNumber = 0;
		}
	}
	
	cout << endl << "list that not equal to sum:" << endl;

	for (int i = 0; i < input.numberArray; i++) {
		for (int j = 0; j < input.numberArray; j++) {
			input.sumNumber = input.arrayList[i] + input.arrayList[j];
			if (input.sumNumber != input.givenNumber) {
				cout << input.arrayList[i] << " + " << input.arrayList[j] << " = " << input.sumNumber << endl;
			}
			input.sumNumber = 0;
		}
	}
}