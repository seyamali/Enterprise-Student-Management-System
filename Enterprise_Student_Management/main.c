#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Student* head = NULL;
    int choice;
    char filename[] = "students.txt";

    // Load data from file at start
    loadFromFile(&head, filename);

    do {
        printf("%s\n========================================\n%s", BOLD CYAN, RESET);
        printf("%s   Enterprise Student Management System\n%s", BOLD CYAN, RESET);
        printf("%s========================================\n%s", BOLD CYAN, RESET);
        printf("%s1. %sAdd Student\n", YELLOW, RESET);
        printf("%s2. %sDelete Student\n", YELLOW, RESET);
        printf("%s3. %sSearch Student by ID\n", YELLOW, RESET);
        printf("%s4. %sSearch by Name\n", YELLOW, RESET);
        printf("%s5. %sSearch by Department\n", YELLOW, RESET);
        printf("%s6. %sSearch by GPA Range\n", YELLOW, RESET);
        printf("%s7. %sUpdate Student\n", YELLOW, RESET);
        printf("%s8. %sDisplay All Students\n", YELLOW, RESET);
        printf("%s9. %sDisplay Ranked by GPA\n", YELLOW, RESET);
        printf("%s10.%s Display Statistics\n", YELLOW, RESET);
        printf("%s11.%s Save Data\n", YELLOW, RESET);
        printf("%s12.%s Exit\n", YELLOW, RESET);
        printf("%sEnter your choice: %s", BOLD, RESET);
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id, age;
                char name[50], department[30];
                float gpa;
                printf("Enter ID (positive integer): ");
                scanf("%d", &id);
                if (id <= 0) {
                    printf("%sInvalid ID. Must be positive.\n%s", RED, RESET);
                    break;
                }
                if (searchStudent(head, id) != NULL) {
                    printf("%sStudent with ID %d already exists.\n%s", RED, id, RESET);
                    break;
                }
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Age (15-30): ");
                scanf("%d", &age);
                if (age < 15 || age > 30) {
                    printf("%sInvalid age. Must be between 15 and 30.\n%s", RED, RESET);
                    break;
                }
                printf("Enter Department: ");
                scanf(" %[^\n]", department);
                printf("Enter GPA (0.0-4.0): ");
                scanf("%f", &gpa);
                if (gpa < 0.0 || gpa > 4.0) {
                    printf("%sInvalid GPA. Must be between 0.0 and 4.0.\n%s", RED, RESET);
                    break;
                }
                addStudent(&head, id, name, age, department, gpa);
                saveToFile(head, filename); // Auto-save after add
                break;
            }
            case 2: {
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&head, id);
                saveToFile(head, filename); // Auto-save after delete
                break;
            }
            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Student* student = searchStudent(head, id);
                if (student) {
                    printf("%sFound: ID=%d, Name=%s, Age=%d, Department=%s, GPA=%.2f\n%s", GREEN, student->id, student->name, student->age, student->department, student->gpa, RESET);
                } else {
                    printf("%sStudent not found.\n%s", RED, RESET);
                }
                break;
            }
            case 4: {
                char name[50];
                printf("Enter Name to search: ");
                scanf(" %[^\n]", name);
                searchByName(head, name);
                break;
            }
            case 5: {
                char department[30];
                printf("Enter Department to search: ");
                scanf(" %[^\n]", department);
                searchByDepartment(head, department);
                break;
            }
            case 6: {
                float minGPA, maxGPA;
                printf("Enter minimum GPA: ");
                scanf("%f", &minGPA);
                printf("Enter maximum GPA: ");
                scanf("%f", &maxGPA);
                searchByGPARange(head, minGPA, maxGPA);
                break;
            }
            case 7: {
                int id, age;
                char name[50], department[30];
                float gpa;
                printf("Enter ID to update: ");
                scanf("%d", &id);
                if (searchStudent(head, id) == NULL) {
                    printf("%sStudent with ID %d not found.\n%s", RED, id, RESET);
                    break;
                }
                printf("Enter new Name: ");
                scanf(" %[^\n]", name);
                printf("Enter new Age (15-30): ");
                scanf("%d", &age);
                if (age < 15 || age > 30) {
                    printf("%sInvalid age. Must be between 15 and 30.\n%s", RED, RESET);
                    break;
                }
                printf("Enter new Department: ");
                scanf(" %[^\n]", department);
                printf("Enter new GPA (0.0-4.0): ");
                scanf("%f", &gpa);
                if (gpa < 0.0 || gpa > 4.0) {
                    printf("%sInvalid GPA. Must be between 0.0 and 4.0.\n%s", RED, RESET);
                    break;
                }
                updateStudent(&head, id, name, age, department, gpa);
                saveToFile(head, filename); // Auto-save after update
                break;
            }
            case 8:
                displayStudents(head);
                break;
            case 9:
                displayRankedByGPA(head);
                break;
            case 10:
                displayStatistics(head);
                break;
            case 11:
                saveToFile(head, filename);
                break;
            case 12:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 12);

    return 0;
}