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

#define STUDENTS_FINISHED_FILE   "school-files/students-finished.txt"
#define PROFESSORS_FINISHED_FILE "school-files/professors-finished.txt"
#define COURSES_FINISHED_FILE    "school-files/courses-finished.txt"

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

void displayPerson(LinkedList *students)
{
    Node *current = students->getHead();
    while (current) {
        cout << current->getID() << ": " << static_cast<Student *>(current->getData())->getName() << '\n';
        current = current->getNext();
    }
    cout << endl;
}

void displayDetailsCourses(Course *course)
{
    cout << course->getName() << '\n';
    if (course->getProfessor())
        cout << course->getProfessor() << ' ';
    cout << course->getDescription() << ' ';
    cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
         << course->getCapacity() << '\n';
    displayPerson(course->getStudents());
}

void displayListDetailsCourses(LinkedList *&courses)
{
    Node *current = courses->getHead();
    while (current) {
        Course *course = static_cast<Course *>(current->getData());
        cout << current->getID() << ": " << course->getName() << '\n';
        cout << course->getDescription() << ' ';
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
             << course->getCapacity() << '\n';
        displayPerson(course->getStudents());
        current = current->getNext();
    }
    cout << endl;
}

void displayListCourses(LinkedList *&courses)
{
    Node *current = courses->getHead();
    while (current) {
        Course *course = static_cast<Course *>(current->getData());
        cout << current->getID() << ": " << course->getName() << '\n';
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
             << course->getCapacity() << '\n';
        current = current->getNext();
    }
    cout << endl;
}

Student *displayAndGetStudent(LinkedList *students)
{
    int studentId = 0;
    cout << endl;
    displayPerson(students);
    cout << "Student to select: ";
    cin >> studentId;
    Node *node = students->findByID(studentId);
    if (node == NULL) {
        cout << "Student not found";
        return displayAndGetStudent(students);
    }
    return static_cast<Student *>(node->getData());
}

Course *displayAndGetCourse(LinkedList *courses)
{
    int courseId = 0;
    if (courses->getSize() == 0) {
        throw std::runtime_error("There is no course available");
    }
    cout << endl;
    displayListCourses(courses);
    cout << "Course to select: ";
    cin >> courseId;
    Node *node = courses->findByID(courseId);

    if (node == NULL) {
        cout << "Course not found";
        return displayAndGetCourse(courses);
    }
    return static_cast<Course *>(node->getData());
}

Professor *displayAndGetProfessor(LinkedList *professors)
{
    int studentId = 0;
    cout << endl;
    displayPerson(professors);
    cout << "Professor to select: ";
    cin >> studentId;
    Node *node = professors->findByID(studentId);
    if (node == NULL) {
        cout << "Professor not found";
        return displayAndGetProfessor(professors);
    }
    return static_cast<Professor *>(node->getData());
}

LinkedList *getCoursesNoEmpty(LinkedList *&courses)
{
    LinkedList *fillCourse = new LinkedList();
    Node *current = courses->getHead();

    while (current) {
        if (static_cast<Course *>(current->getData())->getStudents()->getSize() != 0)
            fillCourse->push_back(current->getData(), current->getID());
        current = current->getNext();
    }
    return fillCourse;
}

LinkedList *getCoursesNoFull(LinkedList *&courses)
{
    LinkedList *fillCourse = new LinkedList();
    Node *current = courses->getHead();

    while (current) {
        if (static_cast<Course *>(current->getData())->getStudents()->getSize()
            < static_cast<Course *>(current->getData())->getCapacity())
            fillCourse->push_back(current->getData(), current->getID());
        current = current->getNext();
    }
    return fillCourse;
}

void addStudent(LinkedList *&courses, LinkedList *&students)
{
    Course *course = nullptr;
    try {
        course = displayAndGetCourse(getCoursesNoFull(courses));
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
        if (std::string(e.what()).compare("There is no course available") == 0) {
            return;
        }
    }

    while (1) {
        try {
            Student *student = displayAndGetStudent(students);
            course->addStudents(student);
            cout << "Student added successfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception &e) {
            cout << e.what() << std::endl;
            break;
        }
    }
    cout << "-----------------------------\n";
}

