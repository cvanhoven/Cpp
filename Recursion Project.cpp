#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Recursive function
int Fib(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return (Fib(n - 2) + Fib(n - 1));
	}
}

// Non-Recursive function
int fib(int n) {
	int current = 1;
	int prev = 0;
	int temp = current;
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		while (n > 1) {
			current += prev;
			prev = temp;
			temp = current;
			n -= 1;
		}
		return current;
	}
}


int main() {
	string file;
	string line;
	cout << "Please enter the file you wish to use." << endl;
	cin >> file;
	ifstream myfile;
	myfile.open(file);

	if (myfile.is_open()) {
		cout << "Recusive" << endl << endl;
		while (getline(myfile, line)) {
			cout << line << "   ";
			line = stoi(line);
			cout << Fib(line) << endl;
		}
		cout << endl << "Non Recursive" << endl << endl;
		while (getline(myfile, line)) {
			cout << line << "   ";
			line = stoi(line);
			cout << fib(line) << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "The file was unable to open.";
	}
}