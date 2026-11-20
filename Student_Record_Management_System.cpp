#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
using namespace std;
struct Student
{
int rollNo;
string name;
float marks;
};
class StudentManagement
{
vector<Student> students;
queue<int> serviceQueue;
stack<Student> recentRecords;
public:
int findStudent(int roll)
{
for (int i = 0; i < (int)students.size(); i++)
{
if (students[i].rollNo == roll)
return i;
}
return -1;
}
void addStudent()
{
Student s;
cout << "Enter roll number: ";
cin >> s.rollNo;
if (findStudent(s.rollNo) != -1)
{
cout << "Roll number already exists!\n";
return;
}
cout << "Enter student name: ";
cin >> ws;
getline(cin, s.name);
cout << "Enter marks: ";
cin >> s.marks;
students.push_back(s);
recentRecords.push(s);


cout << "Student added successfully!\n";
}
void displayStudents()
{
if (students.empty())
{
cout << "No student records available.\n";
return;
}
cout << "\nRoll No\tName\t\tMarks\n";
for (const Student &s : students)
{
cout << s.rollNo << "\t"
<< s.name << "\t\t"
<< s.marks << endl;
}
}
void searchStudent()
{
int roll;
cout << "Enter roll number to search: ";
cin >> roll;
int i = findStudent(roll);
if (i == -1)
cout << "Student not found.\n";
else
{
cout << "Name: " << students[i].name << endl;
cout << "Roll No: " << students[i].rollNo << endl;
cout << "Marks: " << students[i].marks << endl;
}
}
void deleteStudent()
{
int roll;
cout << "Enter roll number to delete: ";
cin >> roll;
int i = findStudent(roll);
if (i == -1)
cout << "Student not found.\n";
else
{
students.erase(students.begin() + i);
cout << "Student deleted successfully.\n";
}
}


void sortStudents()
{
sort(students.begin(), students.end(),
[](const Student &a, const Student &b)
{
return a.rollNo < b.rollNo;
});
cout << "Records sorted by roll number.\n";
displayStudents();
}
void addToQueue()
{
int roll;
cout << "Enter roll number for service queue: ";
cin >> roll;
if (findStudent(roll) == -1)
{
cout << "Student record not found.\n";
return;
}
serviceQueue.push(roll);
cout << "Student added to service queue.\n";
}
void serveNextStudent()
{
if (serviceQueue.empty())
{
cout << "Service queue is empty.\n";
return;
}
int roll = serviceQueue.front();
serviceQueue.pop();
int i = findStudent(roll);
if (i == -1)
cout << "Roll number " << roll
<< " was served; record was deleted.\n";
else
cout << "Now serving: " << students[i].name
<< " (Roll No: " << roll << ")\n";
}
void showRecentStudent()
{
if (recentRecords.empty())
{
cout << "No recently added records.\n";
return;
}


Student s = recentRecords.top();
cout << "Most recently added student:\n";
cout << "Roll No: " << s.rollNo << endl;
cout << "Name: " << s.name << endl;
cout << "Marks: " << s.marks << endl;
}
};

int main()
{
StudentManagement sm;
int choice;
do
{
cout << "\n=== STUDENT RECORD MANAGEMENT ===\n";
cout << "1. Add Student\n";
cout << "2. Display Students\n";
cout << "3. Search Student\n";
cout << "4. Delete Student\n";
cout << "5. Sort Students\n";
cout << "6. Add Student to Service Queue\n";
cout << "7. Serve Next Student\n";
cout << "8. Show Most Recently Added Student\n";
cout << "0. Exit\n";
cout << "Enter your choice: ";
if (!(cin >> choice))
break;
switch (choice)
{
case 1:
sm.addStudent();
break;
case 2:
sm.displayStudents();
break;
case 3:
sm.searchStudent();
break;
case 4:
sm.deleteStudent();
break;
case 5:
sm.sortStudents();
break;
case 6:
sm.addToQueue();
break;
case 7:
sm.serveNextStudent();
break;
case 8:
sm.showRecentStudent();
break;


case 0:
cout << "Thank you for using the system!\n";
break;
default:
cout << "Invalid choice. Try again.\n";
}
} while (choice != 0);
return 0;
}
