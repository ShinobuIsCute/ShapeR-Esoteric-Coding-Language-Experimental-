#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int count_char_in_line(string line);
int check_rhombus(string* text, int start);
int* shape_finder(string* text, int num_lines);

int main() {
    //string* aisot;
    string input_2;
    //getline(cin, aisot[0], '\n');
    //getline(cin, aisot[1], '\n');
    //getline(cin, aisot[2], '\n');
    string arr[33] = {"d 31234", "s Hello", "~ ~~~~~", " ", "  ~", " ~~", "~~~", " ~~", "  ~", " ", "~", "~~", "~~~", "~~", "~", " ", "  ~", " ~~~", "~~~~~", " ", "~~~~~", " ~~~", "  ~", " ", " ~~~", "~~~~~", " ", "~~~~~", " ~~~", " ", " ~ ", "~~~", " ~ "};
    string t = "Hello.";
    //int answer = count_char_in_line(t);
    int* answer = shape_finder(arr, 33);
    
    size_t n = sizeof(answer)/sizeof(int);
 
    // loop through the array elements
    for (int i = 0; i < 9; i++) {
        cout << answer[i] << ' ';
    }
    cin >> input_2;
    if(sizeof(input_2) == 4) {
        return 0;
    } else {
        return 1;
    }
    
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