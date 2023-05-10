#include <fstream>
#include <sstream>
#include "Course.hpp"
#include "Professor.hpp"
#include "Student.hpp"

#define STUDENTS_FILE   "school-files/students.txt"
#define PROFESSORS_FILE "school-files/professors.txt"
#define COURSES_FILE    "school-files/courses.txt"

#define STUDENTS_FINISHED_FILE   "../school-files/students-finished.txt"
#define PROFESSORS_FINISHED_FILE "../school-files/professors-finished.txt"
#define COURSES_FINISHED_FILE    "../school-files/courses-finished.txt"

void displayMenu()
//the display menu will show the user what options they have in the program
{
    std::cout << "University Management System" << std::endl;
    std::cout << "1. Add a student" << std::endl;
    std::cout << "2. Remove a student" << std::endl;
    std::cout << "3. Add a professor" << std::endl;
    std::cout << "4. Remove a professor" << std::endl;
    std::cout << "5. Add a course" << std::endl;
    std::cout << "6. Remove a course" << std::endl;
    std::cout << "7. Enroll a student in a course" << std::endl;
    std::cout << "8. Drop a student from a course" << std::endl;
    std::cout << "9. Assign a professor to a course" << std::endl;
    std::cout << "10. Remove a professor from a course" << std::endl;
    std::cout << "11. Display all students" << std::endl;
    std::cout << "12. Display all professors" << std::endl;
    std::cout << "13. Display all courses" << std::endl;
    std::cout << "14. Display student details" << std::endl;
    std::cout << "15. Display professor details" << std::endl;
    std::cout << "16. Quit" << std::endl;
}

std::vector<std::string> getLinesFromFile(std::string fileName)
{
    std::vector<std::string> lines;
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << fileName << std::endl;
    }

    return lines;
}

Course *getCoursesFromFile(std::string fileName)
//this gathers the files needed to run the program
{
    std::vector<std::string> lines = getLinesFromFile(fileName);
    Course *courses = nullptr;
    int id = 0;

    for (auto line : lines) {
        std::stringstream ss{line};
        std::string name;
        std::string capacity;
        ss >> name;
        ss >> capacity;

        Course *newCourse = new Course(id, name, stoi(capacity));

        if (courses == nullptr) {
            courses = newCourse;
            courses->setHead(courses);
        } else {
            if (courses->getTail() == nullptr) {
                courses->setNext(newCourse);
                courses->setTail(newCourse);
            } else {
                courses->getTail()->setNext(newCourse);
                courses->setTail(newCourse);
            }
        }
        id++;
    }

    return courses;
}

Student *getStudentsFromFile(std::string fileName)
{
    std::vector<std::string> lines = getLinesFromFile(fileName);
    Student *students = nullptr;
    int id = 0;

    for (auto line : lines) {
        Student *newStudent = new Student(id, line);

        if (students == nullptr) {
            students = newStudent;
            students->setHead(students);
        } else {
            if (students->getTail() == nullptr) {
                newStudent->setPrev(students);
                students->setNext(newStudent);
                students->setTail(newStudent);
            } else {
                students->getTail()->setNext(newStudent);
                newStudent->setPrev(students->getTail());
                students->setTail(newStudent);
            }
        }
        id++;
    }

    return students;
}

Professor *getProfessorsFromFile(std::string fileName)
{
    std::vector<std::string> lines = getLinesFromFile(fileName);
    Professor *professors = nullptr;
    int id = 0;

    for (auto line : lines) {
        Professor *newProfessor = new Professor(id, line);

        if (professors == nullptr) {
            professors = newProfessor;
            professors->setHead(professors);
        } else {
            if (professors->getTail() == nullptr) {
                newProfessor->setPrev(professors);
                professors->setNext(newProfessor);
                professors->setTail(newProfessor);
            } else {
                professors->getTail()->setNext(newProfessor);
                newProfessor->setPrev(professors->getTail());
                professors->setTail(newProfessor);
            }
        }
        id++;
    }

    return professors;
}

int main()
{
    Course *courses = getCoursesFromFile(COURSES_FILE);
    Student *students = getStudentsFromFile(STUDENTS_FILE);
    Professor *professors = getProfessorsFromFile(PROFESSORS_FILE);

    if (!courses || !students || !professors) {
        std::cout << "Error: Unable to load files" << std::endl;
        return 84;
    }

    courses->displayCourses();
    return 0;
}