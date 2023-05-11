#include <fstream>
#include <iostream>
#include <sstream>
#include "Course.hpp"
#include "LinkedList.hpp"
#include "Professor.hpp"
#include "Student.hpp"

using namespace std;

#define STUDENTS_FILE   "school-files/students.txt"
#define PROFESSORS_FILE "school-files/professors.txt"
#define COURSES_FILE    "school-files/courses.txt"

#define STUDENTS_FINISHED_FILE   "../school-files/students-finished.txt"
#define PROFESSORS_FINISHED_FILE "../school-files/professors-finished.txt"
#define COURSES_FINISHED_FILE    "../school-files/courses-finished.txt"

int displayMenu()
{
    int choice;
    cout << "\nUniversity Management System" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Remove a student" << endl;
    cout << "3. Add a professor" << endl;
    cout << "4. Remove a professor" << endl;
    cout << "5. Add a course" << endl;
    cout << "6. Remove a course" << endl;
    cout << "7. Enroll a student in a course" << endl;
    cout << "8. Drop a student from a course" << endl;
    cout << "9. Assign a professor to a course" << endl;
    cout << "10. Remove a professor from a course" << endl;
    cout << "11. Display all students" << endl;
    cout << "12. Display all professors" << endl;
    cout << "13. Display all courses" << endl;
    cout << "14. Display student details" << endl;
    cout << "15. Display professor details" << endl;
    cout << "16. Quit\n" << endl;
    cout << "Enter a number from 1 to 16: ";
    cin >> choice;
    return choice;
}

vector<string> getLinesFromFile(string fileName)
{
    vector<string> lines;
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }

    return lines;
}

vector<string> splitString(const string &str, char delimiter)
{
    vector<string> splitLine;
    istringstream iss(str);
    string token;
    while (getline(iss, token, delimiter)) {
        splitLine.push_back(token);
    }
    return splitLine;
}

LinkedList *getCoursesFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName);
    LinkedList *list = new LinkedList();

    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';');
        if (splitLine.size() != 3) {
            cout << "Invalid format: " << fileName << endl;
            exit(84);
        }
        Course *c = new Course(list->getSize() + 1, splitLine[0], stoi(splitLine[1]), splitLine[2]);
        list->push_back(c, c->getId());
    }
    return list;
}

LinkedList *getStudentsFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName);
    LinkedList *list = new LinkedList();

    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';');
        if (splitLine.size() != 1) {
            cout << "Invalid format: " << fileName << endl;
            exit(84);
        }
        Student *s = new Student(list->getSize() + 1, splitLine[0]);
        list->push_back(s, s->getId());
    }
    return list;
}

LinkedList *getProfessorsFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName);
    LinkedList *list = new LinkedList();

    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';');
        if (splitLine.size() != 1) {
            cout << "Invalid format: " << fileName << endl;
            exit(84);
        }
        Professor *p = new Professor(list->getSize() + 1, splitLine[0]);
        list->push_back(p, p->getId());
    }
    return list;
}

void displayCourseStudent(Course *course) {
    Node *current = course->getStudents()->getHead();
    while (current) {
        cout << current->getID() << ": " << static_cast<Student*>(current->getData())->getName() << '\n';
        current = current->getNext();
    }
}

void displayDetailsCourses(Course *course) {
    cout << course->getName() << '\n';
    cout << course->getDescription() << ' ';
    cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/" << course->getCapacity() << '\n';
    displayCourseStudent(course);
}

void displayListDetailsCourses(LinkedList *&courses) {
    Node *current = courses->getHead();
    while (current) {
        Course *course = static_cast<Course*>(current->getData());
        cout << current->getID() << ": " << course->getName() << '\n';
        cout << course->getDescription() << ' ';
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/" << course->getCapacity() << '\n';
        displayCourseStudent(course);
        current = current->getNext();
    }
    cout << endl;
}

void displayListCourses(LinkedList *&courses) {
    Node *current = courses->getHead();
    while (current) {
        Course *course = static_cast<Course*>(current->getData());
        cout << current->getID() << ": " << course->getName() << '\n';
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/" << course->getCapacity() << '\n';
        current = current->getNext();
    }
    cout << endl;
}

void displayStudents(LinkedList *&students) {
    Node *current = students->getHead();
    while (current) {
        cout << current->getID() << ": " << static_cast<Student*>(current->getData())->getName() << '\n';
        current = current->getNext();
    }
    cout << endl;
}

Student *displayAndGetStudent(LinkedList *&students) {
    int studentId = 0;
    cout << endl;
    displayStudents(students);
    cout << "Student to add: ";
    cin >> studentId;
    Node *node = students->find_by_id(studentId);
    if (node == NULL) {
        cout << "Student not found";
        return displayAndGetStudent(students);
    }
    return static_cast<Student *>(node->getData());
}

Course *displayAndGetCourse(LinkedList *&courses) {
    int courseId = 0;
    cout << endl;
    displayListCourses(courses);
    cout << "Course to add the student: ";
    cin >> courseId;
    Node *node = courses->find_by_id(courseId);

    if (node == NULL) {
        cout << "Course not found";
        return displayAndGetCourse(courses);
    }
    return static_cast<Course *>(node->getData());
}

void addStudent(LinkedList *&courses, LinkedList *&students) {
    Student* student = displayAndGetStudent(students);

    while(1) {
        try {
            Course* course = displayAndGetCourse(courses);
            course->addStudents(student);
            cout << "Student added successfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception& e) {
            cout << e.what() << std::endl;
        }
    }
    cout << "-----------------------------\n";
}

int main()
{
    LinkedList *courses = getCoursesFromFile(COURSES_FILE);
    LinkedList *students = getStudentsFromFile(STUDENTS_FILE);
    LinkedList *professors = getProfessorsFromFile(PROFESSORS_FILE);

    if (!courses || !students || !professors) {
        cout << "Error: Unable to load files" << endl;
        return 84;
    }
    int choice = displayMenu();
    while (choice != 16) {
        switch (choice) {
            case 1:
                addStudent(courses, students);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                cout << "Coming soon!" << endl;
                break;
            case 8:
                cout << "Coming soon!" << endl;
                break;
            default:
                cout << "Error! Input must be a number between 1 and 16" << endl;
                break;
        }
        choice = displayMenu();
    }
    return 0;
}