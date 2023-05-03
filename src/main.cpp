#include "Student.hpp"

void displayMenu()
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

int main()
{
    Student student(0, "John Doe");

    std::cout << "Student name: " << student.getName() << "    Student ID: " << student.getID() << std::endl;
    return 0;
}