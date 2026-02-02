#include "student.h"

// Add a new student to the linked list (sorted by ID for faster search)
void addStudent(Student** head, int id, char* name, int age, char* department, float gpa) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    strcpy(newStudent->department, department);
    newStudent->gpa = gpa;
    newStudent->next = NULL;
    newStudent->prev = NULL;

    // Insert in sorted order by ID
    if (*head == NULL) {
        *head = newStudent;
    } else if ((*head)->id >= id) {
        newStudent->next = *head;
        (*head)->prev = newStudent;
        *head = newStudent;
    } else {
        Student* current = *head;
        while (current->next != NULL && current->next->id < id) {
            current = current->next;
        }
        newStudent->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newStudent;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
}

// Delete a student by ID
void deleteStudent(Student** head, int id) {
    Student* temp = *head;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("%sStudent with ID %d deleted.\n%s", GREEN, id, RESET);
        return;
    }

    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%sStudent with ID %d not found.\n%s", RED, id, RESET);
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("%sStudent with ID %d deleted.\n%s", GREEN, id, RESET);
}

// Search for a student by ID (binary search like on sorted list, but linear for simplicity)
Student* searchStudent(Student* head, int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Search and display students by name
void searchByName(Student* head, char* name) {
    Student* current = head;
    int found = 0;
    printf("%s\nStudents with name '%s':\n%s", BOLD MAGENTA, name, RESET);
    printf("%sID\tName\t\tAge\tDepartment\tGPA\n%s", BOLD, RESET);
    printf("---------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s%d\t%s\t\t%d\t%s\t\t%.2f\n%s", GREEN, current->id, current->name, current->age, current->department, current->gpa, RESET);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("%sNo students found with name '%s'.\n%s", RED, name, RESET);
    } else {
        printf("---------------------------------------------\n");
    }
}

// Search and display students by department
void searchByDepartment(Student* head, char* department) {
    Student* current = head;
    int found = 0;
    printf("%s\nStudents in department '%s':\n%s", BOLD MAGENTA, department, RESET);
    printf("%sID\tName\t\tAge\tDepartment\tGPA\n%s", BOLD, RESET);
    printf("---------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->department, department) == 0) {
            printf("%s%d\t%s\t\t%d\t%s\t\t%.2f\n%s", GREEN, current->id, current->name, current->age, current->department, current->gpa, RESET);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("%sNo students found in department '%s'.\n%s", RED, department, RESET);
    } else {
        printf("---------------------------------------------\n");
    }
}

