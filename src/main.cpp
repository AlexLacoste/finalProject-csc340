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

/**
 * This function reads the contents of a file line by line and returns a vector of strings,
 * where each string represents a line in the file.
 * It takes the file name as input.
 *
 * @param fileName The name of the file to be read
 * @return A vector of strings representing the lines in the file
 */
vector<string> getLinesFromFile(string fileName)
{
    vector<string> lines;    // Vector to store the lines read from the file
    ifstream file(fileName); // Create an input file stream
    string line;             // Variable to store each line of the file

    // Check if the file is open
    if (file.is_open()) {
        // Read each line from the file using getline and add it to the vector
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();                                        // Close the file
    } else {
        cout << "Unable to open file: " << fileName << endl; // Unable to open the file
    }

    return lines; // Return the vector of lines
}

/**
 * This function splits a given string into multiple substrings based on a specified delimiter.
 * It takes the input string and the delimiter character as parameters.
 *
 * @param str The input string to be split
 * @param delimiter The delimiter character to split the string
 * @return A vector of strings representing the split substrings
 */
vector<string> splitString(const string &str, char delimiter)
{
    vector<string> splitLine; // Vector to store the split substrings
    istringstream iss(str);   // Create an input string stream and initialize it with the input string
    string token;             // Variable to store each substring

    // Read each substring from the input string stream using getline and add it to the vector
    while (getline(iss, token, delimiter)) {
        splitLine.push_back(token);
    }

    return splitLine; // Return the vector of split substrings
}

/**
 * This function reads course data from a file and creates a linked list of courses.
 * It takes the file name as input.
 *
 * @param fileName The name of the file containing course data
 * @return A pointer to the linked list of courses
 */
LinkedList *getCoursesFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName); // Read lines from the file
    LinkedList *list = new LinkedList();               // Create a new linked list

    // Process each line of the file
    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';'); // Split the line using the ';' delimiter

        // Check if the line has the correct number of elements
        if (splitLine.size() != 3) {
            cout << "Invalid format: " << fileName << endl; // Print an error message
            exit(84);                                       // Exit the program with an error code
        }

        // Create a new course object using the data from the line and add it to the linked list
        Course *c = new Course(list->getSize() + 1, splitLine[0], stoi(splitLine[1]), splitLine[2]);
        list->push_back(c, c->getId());
    }

    return list; // Return the pointer to the linked list of courses
}

/**
 * This function reads student data from a file and creates a linked list of students.
 * It takes the file name as input.
 *
 * @param fileName The name of the file containing student data
 * @return A pointer to the linked list of students
 */
LinkedList *getStudentsFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName); // Read lines from the file
    LinkedList *list = new LinkedList();               // Create a new linked list

    // Process each line of the file
    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';'); // Split the line using the ';' delimiter

        // Check if the line has the correct number of elements
        if (splitLine.size() != 1) {
            cout << "Invalid format: " << fileName << endl; // Print an error message
            exit(84);                                       // Exit the program with an error code
        }

        // Create a new student object using the data from the line and add it to the linked list
        Student *s = new Student(list->getSize() + 1, splitLine[0]);
        list->push_back(s, s->getId());
    }

    return list; // Return the pointer to the linked list of students
}

/**
 * This function reads professor data from a file and creates a linked list of professors.
 * It takes the file name as input.
 *
 * @param fileName The name of the file containing professor data
 * @return A pointer to the linked list of professors
 */
LinkedList *getProfessorsFromFile(string fileName)
{
    vector<string> lines = getLinesFromFile(fileName); // Read lines from the file
    LinkedList *list = new LinkedList();               // Create a new linked list

    // Process each line of the file
    for (const auto &line : lines) {
        vector<string> splitLine = splitString(line, ';'); // Split the line using the ';' delimiter

        // Check if the line has the correct number of elements
        if (splitLine.size() != 1) {
            cout << "Invalid format: " << fileName << endl; // Print an error message
            exit(84);                                       // Exit the program with an error code
        }

        // Create a new professor object using the data from the line and add it to the linked list
        Professor *p = new Professor(list->getSize() + 1, splitLine[0]);
        list->push_back(p, p->getId());
    }

    return list; // Return the pointer to the linked list of professors
}

/**
 * This function displays the details of each person in the linked list of students.
 * It takes the linked list of students as input.
 *
 * @param students A pointer to the linked list of students
 */
void displayPerson(LinkedList *students)
{
    Node *current = students->getHead(); // Get the head of the linked list
    while (current) {
        // Print the ID and name of the student using static_cast to access the student-specific data
        cout << current->getID() << ": " << static_cast<Student *>(current->getData())->getName() << '\n';
        current = current->getNext(); // Move to the next node
    }
    cout << endl;                     // Print an empty line after displaying all persons
}

/**
 * This function displays the details of a specific course.
 * It takes a pointer to the course as input.
 *
 * @param course A pointer to the course to display
 */
