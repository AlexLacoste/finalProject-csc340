#include "Course.hpp"
#include <iostream>

Course::Course(int id, const std::string &name, int capacity, const std::string &description)
        : id(id), name(name), capacity(capacity), description(description), professor(nullptr), studends(new LinkedList()) {}


const std::string &Course::getName() const {
    return name;
}

const std::string &Course::getDescription() const {
    return description;
}

int Course::getCapacity() const {
    return capacity;
}

int Course::getId() const {
    return id;
}

Professor *Course::getProfessor() const {
    return professor;
}

LinkedList *Course::getStudents() const {
    return studends;
}

void Course::setName(const std::string &name) {
    this->name = name;
}

void Course::setProfessor(Professor *professor) {
    this->professor = professor;
}

void Course::setStudents(LinkedList *studends) {
    this->studends = studends;
}

void Course::setDescription(const std::string &description) {
    this->description = description;
}

void Course::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Course::setId(int id) {
    this->id = id;
}

void Course::addStudents(Student *student) {
    if (this->capacity < this->studends->getSize())
        throw std::runtime_error("Class full");
    if (this->getStudents()->find_by_id(student->getId()) != nullptr)
        throw std::runtime_error("Student already in class");
    this->studends->push_back(student, student->getId());
}

void Course::removeStudents(int studentID) {
    if (this->getStudents()->find_by_id(studentID) == nullptr)
        throw std::runtime_error("Student not found in this class");
    this->studends->remove(studentID);
}