// Search and display students by GPA range
void searchByGPARange(Student* head, float minGPA, float maxGPA) {
    Student* current = head;
    int found = 0;
    printf("%s\nStudents with GPA between %.2f and %.2f:\n%s", BOLD MAGENTA, minGPA, maxGPA, RESET);
    printf("%sID\tName\t\tAge\tDepartment\tGPA\n%s", BOLD, RESET);
    printf("---------------------------------------------\n");
    while (current != NULL) {
        if (current->gpa >= minGPA && current->gpa <= maxGPA) {
            printf("%s%d\t%s\t\t%d\t%s\t\t%.2f\n%s", GREEN, current->id, current->name, current->age, current->department, current->gpa, RESET);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("%sNo students found in the GPA range %.2f - %.2f.\n%s", RED, minGPA, maxGPA, RESET);
    } else {
        printf("---------------------------------------------\n");
    }
}

// Update a student by ID
void updateStudent(Student** head, int id, char* name, int age, char* department, float gpa) {
    Student* student = searchStudent(*head, id);
    if (student) {
        strcpy(student->name, name);
        student->age = age;
        strcpy(student->department, department);
        student->gpa = gpa;
        printf("%sStudent with ID %d updated.\n%s", GREEN, id, RESET);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

// Sort the linked list by GPA (descending)
void sortByGPA(Student** head) {
    if (*head == NULL) return;
    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->gpa < ptr1->next->gpa) {
                // Swap data
                int tempId = ptr1->id;
                char tempName[50];
                strcpy(tempName, ptr1->name);
                int tempAge = ptr1->age;
                char tempDept[30];
                strcpy(tempDept, ptr1->department);
                float tempGpa = ptr1->gpa;

                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);
                ptr1->age = ptr1->next->age;
                strcpy(ptr1->department, ptr1->next->department);
                ptr1->gpa = ptr1->next->gpa;

                ptr1->next->id = tempId;
                strcpy(ptr1->next->name, tempName);
                ptr1->next->age = tempAge;
                strcpy(ptr1->next->department, tempDept);
                ptr1->next->gpa = tempGpa;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Display students ranked by GPA
void displayRankedByGPA(Student* head) {
    if (head == NULL) {
        printf("No students in the system.\n");
        return;
    }
    // Create a copy of the list to sort
    Student* sortedHead = NULL;
    Student* current = head;
    while (current != NULL) {
        addStudent(&sortedHead, current->id, current->name, current->age, current->department, current->gpa);
        current = current->next;
    }
    sortByGPA(&sortedHead);

    printf("%s\nStudents Ranked by GPA:\n%s", BOLD BLUE, RESET);
    printf("%sRank\tID\tName\t\tAge\tDepartment\tGPA\n%s", BOLD, RESET);
    printf("-------------------------------------------------\n");
    int rank = 1;
    float prevGPA = -1.0;
    current = sortedHead;
    while (current != NULL) {
        if (current->gpa != prevGPA) {
            rank = (prevGPA == -1.0) ? 1 : rank + 1;  // For first, rank=1, else increment
        }
        // If same GPA, keep same rank
        printf("%d\t%d\t%s\t\t%d\t%s\t\t%.2f\n", rank, current->id, current->name, current->age, current->department, current->gpa);
        prevGPA = current->gpa;
        current = current->next;
    }
    printf("-------------------------------------------------\n");
    freeList(sortedHead);
}

// Display statistics
void displayStatistics(Student* head) {
    if (head == NULL) {
        printf("%sNo students in the system.\n%s", RED, RESET);
        return;
    }
    int count = 0;
    float totalGPA = 0.0;
    float highestGPA = head->gpa;
    float lowestGPA = head->gpa;
    Student* current = head;
    while (current != NULL) {
        count++;
        totalGPA += current->gpa;
        if (current->gpa > highestGPA) highestGPA = current->gpa;
        if (current->gpa < lowestGPA) lowestGPA = current->gpa;
        current = current->next;
    }
    float averageGPA = totalGPA / count;
    printf("%s\nStatistics:\n%s", BOLD GREEN, RESET);
    printf("Total Students: %d\n", count);
    printf("Average GPA: %.2f\n", averageGPA);
    printf("Highest GPA: %.2f\n", highestGPA);
    printf("Lowest GPA: %.2f\n", lowestGPA);
}

// Display all students
void displayStudents(Student* head) {
    if (head == NULL) {
        printf("%sNo students in the system.\n%s", RED, RESET);
        return;
    }
    Student* current = head;
    printf("%s\nStudent List:\n%s", BOLD BLUE, RESET);
    printf("%sID\tName\t\tAge\tDepartment\tGPA\n%s", BOLD, RESET);
    printf("---------------------------------------------\n");
    while (current != NULL) {
        printf("%d\t%s\t\t%d\t%s\t\t%.2f\n", current->id, current->name, current->age, current->department, current->gpa);
        current = current->next;
    }
    printf("---------------------------------------------\n");
}

// Save students to file
void saveToFile(Student* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%d,%s,%d,%s,%.2f\n", current->id, current->name, current->age, current->department, current->gpa);
        current = current->next;
    }
    fclose(file);
    printf("%sData saved to %s\n%s", GREEN, filename, RESET);
}

// Load students from file
void loadFromFile(Student** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading! File may not exist.\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int id, age;
        char name[50], department[30];
        float gpa;
        if (sscanf(line, "%d,%49[^,],%d,%29[^,],%f", &id, name, &age, department, &gpa) == 5) {
            addStudent(head, id, name, age, department, gpa);
        }
    }
    fclose(file);
    printf("%sData loaded from %s\n%s", GREEN, filename, RESET);
}

// Free the linked list
void freeList(Student* head) {
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }
}