void displayDetailsCourses(Course *course)
{
    cout << course->getName() << '\n';         // Print the name of the course
    if (course->getProfessor())
        cout << course->getProfessor() << ' '; // Print the professor assigned to the course if exists
    cout << course->getDescription() << ' ';   // Print the description of the course
    cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
         << course->getCapacity() << '\n';     // Print the capacity and number of students enrolled in the course
    displayPerson(course->getStudents());      // Display the details of the students enrolled in the course
}

/**
 * This function displays the details of each course in the linked list of courses.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 */
void displayListDetailsCourses(LinkedList *&courses)
{
    Node *current = courses->getHead();                                // Get the head of the linked list
    while (current) {
        Course *course = static_cast<Course *>(current->getData());    // Cast the data to a Course pointer
        cout << current->getID() << ": " << course->getName() << '\n'; // Print the ID and name of the course
        cout << course->getDescription() << ' ';                       // Print the description of the course
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
             << course->getCapacity() << '\n'; // Print the capacity and number of students enrolled in the course
        displayPerson(course->getStudents());  // Display the details of the students enrolled in the course
        current = current->getNext();          // Move to the next node
    }
    cout << endl;                              // Print an empty line after displaying all courses
}

/**
 * This function displays the list of courses with basic details.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 */
void displayListCourses(LinkedList *&courses)
{
    Node *current = courses->getHead();                                // Get the head of the linked list
    while (current) {
        Course *course = static_cast<Course *>(current->getData());    // Cast the data to a Course pointer
        cout << current->getID() << ": " << course->getName() << '\n'; // Print the ID and name of the course
        cout << "Capacity: " << ((course->getStudents() == nullptr) ? 0 : course->getStudents()->getSize()) << "/"
             << course->getCapacity() << '\n'; // Print the capacity and number of students enrolled in the course
        current = current->getNext();          // Move to the next node
    }
    cout << endl;                              // Print an empty line after displaying all courses
}

/**
 * This function displays the list of students and prompts the user to select a student.
 * It takes a pointer to the linked list of students as input.
 *
 * @param students A pointer to the linked list of students
 * @return A pointer to the selected student
 */
Student *displayAndGetStudent(LinkedList *students)
{
    int studentId = 0;
    cout << endl;
    displayPerson(students); // Display the list of students
    cout << "Student to select: ";
    cin >> studentId;
    Node *node = students->findByID(studentId); // Find the node with the specified student ID
    if (node == nullptr) {
        cout << "Student not found";
        return displayAndGetStudent(students); // If student not found, recursively call the function to select again
    }
    return static_cast<Student *>(node->getData()); // Cast the data to a Student pointer and return it
}

/**
 * This function displays the list of courses and prompts the user to select a course.
 * It takes a pointer to the linked list of courses as input.
 *
 * @param courses A pointer to the linked list of courses
 * @return A pointer to the selected course
 */
Course *displayAndGetCourse(LinkedList *courses)
{
    int courseId = 0;
    if (courses->getSize() == 0) {
        throw std::runtime_error("There is no course available");
    }
    cout << endl;
    displayListCourses(courses); // Display the list of courses
    cout << "Course to select: ";
    cin >> courseId;
    Node *node = courses->findByID(courseId); // Find the node with the specified course ID

    if (node == nullptr) {
        cout << "Course not found";
        return displayAndGetCourse(courses);       // If course not found, recursively call the function to select again
    }
    return static_cast<Course *>(node->getData()); // Cast the data to a Course pointer and return it
}

/**
 * This function displays and prompts the user to select a professor from the provided linked list of professors.
 * It takes a pointer to the linked list of professors as input.
 *
 * @param professors A pointer to the linked list of professors
 * @return A pointer to the selected professor
 */
Professor *displayAndGetProfessor(LinkedList *professors)
{
    int studentId = 0;
    cout << endl;
    displayPerson(professors); // Display the list of professors
    cout << "Professor to select: ";
    cin >> studentId;
    Node *node = professors->findByID(studentId);

    if (node == NULL) {
        cout << "Professor not found";
        return displayAndGetProfessor(
            professors); // If professor not found, recursively call the function to select again
    }
    return static_cast<Professor *>(node->getData()); // Cast the data to a Professor pointer and return it
}

/**
 * This function returns a new linked list containing the courses that have at least one student enrolled.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 * @return A pointer to the new linked list of courses with at least one student enrolled
 */
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

/**
 * This function returns a new linked list containing the courses that are not fully occupied.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 * @return A pointer to the new linked list of courses that are not fully occupied
 */
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

/**
 * This function adds a student to a course.
 * It takes references to the linked lists of courses and students as input.
 *
 * @param courses A reference to the linked list of courses
 * @param students A reference to the linked list of students
 */
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

