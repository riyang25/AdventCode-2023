#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct part {
    int value;
    int linenum;
    vector<int> indices;
    bool symbol;
};

int main() {
    ifstream input("input.txt", ios::in);
    string line;
    vector<string> engine;
    int partsum;
    //convert input text into array of strings
    while(getline(input, line)) {
        engine.push_back(line);
    }
    int lines = engine.size();
    int length = engine.at(0).length();
    int hits[lines][length];
    vector<part> parts;
    //create map of where symbols and nums are
    for (int i = 0; i<lines; i++) {
        line = engine.at(i);
        for (int j = 0; j< length; j++) {
            /* hits[i][j] = 1;
            cout << hits[i][j];
            */
            if (line.at(j) == '.') {hits[i][j] = 0;}
            else if (line.at(j) - '0' + 1 > 0 && line.at(j) - '0' < 10) {hits[i][j]=2;}
            else {hits[i][j] = 1;}
        }
    }
    //store nums
    for (int i = 0; i<lines; i++) {
        int j = 0;
        while(j < length){
            while (hits[i][j] != 2 && j<length) {
                j++;
            }
            if (j!=length) {
                part mech;
                int num = engine.at(i).at(j) - '0';
                mech.linenum = i;
                mech.indices.push_back(j);
                int k = j + 1;
                while (hits[i][k] == 2) {
                    num *= 10;
                    num += engine.at(i).at(k) - '0';
                    mech.indices.push_back(k);
                    k++;
                }
                mech.value = num;
                parts.push_back(mech);
                j = k;
            }
        }
    }
    // find valid parts
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < length; j++) {
            if (hits[i][j] == 1) {
                for (int k = 0; k < parts.size(); k++) {
                    if (abs(parts.at(k).linenum - i) < 2) {
                        for (int index : parts.at(k).indices) {
                            if (abs(index - j) < 2) parts.at(k).symbol = true;
                        }
                    }
                }
            }
        }
    }
    for (part mech: parts) {
        if(mech.symbol) {
            partsum+=mech.value;
        }
    }
    cout << partsum;
}