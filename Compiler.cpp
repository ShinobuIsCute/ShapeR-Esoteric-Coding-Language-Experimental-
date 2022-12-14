#include <iostream>
#include <fstream>
#include <string>
using namespace std; // Just makes it so you don't need std::


int main() {
        int counter = 0; //Will first use to count amount of lines in input file
        string fileName; //Take filename from terminal, can make it so it's just a set string if needed
        string redacted; //Just used to make the line counter work
        cout << "Enter Filename:";
        cin >> fileName;

        ifstream originalFile; // I think ifstream is for reading, and ofstream is for writing
        originalFile.open(fileName); // Original File is the input
        ofstream compiled; // Converted program will be written here
        compiled.open("Compiled.txt"); // File output

        if(originalFile.fail()) {
                cout << "Error! Check your spelling.";
                cin >> fileName;
                return 0;
        }
        
        while(!originalFile.eof()) {
                getline(originalFile, redacted); //just uses a random String variable to make this work
                counter++;
        }
        string ShapeArray[counter]; //Counter = number of lines in program
        originalFile.open(fileName);
        counter = 0; //Will use counter as ShapeArray indices

        while(!originalFile.eof()) { //Shape Array is initialized after this
                getline(originalFile, ShapeArray[counter]);
                counter++;
        }

        counter = -1; //Now, counter will be used for the compiler itself.

        

        return 0;
}