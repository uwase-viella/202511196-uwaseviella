#include "notepad.h"
void writeFile(string filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: Could not create or open file." << endl;
        return;
    }

    cout << "Type your text below. Type END on a new line to stop." << endl;

    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        outFile << line << endl;
    }

    outFile.close();
    cout << "File saved successfully." << endl;
}
void readFile(string filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error: File not found." << endl;
        return;
    }

    cout << "===== File Contents =====" << endl;

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    cout << "=========================" << endl;
    inFile.close();
}
void appendFile(string filename) {
    ofstream outFile(filename, ios::app);

    if (!outFile) {
        cout << "Error: Could not open file for appending." << endl;
        return;
    }

    cout << "Type text to append. Type END on a new line to stop." << endl;

    string line;
    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        outFile << line << endl;
    }

    outFile.close();
    cout << "Text appended successfully." << endl;
}
