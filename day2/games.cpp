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
    int idsum;
    const int RED = 12;
    const int GREEN = 13;
    const int BLUE = 14;
    while(getline(input, line)) {
        int game;
        int start = line.find(":", 0);
        game = stoi(line.substr(5, start));
        bool valid = 1;
        while (start < line.length() && valid) {
            string data = line.substr(start + 1, parseComma(line, start+1));
            stringstream info(data);
            int num;
            string color;
            info >> num >> color;
            if(color=="blue") {if(num>BLUE) valid = 0;}
            if(color=="green") {if (num>GREEN) valid = 0;}
            if(color=="red") {if (num>RED) valid = 0;}
            start+=data.length() + 1;
        }
        if (valid) idsum+= game;
    }
    std::cout << idsum;
}