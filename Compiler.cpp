#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std; // Just makes it so you don't need std::

int* shape_finder(string* text);
int count_char_in_line(string line);
int check_rhombus(string* text, int start);

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