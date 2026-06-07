#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;
};

vector<Student> students;

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
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }
    cout << "Student Not Found!\n";
}
int main() {
    int choice;
    while(true) {
    cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Search Students\n";
    cout << "5. Delete Student\n";
    cout << "5. Exit\n";
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
        break;
    }
    return 0;
}