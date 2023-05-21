#ifndef COURSE_HPP_
#define COURSE_HPP_

#include <LinkedList.hpp>
#include <Professor.hpp>
#include <Student.hpp>
#include <string>

class Course {
  public:
    /**
     * Constructor for the Course class.
     *
     * @param id The course ID.
     * @param name The name of the course.
     * @param capacity The maximum capacity of the course.
     * @param description The description of the course.
     */
    Course(int id, const std::string &name, int capacity, const std::string &description);

    /**
     * Default destructor for the Course class.
     */
    ~Course() noexcept = default;

    /**
     * Retrieves the name of the course.
     *
     * @return The name of the course.
     */
    const std::string &getName() const;

    /**
     * Retrieves the description of the course.
     *
     * @return The description of the course.
     */
    const std::string &getDescription() const;

    /**
     * Retrieves the maximum capacity of the course.
     *
     * @return The maximum capacity of the course.
     */
    int getCapacity() const;

    /**
     * Retrieves the professor teaching the course.
     *
     * @return A pointer to the Professor object representing the course professor.
     */
    Professor *getProfessor() const;

    /**
     * Retrieves the linked list of students enrolled in the course.
     *
     * @return A pointer to the LinkedList object representing the list of students.
     */
    LinkedList *getStudents() const;

    /**
     * Retrieves the ID of the course.
     *
     * @return The ID of the course.
     */
    int getId() const;

    /**
     * Sets the name of the course.
     *
     * @param name The new name of the course.
     */
    void setName(const std::string &name);

    /**
     * Sets the professor teaching the course.
     *
     * @param professor A pointer to the Professor object representing the course professor.
     */
    void setProfessor(Professor *professor);

    /**
     * Sets the linked list of students enrolled in the course.
     *
     * @param students A pointer to the LinkedList object representing the list of students.
     */
    void setStudents(LinkedList *students);

    /**
     * Sets the description of the course.
     *
     * @param description The new description of the course.
     */
    void setDescription(const std::string &description);

    /**
     * Sets the maximum capacity of the course.
     *
     * @param capacity The new maximum capacity of the course.
     */
    void setCapacity(int capacity);

    /**
     * Sets the ID of the course.
     *
     * @param id The new ID of the course.
     */
    void setId(const int id);

    /**
     * Adds a student to the course.
     *
     * @param student A pointer to the Student object representing the student to be added.
     */
    void addStudents(Student *student);

    /**
     * Removes a student from the course.
     *
     * @param studentID The ID of the student to be removed.
     */
    void removeStudents(int studentID);

  private:
    std::string name;        // The name of the course.
    std::string description; // The description of the course.
    Professor *professor;    // The professor teaching the course.
    LinkedList *students;    // The linked list of students enrolled in the course.
    int capacity;            // The maximum capacity of the course.
    int id;                  // The ID of the course.
};

#endif