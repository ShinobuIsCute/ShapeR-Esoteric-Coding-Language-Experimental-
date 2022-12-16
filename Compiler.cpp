#include <iostream>
#include <fstream>
#include <string>
using namespace std; // Just makes it so you don't need std::

int main() {
        int counter = -1; //Global count variable
        string fileName; //Take filename from terminal, can make it so it's just a set string if needed
        string test;
        cout << "Enter Filename:";
        cin >> fileName;

        ifstream originalFile; //I think ifstream is for reading, and ofstream is for writing
        originalFile.open(fileName); // Original File is the input
        ofstream compiled; // Converted program will be written here
        
        test = originalFile.get();
        cout << test;

        return 0;
}