#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <conio.h>
//1,3,5,6 to do now

using namespace std; // Just makes it so you don't need std::

int* shape_finder(string* text, int num_lines);
int count_char_in_line(string line);
int check_rhombus(string* text, int start);

int main() {
        int counter = 0; //Will first use to count amount of lines in input file
        int num_char_in_file = 0;
        int numRows; // Amount of rows in ShapeArray
        int numCols;
        string fileName; //Take filename from terminal, can make it so it's just a set string if needed
        string tempLine; //temporarily stores lines of the txt file
        string redacted; //Just used to make the line counter work
        cout << "Enter Filename: Test.txt\n";
        fileName = "Test.txt";
        //cin >> fileName;
        
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
        numRows = counter;
        string* ShapeArray = static_cast<string*>( malloc((numRows) * sizeof(string))); //Counter = number of lines in program
        originalFile.close(); //reset the file pointer.
        originalFile.open(fileName);
        counter = 0; //Re-using counter as an index for ShapeArray here
        
        while(!originalFile.eof()) { //Store the line
                getline(originalFile, tempLine, '\n');
                new (ShapeArray + counter) string(tempLine);
                counter++;
        }
        printf("Hello there!");
        printf("%d\n WHAT", numRows);
        for(int row = 0; row < numRows; row++) { //print out the Shape Array.
                cout << ShapeArray[row];
                printf("\n");
        }
        cin >> redacted;// Pause to see output
        printf("please work.");  
        counter = -1; //Now, counter will be used for the compiler itself.

        originalFile.close();
        printf("Before ShapeOrder");

        for (int k = 0; k < numRows; k++) {
        cout << ShapeArray[k] << '\n';
        }

        int* ShapeOrder = shape_finder(ShapeArray, 33); //Placeholder ShapeOrder array here

        //Manager function here
        printf("After ShapeOrder");
        for(int index = 0; index < sizeof(ShapeOrder); index++) {
                printf("%d", ShapeOrder[index]);
                switch(ShapeOrder[index]) {
                        case 0: //Square / rectangle
                                break;
                        case 1: //up 
                                break;
                        case 2: //right/output
                                break;
                        case 3: //down relational operations me
                                break;
                        case 4: //left input me
                                break;
                        case 5: // up if statements
                                break;
                        case 6: // down, loops
                                break;
                        case 7: // Rhombus
                                break;
                        case 8: // Special rhombus
                                break;
                        default:
                                cout << "What?\n";
                }
        }
        

        //End of the program, only release resources after this point.
        int getch;
        for (int i = 0; i < 10; i++) {
                (ShapeArray + i)->~string();  // Call the string destructor to clean up the element
        }
        
        printf("HELLO");
        //free(ShapeArray);
        //free(ShapeOrder);
        compiled.close();
        // tested cin >> numCols;
        return 0;
}



int count_char_in_line(string line) {
        int char_counter = line.length();
        for (int i = 0; i < line.length(); i++) {
                if ((line[i] == ' ') || line[i] == '\0') {
                        char_counter = char_counter - 1;
                }
        }
        return char_counter;
}

int check_rhombus(string* text, int start) {
        int i = 0;
        int j = 0;
        
        if (text[start][0] != ' ') {
                return 0;
        }
        while (count_char_in_line(text[start+j]) != 0) {
                ++j;
        }
        --j;

        int x = j/2;
        
        int m = count_char_in_line(text[start+i+1]);
        int n = count_char_in_line(text[start+i]);
        int test = m - n;
        if (test % 2 == 1) {
                return 0;
        }
        i++;

        if (i == x) {
                if (((text[start] == " ~ ") && (text[start+2] == " ~ ")) && (text[start+1] == "~~~")) {
                        return 2;
                } else {
                        return 0;
                }
        }

        for(i; i < x; i++) {
                m = count_char_in_line(text[start+i+1]);
                n = count_char_in_line(text[start+i]);
                int checker = m - n;
                if (test != checker) {
                        return 0;
                }
        }

        for(i; i < j; i++) {
                m = count_char_in_line(text[start+i+1]);
                n = count_char_in_line(text[start+i]);
                int checker = m - n;
                if (test != (checker - 2 * checker)) {
                        return 0;
                }
        }

        return 1;
}

int* shape_finder(string* text, int num_lines) {

        int i = -1;
        int j;
        int array_size = 1;
        int* array_to_return = (int*) malloc(sizeof(int));
        
        while ((i+1) < num_lines) {
                // i represents first line in shape, j represents the last line.
                i++; // go to next line
                while (count_char_in_line(text[i]) == 0) {
                        i++; // go to next line with a character in it
                } 

                j = i; // let j be equal to i
                
                while (count_char_in_line(text[j]) != 0) {
                        j++; 
                }
                j--; // j is now equal to the last line in the shape
                if (count_char_in_line(text[i]) == 1) { // if first line in shape has only 1 character
                        if (check_rhombus(text, i) == 1) { // shape is a normal rhombus
                                //place 7 in array and then continue the loop
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*array_size);
                                array_to_return[array_size-1] = 7;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (check_rhombus(text, i) == 2) { // shape is a special rhombus
                                //place 8 in array and then continue the loop
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 8;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (count_char_in_line(text[j]) != 1) { // shape is upwards facing triangle
                                // place 1 in array and then continue the loop
                                
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 1;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (text[j][0] == ' ') { // shape is a left facing triangle
                                // place 4 in array and then continue loop
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 4;
                                array_size += 1;
                                i = j;
                                continue;
                        } else { // shape is a right facing triangle
                                // place 2 in array and then continue loop                                         
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 2;
                                array_size += 1;
                                i = j;
                                continue;
                        }
                } else {
                        if (count_char_in_line(text[j]) == 1) { // shape is a downwards facing triangle
                                // place 3 in array and then continue loop
                                
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 3;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (count_char_in_line(text[i]) == count_char_in_line(text[j])) { // shape is a rectangle
                                // place 0 in array and then continue loop
                                
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 0;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (count_char_in_line(text[i]) < count_char_in_line(text[j])) { // shape is a upwards facing trapezium
                                // place 5 in array and then continue loop
                                
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 5;
                                array_size += 1;
                                i = j;
                                continue;
                        } else if (count_char_in_line(text[i]) > count_char_in_line(text[j])) { // shape is a downwards facing trapezium
                                // place 6 in array and then continue loop
                                
                                array_to_return = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size));
                                array_to_return[array_size-1] = 6;
                                array_size += 1;
                                i = j;
                                continue;
                        }
                }
        }
        return array_to_return; // return array 
}