void removeStudent(LinkedList *&courses, LinkedList *&students)
{
    Course *course = nullptr;
    try {
        course = displayAndGetCourse(getCoursesNoEmpty(courses));
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
        if (std::string(e.what()).compare("There is no course available") == 0) {
            return;
        }
    }

    while (1) {
        try {
            Student *student = displayAndGetStudent(course->getStudents());
            course->removeStudents(student->getId());
            cout << "Student remove successfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception &e) {
            cout << e.what() << std::endl;
        }
    }
    cout << "-----------------------------\n";
}

Student *getStudentsByName(LinkedList *&students, std::string name)
{
    Node *c = students->getHead();
    while (c) {
        if (static_cast<Student *>(c->getData())->getName().compare(name) == 0)
            return static_cast<Student *>(c->getData());
        c = c->getNext();
    }
    return nullptr;
}

Professor *getProfessorByName(LinkedList *&professors, std::string name)
{
    Node *c = professors->getHead();
    while (c) {
        if (static_cast<Professor *>(c->getData())->getName().compare(name) == 0)
            return static_cast<Professor *>(c->getData());
        c = c->getNext();
    }
    return nullptr;
}

Course *getCourseByName(LinkedList *&courses, std::string name)
{
    Node *c = courses->getHead();
    while (c) {
        if (static_cast<Course *>(c->getData())->getName().compare(name) == 0)
            return static_cast<Course *>(c->getData());
        c = c->getNext();
    }
    return nullptr;
}

void createStudent(LinkedList *&students)
{
    std::string studentFirstName = "";
    std::string studentLastName = "";
    cout << endl;
    cin.ignore(); // discard any remaining characters in the input buffer
    while (true) {
        cout << "Student firstName: ";
        cin >> studentFirstName;
        cout << "Student lastName: ";
        cin >> studentLastName;
        if (getStudentsByName(students, studentFirstName + " " + studentLastName) == nullptr)
            break;
    }
    Student *n = new Student(students->getSize() + 1, studentFirstName + " " + studentLastName);
    students->push_back(n, n->getId());
    cout << "Student created successfully\n";
    cout << "-----------------------------\n";
}

void removeStudent(LinkedList *&students)
{
    Student *n = displayAndGetStudent(students);
    students->remove(n->getId());
    cout << "Student remove successfully\n";
    cout << "-----------------------------\n";
}

void createProfessor(LinkedList *&professors)
{
    std::string professorFirstName = "";
    std::string professorLastName = "";
    cout << endl;
    cin.ignore(); // discard any remaining characters in the input buffer
    while (true) {
        cout << "Professor firstName: ";
        cin >> professorFirstName;
        cout << "Professor lastName: ";
        cin >> professorLastName;
        if (getProfessorByName(professors, professorFirstName + " " + professorLastName) == nullptr)
            break;
    }
    Professor *n = new Professor(professors->getSize() + 1, professorFirstName + " " + professorLastName);
    professors->push_back(n, n->getId());
    cout << "Professor created successfully\n";
    cout << "-----------------------------\n";
}

void removeProfessor(LinkedList *&professors)
{
    Professor *n = displayAndGetProfessor(professors);
    professors->remove(n->getId());
    cout << "Professor remove successfully\n";
    cout << "-----------------------------\n";
}

void createCourse(LinkedList *&courses)
{
    std::string courseName = "";
    int courseCapacity = 0;
    std::string courseDescription = "";
    cout << endl;
    cin.ignore(); // discard any remaining characters in the input buffer
    while (true) {
        cout << "Course name: ";
        cin >> courseName;
        cout << "Course capacity(number): ";
        cin >> courseCapacity;
        cout << "Course description: ";
        cin >> courseDescription;
        if (getCourseByName(courses, courseName) == nullptr)
            break;
    }
    Course *n = new Course(courses->getSize() + 1, courseName, courseCapacity, courseName);
    courses->push_back(n, n->getId());
    cout << "Course created successfully\n";
    cout << "-----------------------------\n";
}

