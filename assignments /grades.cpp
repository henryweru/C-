#include <iostream>
#include <vector>
#include <iomanip>  // For setw and setprecision
using namespace std;

class Student {
private:
    string name;
    int studentID;
    vector<double> assignmentMarks;
    vector<double> examMarks;

public:

    Student(string name, int studentID, vector<double> assignments, vector<double> exams) {
        this->name = name;
        this->studentID = studentID;
        this->assignmentMarks = assignments;
        this->examMarks = exams;
    }

    double calculateFinalGrade() const {

        double assignmentAvg = 0;
        for (double mark : assignmentMarks) {
            assignmentAvg += mark;
        }
        assignmentAvg = assignmentAvg / assignmentMarks.size();

        double examAvg = 0;
        for (double mark : examMarks) {
            examAvg += mark;
        }
        examAvg = examAvg / examMarks.size();

        double finalGrade = (assignmentAvg * 0.4) + (examAvg * 0.6);
        return finalGrade;
    }

    void display() const {
        cout << setw(20) << left << name << setw(10) << studentID;
        cout << fixed << setprecision(2) << setw(10) << calculateFinalGrade() << "%" << endl;
    }
};

Student inputStudentData() {
    string name;
    int studentID;
    vector<double> assignments(3);
    vector<double> exams(2);

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter marks for 3 assignments (out of 100):\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Assignment " << (i + 1) << ": ";
        cin >> assignments[i];
    }

    cout << "Enter marks for 2 exams (out of 100):\n";
    for (int i = 0; i < 2; ++i) {
        cout << "Exam " << (i + 1) << ": ";
        cin >> exams[i];
    }

    return Student(name, studentID, assignments, exams);
}

void displayStudents(const vector<Student>& students) {
    cout << setw(20) << left << "Name" << setw(10) << "ID" << setw(10) << "Final Grade" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& student : students) {
        student.display();
    }
}

int main() {
    vector<Student> students;
    int numberOfStudents;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "\nEntering data for student " << (i + 1) << ":\n";
        students.push_back(inputStudentData());
    }

    cout << "\nFinal Grades for All Students:\n";
    displayStudents(students);

    return 0;
}
