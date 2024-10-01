#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int studentID;
    vector<double> assignmentMarks;
    vector<double> examMarks;

public:
    // Constructor to initialize a student with name and ID
    Student(string name, int studentID, vector<double> assignments, vector<double> exams) {
        this->name = name;
        this->studentID = studentID;
        this->assignmentMarks = assignments;
        this->examMarks = exams;
    }

    // Function to calculate final grade
    double calculateFinalGrade() const {
        // Calculate assignment average (40%)
        double assignmentAvg = 0;
        for (double mark : assignmentMarks) {
            assignmentAvg += mark;
        }
        assignmentAvg = assignmentAvg / assignmentMarks.size();

        // Calculate exam average (60%)
        double examAvg = 0;
        for (double mark : examMarks) {
            examAvg += mark;
        }
        examAvg = examAvg / examMarks.size();

        // Calculate final grade as weighted average
        double finalGrade = (assignmentAvg * 0.4) + (examAvg * 0.6);
        return finalGrade;
    }

    // Function to display student's details and final grade
    void display() const {
        cout << "Student: " << name << " (ID: " << studentID << ")\n";
        cout << "Final Grade: " << calculateFinalGrade() << "%\n";
    }
};

// Function to input data for a student
Student inputStudentData() {
    string name;
    int studentID;
    vector<double> assignments(3);
    vector<double> exams(2);

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> studentID;

    // Input assignment marks
    cout << "Enter marks for 3 assignments (out of 100):\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Assignment " << (i + 1) << ": ";
        cin >> assignments[i];
    }

    // Input exam marks
    cout << "Enter marks for 2 exams (out of 100):\n";
    for (int i = 0; i < 2; ++i) {
        cout << "Exam " << (i + 1) << ": ";
        cin >> exams[i];
    }

    return Student(name, studentID, assignments, exams);
}

// Function to display all students' details and final grades
void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        student.display();
        cout << "---------------------\n";
    }
}

int main() {
    vector<Student> students;
    int numberOfStudents;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    // Input data for each student
    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nEntering data for student " << (i + 1) << ":\n";
        students.push_back(inputStudentData());
    }

    // Display final grades for all students
    cout << "\nFinal Grades for All Students:\n";
    displayStudents(students);

    return 0;
}
