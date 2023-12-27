#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream input ("input.txt", ios::in);
    string line;
    int calibration=0;
    string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (getline (input, line)) {
        int sum;
        int first;
        int last;
        vector<int> indices;
        for (int i = 0; i < line.length(); i++) {
            if (line.at(i) - '0' > 0 && line.at(i)-'0' < 10) {
                indices.push_back(i);
            }
            for (string num : digits) {
                if (line.substr(i,i+3).find(num)==0) indices.push_back(i);
                else if (line.substr(i, i+4).find(num)==0) indices.push_back(i);
                else if (line.substr(i, i+5).find(num)==0) indices.push_back(i);
            }
        }
        int findex = indices.at(0);
        int lindex = indices.at(indices.size()-1);

        if (line.at(findex) - '0' > 0 && line.at(findex)-'0' < 10) {
            first = line.at(findex) - '0';
        }
        else {
            for (int i = 1; i<10; i++) {
                string digit = digits[i-1];
                if (line.substr(findex, findex+3).find(digit)==0) first = i;
                else if (line.substr(findex, findex+4).find(digit)==0) first = i;
                else if (line.substr(findex, findex+5).find(digit)==0) first = i;
            }
        }
        if (line.at(lindex) - '0' > 0 && line.at(lindex)-'0' < 10) {
            last = line.at(lindex) - '0';
        }
        else {
            for (int i = 1; i<10; i++) {
                string digit = digits[i-1];
                if (line.substr(lindex, lindex+3).find(digit)==0) last = i;
                else if (line.substr(lindex, lindex+4).find(digit)==0) last = i;
                else if (line.substr(lindex, lindex+5).find(digit)==0) last = i;
            }
        }
        sum = 10*first + last;
        calibration+=sum;
    }
    cout << calibration;
}