/**
 * This function removes a student from a course.
 * It takes references to the linked lists of courses and students as input.
 *
 * @param courses A reference to the linked list of courses
 * @param students A reference to the linked list of students
 */
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
            cout << "Student removed successfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception &e) {
            cout << e.what() << std::endl;
        }
    }
    cout << "-----------------------------\n";
}

/**
 * This function searches for a student by name in the provided linked list of students.
 * It takes a reference to the linked list of students and a name as input.
 *
 * @param students A reference to the linked list of students
 * @param name The name of the student to search for
 * @return A pointer to the found student, or nullptr if not found
 */
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

/**
 * This function searches for a professor by name in the provided linked list of professors.
 * It takes a reference to the linked list of professors and a name as input.
 *
 * @param professors A reference to the linked list of professors
 * @param name The name of the professor to search for
 * @return A pointer to the found professor, or nullptr if not found
 */
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

/**
 * This function searches for a course by name in the provided linked list of courses.
 * It takes a reference to the linked list of courses and a name as input.
 *
 * @param courses A reference to the linked list of courses
 * @param name The name of the course to search for
 * @return A pointer to the found course, or nullptr if not found
 */
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

/**
 * This function creates a new student and adds it to the linked list of students.
 * It takes a reference to the linked list of students as input.
 *
 * @param students A reference to the linked list of students
 */
void createStudent(LinkedList *&students)
{
    std::string studentFirstName = "";
    std::string studentLastName = "";
    cout << endl;
    cin.ignore(); // Discard any remaining characters in the input buffer
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

/**
 * This function removes a student from the linked list of students.
 * It takes a reference to the linked list of students as input.
 *
 * @param students A reference to the linked list of students
 */
void removeStudent(LinkedList *&students)
{
    Student *n = displayAndGetStudent(students);
    students->remove(n->getId());
    cout << "Student removed successfully\n";
    cout << "-----------------------------\n";
}

/**
 * This function creates a new professor and adds it to the linked list of professors.
 * It takes a reference to the linked list of professors as input.
 *
 * @param professors A reference to the linked list of professors
 */
void createProfessor(LinkedList *&professors)
{
    std::string professorFirstName = "";
    std::string professorLastName = "";
    cout << endl;
    cin.ignore(); // Discard any remaining characters in the input buffer
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

/**
 * This function removes a professor from the linked list of professors.
 * It takes a reference to the linked list of professors as input.
 *
 * @param professors A reference to the linked list of professors
 */
void removeProfessor(LinkedList *&professors)
{
    Professor *n = displayAndGetProfessor(professors);
    professors->remove(n->getId());
    cout << "Professor removed successfully\n";
    cout << "-----------------------------\n";
}

/**
 * This function creates a new course and adds it to the linked list of courses.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 */
void createCourse(LinkedList *&courses)
{
    std::string courseName = "";
    int courseCapacity = 0;
    std::string courseDescription = "";
    cout << endl;
    cin.ignore(); // Discard any remaining characters in the input buffer
    while (true) {
        cout << "Course name: ";
        cin >> courseName;
        cout << "Course capacity (number): ";
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

/**
 * This function removes a course from the linked list of courses.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 */
void removeCourse(LinkedList *&courses)
{
    Course *n = displayAndGetCourse(courses);
    courses->remove(n->getId());
    cout << "Course removed successfully\n";
    cout << "-----------------------------\n";
}

/**
 * This function assigns a professor to a course.
 * It takes references to the linked lists of courses and professors as input.
 *
 * @param courses A reference to the linked list of courses
 * @param professors A reference to the linked list of professors
 */
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
            cout << "Professor assigned successfully\n";
            displayDetailsCourses(course);
            break;
        } catch (const std::exception &e) {
            cout << e.what() << std::endl;
            break;
        }
    }
    cout << "-----------------------------\n";
}

/**
 * This function removes a professor from a course.
 * It takes a reference to the linked list of courses as input.
 *
 * @param courses A reference to the linked list of courses
 */
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
        cout << "Professor removed successfully\n";
        displayDetailsCourses(course);
    } catch (const std::exception &e) {
        cout << e.what() << std::endl;
    }
    cout << "-----------------------------\n";
}

/**
 * This function displays the main menu and prompts the user to select an option.
 *
 * @return The selected option
 */
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

/**
 * This function saves the courses to a file.
 * It takes a reference to the linked list of courses and a filename as input.
 *
 * @param courses A reference to the linked list of courses
 * @param filename The name of the file to save the courses to
 */
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

/**
 * This function saves the students to a file.
 * It takes a reference to the linked list of students and a filename as input.
 *
 * @param students A reference to the linked list of students
 * @param filename The name of the file to save the students to
 */
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

/**
 * This function saves the professors to a file.
 * It takes a reference to the linked list of professors and a filename as input.
 *
 * @param professors A reference to the linked list of professors
 * @param filename The name of the file to save the professors to
 */
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