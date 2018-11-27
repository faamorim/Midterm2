#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "mymap.cpp"
#include "standard_deviation.hpp"
MyMap<string, int> readFile(string fileName);

int main() {
    string fileName = "studentMarks.txt";
    MyMap<> mymap = readFile(fileName);



    cout << mymap << endl;
    vector<int> grades = mymap.getValues();
    cout << "Standard Deviation: " << standardDeviation(grades.begin(), grades.end()) << endl;

    cout << endl;
    auto fifthElement = mymap[5];
    cout << "5th element: " << fifthElement.first << ": " << fifthElement.second << endl;

    cout << endl;
    auto wiggim = mymap["Wiggim"];
    cout << "Wiggim: " << wiggim.first << ": " << wiggim.second << endl;

    return 0;
}

MyMap<string, int> readFile(const string& fileName){
    MyMap<> mymap;
    ifstream file{fileName, ios_base::in};
    if(!file.is_open()) {
        cout << "Unable to open file " << fileName << endl;
    } else{
        string line;
        while(getline(file, line)){
            string name;
            int grade;
            stringstream lineStream;
            lineStream << line;
            lineStream >> name;
            lineStream >> grade;
            mymap.add(name, grade);
        }
        file.close();
        if(file.is_open()) {
            cerr << "Unable to close file after load.";
        }
    }
    return mymap;
}