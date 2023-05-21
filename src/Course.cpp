#include "Course.hpp"
#include <iostream>

Course::Course(int id, const std::string &name, int capacity, const std::string &description)
    : id(id), name(name), capacity(capacity), description(description), professor(nullptr), students(new LinkedList())
{
    /* Constructor for the Course class.
     * Initializes the member variables with the provided values:
     * - id: The course ID.
     * - name: The name of the course.
     * - capacity: The maximum capacity of the course.
     * - description: The description of the course.
     * - professor: Initially set to nullptr.
     * - students: Initializes a new LinkedList object for storing the students.
     */
}

const std::string &Course::getName() const
{
    /* Retrieves the name of the course.
     *
     * @return The name of the course.
     */
    return name;
}

const std::string &Course::getDescription() const
{
    /* Retrieves the description of the course.
     *
     * @return The description of the course.
     */
    return description;
}

int Course::getCapacity() const
{
    /* Retrieves the maximum capacity of the course.
     *
     * @return The maximum capacity of the course.
     */
    return capacity;
}

int Course::getId() const
{
    /* Retrieves the ID of the course.
     *
     * @return The ID of the course.
     */
    return id;
}

Professor *Course::getProfessor() const
{
    /* Retrieves the professor teaching the course.
     *
     * @return A pointer to the Professor object representing the course professor.
     */
    return professor;
}

LinkedList *Course::getStudents() const
{
    /* Retrieves the linked list of students enrolled in the course.
     *
     * @return A pointer to the LinkedList object representing the list of students.
     */
    return students;
}

void Course::setName(const std::string &name)
{
    /* Sets the name of the course.
     *
     * @param name The new name of the course.
     */
    this->name = name;
}

void Course::setProfessor(Professor *professor)
{
    /* Sets the professor teaching the course.
     *
     * @param professor A pointer to the Professor object representing the course professor.
     */
    this->professor = professor;
}

void Course::setStudents(LinkedList *students)
{
    /* Sets the linked list of students enrolled in the course.
     *
     * @param students A pointer to the LinkedList object representing the list of students.
     */
    this->students = students;
}

void Course::setDescription(const std::string &description)
{
    /* Sets the description of the course.
     *
     * @param description The new description of the course.
     */
    this->description = description;
}

void Course::setCapacity(int capacity)
{
    /* Sets the maximum capacity of the course.
     *
     * @param capacity The new maximum capacity of the course.
     */
    this->capacity = capacity;
}

void Course::setId(int id)
{
    /* Sets the ID of the course.
     *
     * @param id The new ID of the course.
     */
    this->id = id;
}

void Course::addStudents(Student *student)
{
    /* Adds a student to the course.
     *
     * @param student A pointer to the Student object representing the student to be added.
     */
    if (this->capacity < this->students->getSize())
        throw std::runtime_error("Class full");
    if (this->getStudents()->findByID(student->getId()) != nullptr)
        throw std::runtime_error("Student already in class");
    this->students->push_back(student, student->getId());
}

void Course::removeStudents(int studentID)
{
    /* Removes a student from the course.
     *
     * @param studentID The ID of the student to be removed.
     */
    if (this->getStudents()->findByID(studentID) == nullptr)
        throw std::runtime_error("Student not found in this class");
    this->students->remove(studentID);
}