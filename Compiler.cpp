#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std; // Just makes it so you don't need std::

int* shape_finder(string* text);
int count_char_in_line(string line);
int check_rhombus(string* text, int start);

int main() {
        int counter = 0; //Will first use to count amount of lines in input file
        int num_char_in_file = 0;
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
                ++counter;
        }
        char** ShapeArray = (char**) malloc(num_char_in_file * sizeof(char)); //Counter = number of lines in program
        int* array_to_return = (int*) malloc(sizeof(int));
        originalFile.close();
        originalFile.open(fileName);
        counter = 0; //Will use counter as ShapeArray indices
        
        while(!originalFile.eof()) { //Shape Array is initialized after this
                //getline(originalFile, ShapeArray[counter]);
                ++counter;
        }

        counter = -1; //Now, counter will be used for the compiler itself.

        originalFile.close();

        int ShapeOrder[10]; //Placeholder ShapeOrder array here

        //Manager function here
        for(int index = 0; index < sizeof(ShapeOrder); index++) {
                switch(ShapeOrder[index]) {
                        case 0: //Square / rectangle
                                break;
                        case 1: //triangle in clockwise order
                                break;
                        case 2:
                                break;
                        case 3:
                                break;
                        case 4:
                                break;
                        case 5: // two trapeziums, up and down
                                break;
                        case 6: // 
                                break;
                        case 7: // Rhombus
                                break;
                        case 8: // Special rhombus
                                break;
                        default:
                                cout << "What?\n";
                }
        }

        return 0;
}

int count_char_in_line(string line) {
        int char_counter = sizeof(line);
        for (int i = 0; i < sizeof(line); ++i) {
                if ((line[i] == ' ') || line[i] == '~') {
                        --char_counter;
                }
        }
        return char_counter;
}

int check_rhombus(string* text, int start) {
        int i, j = 0;
        int checker = 1;
        if (text[0][0] == ' ') {
                return 0;
        }
        while (count_char_in_line(text[start+j]) != 0) {
                ++j;
        }
        --j;
        while (i != j) {
                if (sizeof(text[start+i]) == sizeof(text[start+j])) {
                        continue;
                } else {
                        checker = 0;
                        break;
                }
        }
        return checker;
}

int* shape_finder(string* text) {

        int i = 0;
        int array_size = 0;
        int* array_to_return = (int*) malloc(sizeof(int));
        

        while (text[i] != "\u001a") {
                
                if (i == 0) {
                        if (count_char_in_line(text[i]) == 0) {
                        ++i;
                        }
                } else {
                        while (count_char_in_line(text[i]) != 0) {
                                ++i;
                        }
                }
                 
                if (count_char_in_line(text[i]) == 1) {
                        if (check_rhombus(text, i) == 1) {
                                //place 7 in array and then continue the loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 7;
                                continue;
                        }
                
                        int j = i;
                        while (count_char_in_line(text[j]) != 0) {
                                ++j;
                        }
                        --j;
                        if (count_char_in_line(text[j]) != 1) {
                                // place 1 in array and then continue the loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 1;
                                continue;
                        }
                        if (text[j][0] == ' ') {
                                // place 4 in array and then continue loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 4;
                                continue;
                        } else {
                                // place 2 in array and then continue loop 
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 2;
                                continue;
                        }
                } else {
                        int j = i;
                        while (count_char_in_line(text[j]) != 0) {
                                ++j;
                        }
                        --j;
                        if (count_char_in_line(text[j]) == 1) {
                                // place 3 in array and then continnue loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 3;
                                continue;
                        } else if (count_char_in_line(text[i]) == count_char_in_line(text[j])) {
                                // place 0 in array and then continue loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 0;
                                continue;
                        } else if (count_char_in_line(text[i]) < count_char_in_line(text[j])) {
                                // place 5 in array and then continue loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 5;
                                continue;
                        } else if (count_char_in_line(text[i]) > count_char_in_line(text[j])) {
                                // place 6 in array and then continue loop
                                ++array_size;
                                (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 6;
                                continue;
                        }
                }
        }
        return array_to_return;
}