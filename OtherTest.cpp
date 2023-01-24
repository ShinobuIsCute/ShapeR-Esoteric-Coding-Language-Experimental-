#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <conio.h>

using namespace std;

main() {
    ifstream testInput;
    ofstream testOutput;
    string takeInput = "";
    testInput.open("Test.txt");
    testOutput.open("discard.txt");
    while(!testInput.eof()) {
        getline(testInput, takeInput);
        testOutput << takeInput << endl;
    }
    return 0;
}