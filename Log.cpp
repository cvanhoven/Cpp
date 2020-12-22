#include <iostream>
#include <string>
using namespace std;

// I wrote this code, and have tested it. It runs as needed.

// Calculate the correct Answer
int CalcAns(int num, string var) {
    int comp_answer = 0;
    // Calculate for variable
    if (var == "K") {
        comp_answer += 10;
    }
    else if (var == "M") {
        comp_answer += 20;
    }
    else if (var == "G") {
        comp_answer += 30;
    }
    else if (var == "T") {
        comp_answer += 40;
    }

    // Calcualte for the number
    if (num == 2) {
        comp_answer += 1;
    }
    else if (num == 4) {
        comp_answer += 2;
    }
    else if (num == 8) {
        comp_answer += 3;
    }
    else if (num == 16) {
        comp_answer += 4;
    }
    else if (num == 32) {
        comp_answer += 5;
    }
    else if (num == 64) {
        comp_answer += 6;
    }
    else if (num == 128) {
        comp_answer += 7;
    }
    else if (num == 256) {
        comp_answer += 8;
    }
    else if (num == 512) {
        comp_answer += 9;
    }
    
    return comp_answer;
}

int main() {
    int numlist[10] = {1,2,4,8,16,32,64,128,256,512};
    string varlist[5] = {"none", "K", "M", "G", "T"};
    int num;
    string var;
    int streak = 0;

    while (streak < 4) {
        int their_answer = 0;
        int answer = 0;
        num = numlist[rand() % 10];
        var = varlist[rand() % 5];
// Ask for their answer to randomly generated question
        if (var == "none") {
            cout << "Please enter the answer to the following question: " 
            << "log" << num << endl << endl;
        }
        else {
            cout << "Please enter the answer to the following question: " 
            << "log" << num << var << endl << endl;
        }

        cin >> their_answer;

        answer = CalcAns(num, var);

// Test whether they got it correct or not
        if (their_answer == answer) {
            streak +=1;
            cout << "Good job. Your streak is now " << streak << endl;
        }
        else {
            cout << "Sad day. The correct answer was "  << answer << "." << endl << endl;
            streak = 0;
        }
    }
// End
    cout << "Congratulations! You got 4 in a row!!" << endl;
}