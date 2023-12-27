#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input ("input.txt", ios::in);
    string line;
    int calibration;
    while (getline (input, line)) {
        int sum = 0;
        int i = 0;
        while (line.at(i)<48 || line.at(i) >57) {
            i++;
        }
        int firstDigit = line.at(i) - '0';
        int lastDigit = 0;
        while (i<line.length()) {
            if (line.at(i)>=48 && line.at(i) <=57) {
                lastDigit = line.at(i) - '0';
            }
            i++;
        }
        sum = 10*firstDigit + lastDigit;
        calibration += sum;
    }
    cout << calibration;
    return 0;
}