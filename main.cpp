#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;
};

vector<Student> students;
void saveToFile() {
    ofstream file("students.txt");
    for(int i = 0; i < students.size(); i++) {
        file << students[i].roll << endl;
        file << students[i].name << endl;
        file << students[i].marks << endl;
    }
    file.close();
}
void loadFromFile() {
    ifstream file("students.txt");
    Student s;
    while(file >> s.roll) {
        file.ignore();
        getline(file, s.name);
        file >> s.marks;
        file.ignore();
        students.push_back(s);
    }
    file.close();
}
void addStudent() {
    Student s;

    cout << "Enter Roll No: ";
    cin >> s.roll;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    saveToFile();

    cout << "Student Added Successfully!\n";
}
void viewStudents() {
    if(students.empty()) {
        cout << "No Students Found!\n";
        return;
    }
    for(int i = 0; i < students.size(); i++) {
        cout << "\nRoll No: " << students[i].roll;
        cout << "\nName: " << students[i].name;
        cout << "\nMarks: " << students[i].marks << endl;
        char grade;
        if(students[i].marks >= 90)
            grade = 'A';
        else if(students[i].marks >= 80)
            grade = 'B';
        else if(students[i].marks >= 70)
            grade = 'C';
        else if(students[i].marks >= 60)
            grade = 'D';
        else
            grade = 'F';
        cout << "Grade: " << grade << endl;
    }
}
void searchStudent() {
    int roll;
    cout << "Enter Roll No to Search:";
    cin >> roll;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].roll == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll No: " << students[i].roll << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }
    cout << "Student Not Found!\n";
}
void deleteStudent() {
    int roll;
    cout << "Enter Roll No to Delete: ";
    cin >> roll;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].roll == roll) {
            students.erase(students.begin() + i);
            saveToFile();
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found!\n";
}
void updateStudent() {
    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].roll == roll) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, students[i].name);
            cout << "Enter New Marks: ";
            cin >> students[i].marks;
            saveToFile();
            cout << "Student Updated Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found\n";
}
void displayTopper() {
    if(students.empty()) {
        cout << "No Students Found!\n";
        return;
    }
    int topperIndex = 0;
    for(int i = 1; i < students.size(); i++) {
        if(students[i].marks > students[topperIndex].marks) {
            topperIndex = 1;
        }
    }
    cout << "\n===== TOPPER =====\n";
    cout << "Roll No: " << students[topperIndex].roll << endl;
    cout << "Name: " << students[topperIndex].name << endl;
    cout << "Marks: " << students[topperIndex].marks << endl;
}
void totalStudents() {
    cout << "Total Students: " << students.size() << endl;
}
void statistics() {
    if(students.empty()) {
        cout << "No Students Found!\n";
        return;
    }
    float sum = 0;
    float highest = students[0].marks;
    float lowest = students[0].marks;
    for(int i = 0; i < students.size(); i++) {
        sum += students[i].marks;
        if(students[i].marks > highest)
            highest = students[i].marks;
        if(students[i].marks < lowest)
            lowest = students[i].marks;
    }
    cout << "\n===== STATISTICS =====\n";
    cout << "Total Students: " << students.size() << endl;
    cout << "Average Marks: " << sum / students.size() << endl;
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
}
int main() {
    loadFromFile();
    int choice;
    while(true) {
    cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. View Student\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Update Student\n";
    cout << "6. Display Topper\n";
    cout << "7. Total Students\n";
    cout << "8. Statistics\n";
    cout << "9. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;
    if(choice == 1) 
        addStudent();
    else if(choice == 2)
        viewStudents();
    else if(choice == 3)
        searchStudent();
    else if(choice == 4)
        deleteStudent();
    else if(choice == 5)
        updateStudent();
    else if(choice == 6)
        displayTopper();
    else if(choice == 7)
        totalStudents();
    else if(choice == 8)
        statistics();
    else if(choice == 9)
        break;
    }
    return 0;
}