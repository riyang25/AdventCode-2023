#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream input ("input.txt", ios::in);
    string line;
    int calibration=0;
    string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (getline (input, line)) {
        int sum = 0;
        int mindex = line.length();
        int maxdex = -1;
        int mindigit;
        int maxdigit;
        for (int j = 0; j< 9; j++) {
            auto pos = line.find(digits[j]);
            if (pos != string::npos) {
                if (pos < mindex) {
                    mindex = pos; mindigit = j + 1;
                }
            }
        }
        for (int j = 0; j< 9; j++) {
            auto pos = line.find(digits[j]);
            if (pos != string::npos) {
                if (pos + 1 > maxdex + 1) {
                    maxdex = pos; maxdigit = j + 1;
                }
            }
        }

        int i = 0;

        while (i<line.length() && (line.at(i)<48 || line.at(i) >57)) {
            i++;
        }
        int firstDigit;
        i<mindex ? firstDigit = line.at(i) - '0' : firstDigit = mindigit;
        
        int j = line.length()-1;
        while (j + 1 > 0 && (line.at(j)<48 || line.at(j) > 57)) {
            j--;
        }
        int lastDigit;
        if (i == line.length()) lastDigit = maxdigit;
        if (j==i) {
            if (i<mindex) {
                lastDigit = mindigit;
            }
            else lastDigit = line.at(j) - '0';
        }
        else {
            j+1 > maxdex+1 ? lastDigit = line.at(j) - '0' : lastDigit = maxdigit;
        }
        sum = 10*firstDigit + lastDigit;
        calibration += sum;
    }
    cout << calibration;
    return 0;
}