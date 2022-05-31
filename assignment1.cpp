#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>

using namespace std; 

//global variables 
const int rows = 5; 
const int cols = 5;

//function signatures
void checkPassword();
void convertPhonetic();
void fillMatrix(int matrix[rows][cols]);
void printMatrix(int matrix[rows][cols]);
void multiplyMatrices(int matrix_left[rows][cols], int matrix_right[rows][cols], int matrix_result[rows][cols]);



int main() {
	srand((unsigned) time(0));

	checkPassword(); 
	convertPhonetic();

	int matrix[rows][cols];
	int matrix2[rows][cols];
	int matrix_result[rows][cols];

	fillMatrix(matrix);
	fillMatrix(matrix2);
	printMatrix(matrix);
	multiplyMatrices(matrix, matrix2, matrix_result);
	printMatrix(matrix_result);

	return 0;

}

void checkPassword() {
    //getting the password
	cout << "Please input a password: " << endl; 
	string yourPass;
	cin >> yourPass; 
	
	//checking password requirements
	bool isLength = false;
	bool isChar = true;
	bool isNumb = false;
	bool isSpecial = false;
	
	//checking that password is 8 chars long 
	if (yourPass.size() >= 8) { 
	    isLength = true; 
	}

	//checking if there is at least one number 
	if (yourPass.find_first_of("0123456789") != string::npos) {
	    isNumb = true;
	}

	//checking if password contains at least one of the special characters
	// * , # $
	if (yourPass.find_first_of("*,#$") != string::npos) {
		isSpecial = true;
	}

	//making sure that each char does not occur more than twice 
	for (int i = 0; i < yourPass.size(); i++) {
		int occur = 1;
		int x = yourPass[i];
		for (int j = i + 1; j < yourPass.size(); j++) { 
			if (x == yourPass[j]) {
				occur++;
			}
		}

		if (occur > 2) {
			isChar = false;
		}
	}
    
    //final msg 
    if (isLength && isChar && isNumb && isSpecial) { 
        cout << "The password has been accepted " << endl;
    } else {
    	cout << "Password not accepted: " << endl;
    }
    //if the password is not accepted.. reasons why 
    if (!isChar) {
    	cout << "A character cannot be repeated more than twice. " << endl;
    }
    if (!isLength) {
    	cout << "Your password must be at least 8 characters. " << endl;
    }
    if (!isNumb) {
    	cout << "Your password must include at least one number. " << endl;
    }
    if (!isSpecial) {
    	cout << "Your password must include at least one of the following special characters: * , # $ " << endl;
    }

    cout << endl;
}

void convertPhonetic() { 
	//getting the input word
	cout << "Please enter a word:" << endl;
	string yourWord;
	cin >> yourWord;

	//looping through the string to print phonetic
	for (int i = 0; i < yourWord.size(); i++ ) { 
		if (tolower(yourWord[i]) == 'a') {
			cout << "Alfa ";
		}
		if (tolower(yourWord[i]) == 'b') {
			cout << "Bravo ";
		}
		if (tolower(yourWord[i]) == 'c') {
			cout << "Charlie ";
		}
		if (tolower(yourWord[i]) == 'd') {
			cout << "Delta ";
		}
		if (tolower(yourWord[i]) == 'e') {
			cout << "Echo ";
		}
		if (tolower(yourWord[i]) == 'f') {
			cout << "Foxtrot ";
		}
		if (tolower(yourWord[i]) == 'g') {
			cout << "Golf ";
		}
		if (tolower(yourWord[i]) == 'h') {
			cout << "Hotel ";
		}
		if (tolower(yourWord[i]) == 'i') {
			cout << "India ";
		}
		if (tolower(yourWord[i]) == 'j') {
			cout << "Juliett ";
		}
		if (tolower(yourWord[i]) == 'k') {
			cout << "Kilo ";
		}
		if (tolower(yourWord[i]) == 'l') {
			cout << "Lima ";
		}
		if (tolower(yourWord[i]) == 'm') {
			cout << "Mike ";
		}
		if (tolower(yourWord[i]) == 'n') {
			cout << "November ";
		}
		if (tolower(yourWord[i]) == 'o') {
			cout << "Oscar ";
		}
		if (tolower(yourWord[i]) == 'p') {
			cout << "Papa ";
		}
		if (tolower(yourWord[i]) == 'q') {
			cout << "Quebec ";
		}
		if (tolower(yourWord[i]) == 'r') {
			cout << "Romeo ";
		}
		if (tolower(yourWord[i]) == 's') {
			cout << "Sierra ";
		}
		if (tolower(yourWord[i]) == 't') {
			cout << "Tango ";
		}
		if (tolower(yourWord[i]) == 'u') {
			cout << "Uniform ";
		}
		if (tolower(yourWord[i]) == 'v') {
			cout << "Victor ";
		}
		if (tolower(yourWord[i]) == 'w') {
			cout << "Whiskey ";
		}
		if (tolower(yourWord[i]) == 'x') {
			cout << "X-ray ";
		}
		if (tolower(yourWord[i]) == 'y') {
			cout << "Yankee ";
		}
		if (tolower(yourWord[i]) == 'z') {
			cout << "Zulu ";
		}
	}
	cout << endl;
}

void fillMatrix(int matrix[rows][cols]) {
	//looping accross each row
	for (int i = 0; i<5; i++) { 
		for (int j = 0; j<5; j++) {
			matrix[i][j] = (rand() % 26);
		}
	}
}

void printMatrix(int matrix[rows][cols]) { 
	//looping through matrix to print out values
	for (int i = 0; i<5; i++) { 
		for (int j = 0; j<5; j++) {
			if (j == 4) {
				cout << "  " << matrix[i][j] << " " << endl;
			} else if (matrix[i][j] > 9 && matrix[i][j] < 100) {
				cout << "  " << matrix[i][j] << "  |";
			} else if (matrix[i][j] > 99) {
				cout << "  " << matrix[i][j] << " |";
			}
			else { 
				cout << "  " << matrix[i][j] << "   |";
			}
		}
		cout << "----------------------------------" << endl;
	}
	cout << endl;
}

void multiplyMatrices(int matrix_left[rows][cols], int matrix_right[rows][cols], int matrix_result[rows][cols]) {
	//initializing i and j as static so that the value doesn't reset w/ every function call
	static int i = 0; 
	static int j = 0; 

	//getting the product of the two matrices
	int prod = matrix_left[i][j] * matrix_right[i][j];
	matrix_result[i][j] = prod;
	//increments j while i remains the same until we reach the end of the row
	j++;

	if (j < 5) {
		multiplyMatrices(matrix_left, matrix_right, matrix_result);
	}
	//reached the end of the row therefore need to reset j and increment i to move to next row 
	if (j == 5 && i < 5) { 
		j = 0; 
		i++;
		multiplyMatrices(matrix_left, matrix_right, matrix_result);
	}
}

















