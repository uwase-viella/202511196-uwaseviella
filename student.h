#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

// Student structure definition
struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveToFile();
void loadFromFile();

// Global vector to store students (declared as extern)
extern vector<Student> students;

#endif
