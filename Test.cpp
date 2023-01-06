#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;


int count_char_in_line(string line);
int check_rhombus(string* text, int start);
int* shape_finder(string* text);

int main() {
    //string* aisot;
    string input_2;
    //getline(cin, aisot[0], '\n');
    //getline(cin, aisot[1], '\n');
    //getline(cin, aisot[2], '\n');
    string arr[5] = {"  ~  ", " ~~~ ", "~~~~~", " ~~~ ", "  ~  "};
    string t = "Hello.";
    //int answer = count_char_in_line(t);
    int* answer = shape_finder(arr);
    cout << answer[0];
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

int* shape_finder(string* text) {

        int i = 0;
        int array_size = 0;
        int* array_to_return = (int*) malloc(sizeof(int));
        int* tmp;

        while (text[i] != "\u001a") {
                
                if (i == 0) {
                        if (count_char_in_line(text[i]) == 0) {
                        ++i;
                        }
                } else {
                        while (count_char_in_line(text[i]) != 0) {
                                ++i;
                        } //fix??
                }
                 
                if (count_char_in_line(text[i]) == 1) {
                        if (check_rhombus(text, i) == 1) {
                                //place 7 in array and then continue the loop
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
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
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 1;
                                continue;
                        }
                        if (text[j][0] == ' ') {
                                // place 4 in array and then continue loop
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 4;
                                continue;
                        } else {
                                // place 2 in array and then continue loop 
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
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
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 3;
                                continue;
                        } else if (count_char_in_line(text[i]) == count_char_in_line(text[j])) {
                                // place 0 in array and then continue loop
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 0;
                                continue;
                        } else if (count_char_in_line(text[i]) < count_char_in_line(text[j])) {
                                // place 5 in array and then continue loop
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 5;
                                continue;
                        } else if (count_char_in_line(text[i]) > count_char_in_line(text[j])) {
                                // place 6 in array and then continue loop
                                ++array_size;
                                tmp = (int*) realloc((int*) array_to_return, sizeof(int)*(array_size+1));
                                array_to_return[array_size] = 6;
                                continue;
                        }
                }
        }
        return array_to_return;
}