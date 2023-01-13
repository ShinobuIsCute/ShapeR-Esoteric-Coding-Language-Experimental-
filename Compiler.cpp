#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
//1,3,5,6 to do now

using namespace std; // Just makes it so you don't need std::

int resizeOrder(int* iref, int* jref, int* shapeOrder, int orderSize, int shapeID, bool skipLine);
void shape_finder(string* text, int* shapeOrder, int num_lines);
int count_char_in_line(string line);
int check_rhombus(string* text, int start);
int upTriangle(string* text, int start); //check down for documentation
int downTriangle(string* text, int start);
int topHexagon(string* text, int start);
int bottomHexagon(string* text, int start);

int main() {
        int counter = 0; //Will first use to count amount of lines in input file
        int num_char_in_file = 0;
        int numRows; // Amount of rows in ShapeArray
        int numCols;
        //int *orderSize = 0;
        string fileName; //Take filename from terminal, can make it so it's just a set string if needed
        string tempLine; //temporarily stores lines of the txt file
        string redacted; //Just used to make the line counter work
        cout << "Enter Filename: Test.txt\n";
        fileName = "Test.txt";
        
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
        
        for(int row = 0; row < numRows; row++) { //print out the Shape Array.
                cout << ShapeArray[row];
                printf("\n");
        }
        
        printf("Hello there!\n");

        counter = -1; //Now, counter will be used for the compiler itself.

        originalFile.close();
        //printf("Before ShapeOrder");
        int ShapeOrder[100];
        for(int i = 0; i < 100; i++) {
                ShapeOrder[i]= 0;
                //printf("%d\n",ShapeOrder[i]);
        }
        printf("gay");
        shape_finder(ShapeArray, ShapeOrder, /*orderSize,*/ numRows); //Placeholder ShapeOrder array here
        //for(int i = 0; i < )

        int shapeArrayIndex = 0;
        //Manager function here
        for(int index = 0; index < 100; index++) {
                cout << ShapeOrder[index] << "\n";
                switch(ShapeOrder[index]) {
                        case 9: //Square / rectangle
                                break;
                        case 1: //up 
                                shapeArrayIndex = upTriangle(ShapeArray, shapeArrayIndex);
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
        for (int i = 0; i < numRows; i++) {
                (ShapeArray + i)->~string();  // Call the string destructor to clean up the element
        }
        
        printf("HELLO");
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

void shape_finder(string* text, int* shapeOrder, /*int *orderSize,*/ int num_lines) {
        int i = 0;
        int j = 0;
        int* iref = &i;
        int* jref = &j;
        int ij [2];
        int* tmp;
        int array_index = 0;
        cout << "Initializing, NumLines : " << num_lines << "\n";

        while (i < num_lines) {
                
                while ((count_char_in_line(text[i])) == 0 && (i < num_lines - 1)) {
                        i++;
                        cout << i << "\n";
                } 
                
                j = i;
                while (count_char_in_line(text[j]) != 0 && i < num_lines - 1) {
                        ++j;
                }
                --j;
                cout << "J : " << j;
                 
                if (count_char_in_line(text[i]) == 1) {
                        if (check_rhombus(text, i) == 1) {
                                //place 7 in array and then continue the loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 7, true);
                                continue;
                        } else if (check_rhombus(text, i) == 2) {
                                // place 8 in array and then continue the loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 8, true);
                                continue;
                        } else if (count_char_in_line(text[j]) != 1) {
                                // place 1 in array and then continue the loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 1, true);
                                continue;
                        } else if (text[j][0] == ' ') {
                                // place 4 in array and then continue loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 4, true);
                                continue;
                        } else {
                                // place 2 in array and then continue loop 
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 2, true);
                                continue;
                        }
                } else {
                        if (count_char_in_line(text[j]) == 1) {
                                // place 3 in array and then continnue loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 3, true);
                                continue;
                        } else if (count_char_in_line(text[i]) == count_char_in_line(text[j])) {
                                // place 0 in array and then continue loop
                                //cout << "J : " << j << "\n";
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 9, false);
                                
                                continue;
                        } else if (count_char_in_line(text[i]) < count_char_in_line(text[j])) {
                                // place 5 in array and then continue loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 5, true);
                                continue;
                        } else if (count_char_in_line(text[i]) > count_char_in_line(text[j])) {
                                // place 6 in array and then continue loop
                                array_index = resizeOrder(iref, jref, shapeOrder, array_index, 6, true);
                                continue;
                        }
                }
        }
}

int resizeOrder(int* iref, int* jref, int* shapeOrder, int orderSize, int shapeID, bool skipLine) { //Helper function
        int i = *iref;
        int j = *jref; // store values from pointers as integers
        cout << "OrderSize : " << orderSize << "\n";
        shapeOrder[orderSize] = shapeID;
        cout << "ShapeID : " << shapeID << "\n";
        
        orderSize++;
        if(skipLine) {
                i = 2*j - i + 4;
        } else {
                i = j + 2;
        }
        *iref = i; //return updated values using pointers.
        *jref = j;
        return orderSize;
}

int skipShape(string* text, int start) {
        
}

// All functions return the updated index start.

int upTriangle(string* text, int start) { //writes upTriangle code into file

}


int downTriangle(string* text, int start);
int topHexagon(string* text, int start);
int bottomHexagon(string* text, int start);