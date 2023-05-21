# University Management System

This is a C++ program that provides a command-line interface for managing a university system. It includes classes such as Student, Professor, and Course, all linked via LinkedLists. The system allows for CRUD operations (Create, Read, Update, Delete) on students, professors, and courses.

The code is organized into several functions, each handling a particular aspect of the system:

<br/>

## Functions

<br/>

**splitString**: This function takes a string and a delimiter and returns a vector of strings split based on the delimiter.

**getCoursesFromFile**, **getStudentsFromFile**, **getProfessorsFromFile**: These functions read courses, students, and professors from a file respectively. The data in the file is split into elements using the ';' character as a delimiter. Each element is then used to create a new Course, Student, or Professor object, which is added to a LinkedList.

**displayPerson**: This function takes a LinkedList of Person type objects (students or professors) and prints out the ID and name of each person.

**displayDetailsCourses**, **displayListDetailsCourses**, **displayListCourses**: These functions display the details of courses.

**displayAndGetStudent**, **displayAndGetCourse**, **displayAndGetProfessor**: These functions display the list of students, courses or professors and then prompt the user to select one based on their ID. The selected object is returned.

**getCoursesNoEmpty**, **getCoursesNoFull**: These functions return a LinkedList of courses that are not empty or not full respectively.

**addStudent**, **removeStudent**: These functions allow adding or removing a student from a course.

**getStudentsByName**, **getProfessorByName**, **getCourseByName**: These functions return a Student, Professor, or Course object respectively, given a name.

**createStudent**, **createProfessor**, **createCourse**: These functions allow creating a new student, professor, or course.

**removeStudent**, **removeProfessor**, **removeCourse**: These functions allow removing a student, professor, or course.

**assignProfessor**, **deleteProfessorFromCourse**: These functions allow assigning a professor to a course or removing a professor from a course.

**displayMenu**: This function displays the available options to the user and returns the user's choice.

**saveCoursesToFile**, **saveStudentsToFile**, **saveProfessorsToFile**: These functions save the current state of courses, students, or professors to a file.

**loadCoursesFromFile**, **loadStudentsFromFile**, **loadProfessorsFromFile**: These functions load the state of courses, students, or professors from a file.

<br/>

## Usage

<br/>

The program starts by displaying a menu to the user with various options such as creating or removing a student, professor, or course, enrolling or dropping a student from a course, assigning or removing a professor from a course, displaying all students, professors, or courses, and quitting the program. The user can select an option by entering the corresponding number. The state of the system can be saved to or loaded from a file.

<br/>

## Installation

<br/>

Clone the repository and run the following command in the root directory:

```bash
make
./finalProject
and follow the instructions on the menu
```

The program will read files from the shool-files directory courses.txt, professors.txt, students.txt and save files to the same directory into courses-finished.txt, professors-finished.txt, students-finished.txt.

and to clean the directory:

```bash
make fclean
```

<br/>

## Format

<br/>

We use the file .clang-format to format our code. To format the code, run the following command in the root directory:

```bash
make format
```

Install clang-format if you don't have it:

For macOS:
```bash
brew install clang-format
```

For Linux:
```bash
sudo apt install clang-format
```

<br/>

## Authors

<br/>

- [Alexandre Lacoste](https://github.com/AlexLacoste)
- [Théo Fargeas](https://github.com/theofrgs)
- [Umaran Ahmadzai](https://github.com/Umaran-Ahmadzai)
- [Mario Dominguez](https://github.com/MarioDominguez1)