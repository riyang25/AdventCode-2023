#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int parseComma(string s, int index) {
    //returns string containing characters from start index to comma or end of string
    int i = index;
    while (i < s.length() && !(s.at(i) == ',' || s.at(i) == ';')) {i++;}
    return i-index;
}
int main() {
    ifstream input ("input.txt", ios::in);
    string line;
    int totalpower;
    while(getline(input, line)) {
        int power;
        int start = line.find(":", 0);
        int maxred=0;
        int maxgreen=0;
        int maxblue=0;
        while (start < line.length()) {
            string data = line.substr(start + 1, parseComma(line, start+1));
            stringstream info(data);
            int num;
            string color;
            info >> num >> color;
            if(color=="blue") {if(num>maxblue) maxblue = num;}
            if(color=="green") {if (num>maxgreen) maxgreen=num;}
            if(color=="red") {if (num>maxred) maxred = num;}
            start+=data.length() + 1;
        }
        power = maxblue * maxgreen * maxred;
        totalpower+=power;
    }
    std::cout << totalpower;
}