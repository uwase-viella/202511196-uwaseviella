#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Define the global vector
vector<Student> students;

void loadFromFile() {
    ifstream file("students.txt");
    if (file.is_open()) {
        Student s;
        while (file >> s.id >> ws) {
            getline(file, s.name);
            file >> s.age >> ws;
            getline(file, s.course);
            students.push_back(s);
        }
        file.close();
    }
}

void saveToFile() {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (const auto& s : students) {
            file << s.id << endl;
            file << s.name << endl;
            file << s.age << endl;
            file << s.course << endl;
        }
        file.close();
    }
}

void addStudent() {
    Student newStudent;
    cout << "\n=== Add New Student ===\n";
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    
    // Check if ID already exists
    for (const auto& s : students) {
        if (s.id == newStudent.id) {
            cout << "Student with this ID already exists!\n";
            return;
        }
    }
    
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, newStudent.name);
    cout << "Enter Student Age: ";
    cin >> newStudent.age;
    cin.ignore();
    cout << "Enter Student Course: ";
    getline(cin, newStudent.course);
    
    students.push_back(newStudent);
    saveToFile();
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo students found!\n";
        return;
    }
    
    cout << "\n=== Student List ===\n";
    cout << left << setw(10) << "ID" 
         << setw(25) << "Name" 
         << setw(8) << "Age" 
         << setw(20) << "Course" << endl;
    cout << string(63, '-') << endl;
    
    for (const auto& s : students) {
        cout << left << setw(10) << s.id 
             << setw(25) << s.name 
             << setw(8) << s.age 
             << setw(20) << s.course << endl;
    }
}

void searchStudent() {
    if (students.empty()) {
        cout << "\nNo students to search!\n";
        return;
    }
    
    int searchId;
    cout << "\n=== Search Student ===\n";
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    
    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            return;
        }
    }
    cout << "Student with ID " << searchId << " not found!\n";
}

void updateStudent() {
    if (students.empty()) {
        cout << "\nNo students to update!\n";
        return;
    }
    
    int updateId;
    cout << "\n=== Update Student ===\n";
    cout << "Enter Student ID to update: ";
    cin >> updateId;
    
    for (auto& s : students) {
        if (s.id == updateId) {
            cout << "\nCurrent Information:\n";
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            
            cout << "\nEnter New Information:\n";
            cin.ignore();
            cout << "New Name: ";
            getline(cin, s.name);
            cout << "New Age: ";
            cin >> s.age;
            cin.ignore();
            cout << "New Course: ";
            getline(cin, s.course);
            
            saveToFile();
            cout << "Student information updated successfully!\n";
            return;
        }
    }
    cout << "Student with ID " << updateId << " not found!\n";
}

void deleteStudent() {
    if (students.empty()) {
        cout << "\nNo students to delete!\n";
        return;
    }
    
    int deleteId;
    cout << "\n=== Delete Student ===\n";
    cout << "Enter Student ID to delete: ";
    cin >> deleteId;
    
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == deleteId) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << it->name << endl;
            cout << "Course: " << it->course << endl;
            
            char confirm;
            cout << "\nAre you sure you want to delete this student? (y/n): ";
            cin >> confirm;
            
            if (confirm == 'y' || confirm == 'Y') {
                students.erase(it);
                saveToFile();
                cout << "Student deleted successfully!\n";
            } else {
                cout << "Deletion cancelled.\n";
            }
            return;
        }
    }
    cout << "Student with ID " << deleteId << " not found!\n";
}
