
#include "notepad.h"

int main() {
    int choice;
    string filename;

    // Loop keeps the menu running until the user chooses Exit
    do {
        // Display the menu
        cout << endl;
        cout << "===== SIMPLE NOTEPAD =====" << endl;
        cout << "1. Write File"             << endl;
        cout << "2. Read File"              << endl;
        cout << "3. Append File"            << endl;
        cout << "4. Exit"                   << endl;
        cout << "==========================" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear leftover newline from input buffer

        // Ask for filename for options 1, 2, 3
        if (choice >= 1 && choice <= 3) {
            cout << "Enter filename (e.g. notes.txt): ";
            getline(cin, filename);
        }

        // Handle the user's menu choice
        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1-4." << endl;
        }

    } while (choice != 4); // Repeat until Exit is chosen

    return 0;
}
