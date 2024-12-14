#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int ID;
    float marks;
};

int num_students = 0;
struct Student students[100];

void addStudent() {
    struct Student newStudent;
    
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    
    printf("Enter student ID: ");
    scanf("%d", &newStudent.ID);
    
    printf("Enter student marks: \n");
    printf("Algorithms: \t");
    scanf("%f", &newStudent.marks);
    printf("Programming: \t");
    scanf("%f", &newStudent.marks);
    printf("Digital Electronics: \t");
    scanf("%f", &newStudent.marks);
    printf("Digital Literacy: \t");
    scanf("%f", &newStudent.marks);
    printf("Engineering Mathematics: \t");
    scanf("%f", &newStudent.marks);
    
    
    printf("Student created successfully!\n\n");
    
    students[num_students] = newStudent;
    num_students++;

}

void displayStudents() {
	int i;
    for (i = 0; i < num_students; i++) {
        printf("Student %d\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].ID);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int ID;
    printf("Enter student ID to search: ");
    scanf("%d", &ID);
    
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].ID == ID) {
            printf("Student found!\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].ID);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    
    printf("Student not found\n");
}

void sortStudents() {
	int i;
    for (i = 0; i < num_students-1; i++) {
    	int j;
        for (j = 0; j < num_students-i-1; j++) {
            if (students[j].marks < students[j+1].marks) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    
    printf("Students sorted by marks\n");
}

void deleteStudent() {
    int ID;
    printf("Enter student ID to delete: ");
    scanf("%d", &ID);
    
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].ID == ID) {
        	int j;
            for (j = i; j < num_students-1; j++) {
                students[j] = students[j+1];

            }
            num_students--;
            printf("Student deleted\n");
            return;
        }
    }
    
    printf("Student not found\n");
}

void identifyTopper() {
    float max_marks = 0;
    int index = -1;
    
    int i;
    for (i = 0; i < num_students; i++) {
        if (students[i].marks > max_marks) {
            max_marks = students[i].marks;
            index = i;
        }
    }
    
    if (index != -1) {
        printf("Topper: %s\n", students[index].name);
    } else {
        printf("No students available\n");
    }
}


int main() {
    int choice;
    
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Sort Students\n");
        printf("5. Delete Student\n");
        printf("6. Identify Topper\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:

                sortStudents();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                identifyTopper();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
        }
    } while (choice != 7);
    
    return 0;
}

