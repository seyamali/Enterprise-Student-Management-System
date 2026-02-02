#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

// Student structure
typedef struct Student {
    int id;
    char name[50];
    int age;
    char department[30];
    float gpa;
    struct Student* next;
    struct Student* prev;
} Student;

// Function prototypes
void addStudent(Student** head, int id, char* name, int age, char* department, float gpa);
void deleteStudent(Student** head, int id);
Student* searchStudent(Student* head, int id);
void displayStudents(Student* head);
void updateStudent(Student** head, int id, char* name, int age, char* department, float gpa);
void sortByGPA(Student** head);
void displayRankedByGPA(Student* head);
void displayStatistics(Student* head);
void searchByName(Student* head, char* name);
void searchByDepartment(Student* head, char* department);
void searchByGPARange(Student* head, float minGPA, float maxGPA);
void saveToFile(Student* head, const char* filename);
void loadFromFile(Student** head, const char* filename);
void freeList(Student* head);

#endif // STUDENT_H