#include "student.h"
#include <iostream>
#include <limits>

using namespace std;

// Function to swap two numbers using pointers (QUESTION 1)
void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to display menu
void displayMenu() {
    cout << "\n====================================\n";
    cout << "   STUDENT MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Update Student Information\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    // Load existing data from file
    loadFromFile();
    
    int choice;
    bool running = true;
    
    // QUESTION 1: Demonstrate pointer swapping
    cout << "=== QUESTION 1: Swapping Numbers Using Pointers ===\n";
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "\nBefore swapping: x = " << x << ", y = " << y << endl;
    swapNumbers(&x, &y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    
    // QUESTION 2: Student Management System
    do {
        displayMenu();
        cin >> choice;
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "\nExiting program. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please enter a number between 1-6.\n";
                break;
        }
        
        if (running) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while (running);
    
    return 0;
}