void removeCourse(LinkedList *&courses)
{
    Course *n = displayAndGetCourse(courses);
    courses->remove(n->getId());
    cout << "Course remove successfully\n";
    cout << "-----------------------------\n";
}

void assignProfessor(LinkedList *&courses, LinkedList *&professors)
{
    Course *course = nullptr;
    try {
        course = displayAndGetCourse(getCoursesNoFull(courses));
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
        if (std::string(e.what()).compare("There is no course available") == 0) {
            return;
        }
    }

    while (1) {
        try {
            Professor *professor = displayAndGetProfessor(professors);
            course->setProfessor(professor);
            cout << "Professor assign succesfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception &e) {
            cout << e.what() << std::endl;
            break;
        }
    }
    cout << "-----------------------------\n";
}

void deleteProfessorFromCourse(LinkedList *&courses)
{
    Course *course = nullptr;
    try {
        course = displayAndGetCourse(getCoursesNoEmpty(courses));
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
        if (std::string(e.what()).compare("There is no course available") == 0) {
            return;
        }
    }

    try {
        course->setProfessor(nullptr);
        cout << "Professor remove successfully\n";
        displayDetailsCourses(course);
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
    }
    cout << "-----------------------------\n";
}

int displayMenu()
{
    int choice;
    cout << "\nUniversity Management System" << endl;
    cout << "1. Create a student" << endl;
    cout << "2. Remove a student" << endl;
    cout << "3. Create a professor" << endl;
    cout << "4. Remove a professor" << endl;
    cout << "5. Create a course" << endl;
    cout << "6. Remove a course" << endl;
    cout << "7. Enroll a student in a course" << endl;
    cout << "8. Drop a student from a course" << endl;
    cout << "9. Assign a professor to a course" << endl;
    cout << "10. Remove a professor from a course" << endl;
    cout << "11. Display all students" << endl;
    cout << "12. Display all professors" << endl;
    cout << "13. Display all courses" << endl;
    cout << "14. Quit\n" << endl;
    cout << "Enter a number from 1 to 14: ";
    cin >> choice;
    return choice;
}

void saveCoursesToFile(LinkedList *&courses, std::string filename)
{
    std::ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to open file" << endl;
        return;
    }
    for (Node *current = courses->getHead(); current; current = current->getNext()) {
        Course *course = static_cast<Course *>(current->getData());
        file << course->getName() << ";" << course->getCapacity() << ";" << course->getDescription() << std::endl;
    }
}

void saveStudentsToFile(LinkedList *&students, std::string filename)
{
    std::ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to open file" << endl;
        return;
    }
    for (Node *current = students->getHead(); current; current = current->getNext()) {
        Student *student = static_cast<Student *>(current->getData());
        file << student->getName() << std::endl;
    }
}

void saveProfessorsToFile(LinkedList *&professors, std::string filename)
{
    std::ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to open file" << endl;
        return;
    }
    for (Node *current = professors->getHead(); current; current = current->getNext()) {
        Professor *professor = static_cast<Professor *>(current->getData());
        file << professor->getName() << std::endl;
    }
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
    while (choice != 14) {
        switch (choice) {
            case 1:
                createStudent(students);
                break;
            case 2:
                removeStudent(students);
                break;
            case 3:
                createProfessor(professors);
                break;
            case 4:
                removeProfessor(professors);
                break;
            case 5:
                createCourse(courses);
                break;
            case 6:
                removeCourse(courses);
                break;
            case 7:
                addStudent(courses, students);
                break;
            case 8:
                removeStudent(courses, students);
                break;
            case 9:
                assignProfessor(courses, professors);
                break;
            case 10:
                deleteProfessorFromCourse(courses);
                break;
            case 11:
                displayPerson(students);
                break;
            case 12:
                displayPerson(professors);
                break;
            case 13:
                displayListDetailsCourses(courses);
                break;
            default:
                cout << "Error! Input must be a number between 1 and 14" << endl;
                break;
        }
        choice = displayMenu();
    }

    saveCoursesToFile(courses, COURSES_FINISHED_FILE);
    saveStudentsToFile(students, STUDENTS_FINISHED_FILE);
    saveProfessorsToFile(professors, PROFESSORS_FINISHED_FILE);

    return 0;
}