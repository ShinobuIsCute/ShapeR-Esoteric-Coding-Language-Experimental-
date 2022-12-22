#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int count_char_in_line(char* line);

using namespace std;

int count_char_in_line(string line);

int main() {
    char* aisot;
    char* input_2;
    cin >> aisot;
    int answer = count_char_in_line(aisot);
    cout << answer;
    cin >> input_2;
    return 0;
}
    string aisot;
    string input_2;
    getline(cin, aisot, '\n');
    int answer = count_char_in_line(aisot);
    cout << answer;
    cin >> input_2;
    return 0;
}

int count_char_in_line(char* line) {
        int char_counter = strlen(line);
        for (int i = 0; i < strlen(line); ++i) {
                if ((line[i] == ' ') || line[i] == '\0') {
                        char_counter = char_counter - 1;
                }
        }
        return char_counter;
int count_char_in_line(string line) {
        int char_counter = line.length();
        for (int i = 0; i < line.length(); ++i) {
                if ((line[i] == ' ') || line[i] == '\0') {
                        char_counter = char_counter - 1;
                }
        }
        return char_counter;
}