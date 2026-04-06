#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   SCHOOL ADMINISTRATION SYSTEM USING BST
   FEATURES:
   - CRUD Operations
   - Dynamic Memory (Strings)
   - Grade System
   - Topper Detection
   - Filter by Marks
   - Memory Safe (free used properly)
   ========================================================= */


/* =========================================================
   STRUCTURE DEFINITION
   ========================================================= */
typedef struct Student {
    int id;                 // Unique student ID
    char *name;             // Dynamic string
    int age;                // Student age
    float marks;            // Student marks
    struct Student *left;   // Left child (BST)
    struct Student *right;  // Right child (BST)
} Student;


/* =========================================================
   UTILITY: PRINT LINE
   ========================================================= */
void printLine() {
    printf("========================================\n");
}


/* =========================================================
   GRADE CALCULATION FUNCTION
   ========================================================= */
char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}


/* =========================================================
   DYNAMIC STRING INPUT FUNCTION
   ========================================================= */
char* createString() {
    char temp[100];

    scanf(" %[^\n]", temp);

    char *str = (char*)malloc(strlen(temp) + 1);

    strcpy(str, temp);

    return str;
}


/* =========================================================
   CREATE NODE FUNCTION
   ========================================================= */
Student* createNode(int id) {

    Student *newNode = (Student*)malloc(sizeof(Student));

    newNode->id = id;

    printf("Enter Name: ");
    newNode->name = createString();

    printf("Enter Age: ");
    scanf("%d", &newNode->age);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* =========================================================
   INSERT INTO BST
   ========================================================= */
Student* insert(Student *root, int id) {

    if (root == NULL)
        return createNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);

    else if (id > root->id)
        root->right = insert(root->right, id);

    else
        printf("ID already exists!\n");

    return root;
}


/* =========================================================
   DISPLAY SINGLE STUDENT
   ========================================================= */
void displayStudent(Student *s) {
    if (s == NULL) return;

    printf("\nID    : %d\n", s->id);
    printf("Name  : %s\n", s->name);
    printf("Age   : %d\n", s->age);
    printf("Marks : %.2f\n", s->marks);
    printf("Grade : %c\n", calculateGrade(s->marks));
    printf("----------------------------------------\n");
}


/* =========================================================
   INORDER TRAVERSAL
   ========================================================= */
void inorder(Student *root) {

    if (root != NULL) {

        inorder(root->left);

        displayStudent(root);

        inorder(root->right);
    }
}


/* =========================================================
   SEARCH FUNCTION
   ========================================================= */
Student* search(Student *root, int id) {

    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}


/* =========================================================
   FIND MIN NODE
   ========================================================= */
Student* findMin(Student *root) {

    while (root && root->left != NULL)
        root = root->left;

    return root;
}


/* =========================================================
   DELETE NODE
   ========================================================= */
Student* deleteNode(Student *root, int id) {

    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);

    else if (id > root->id)
        root->right = deleteNode(root->right, id);

    else {

        if (root->left == NULL) {
            Student *temp = root->right;

            free(root->name);
            free(root);

            return temp;
        }

        else if (root->right == NULL) {
            Student *temp = root->left;

            free(root->name);
            free(root);

            return temp;
        }

        Student *temp = findMin(root->right);

        root->id = temp->id;

        free(root->name);
        root->name = (char*)malloc(strlen(temp->name) + 1);
        strcpy(root->name, temp->name);

        root->age = temp->age;
        root->marks = temp->marks;

        root->right = deleteNode(root->right, temp->id);
    }

    return root;
}


/* =========================================================
   UPDATE STUDENT
   ========================================================= */
void updateStudent(Student *root, int id) {

    Student *s = search(root, id);

    if (s == NULL) {
        printf("Student not found!\n");
        return;
    }

    printf("Enter New Name: ");
    free(s->name);
    s->name = createString();

    printf("Enter New Age: ");
    scanf("%d", &s->age);

    printf("Enter New Marks: ");
    scanf("%f", &s->marks);

    printf("Updated successfully!\n");
}


/* =========================================================
   COUNT STUDENTS
   ========================================================= */
int countStudents(Student *root) {

    if (root == NULL)
        return 0;

    return 1 + countStudents(root->left) + countStudents(root->right);
}


/* =========================================================
   FIND TOPPER
   ========================================================= */
void findTopper(Student *root, Student **topper) {

    if (root == NULL)
        return;

    findTopper(root->left, topper);

    if (*topper == NULL || root->marks > (*topper)->marks)
        *topper = root;

    findTopper(root->right, topper);
}


/* =========================================================
   DISPLAY ABOVE MARKS
   ========================================================= */
void displayAboveMarks(Student *root, float threshold) {

    if (root != NULL) {

        displayAboveMarks(root->left, threshold);

        if (root->marks > threshold)
            displayStudent(root);

        displayAboveMarks(root->right, threshold);
    }
}


/* =========================================================
   FREE ENTIRE TREE
   ========================================================= */
void freeTree(Student *root) {

    if (root != NULL) {

        freeTree(root->left);
        freeTree(root->right);

        free(root->name);
        free(root);
    }
}


/* =========================================================
   MENU DISPLAY
   ========================================================= */
void menu() {

    printLine();
    printf(" SCHOOL ADMINISTRATION SYSTEM\n");
    printLine();

    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Count Students\n");
    printf("7. Find Topper\n");
    printf("8. Students Above Marks\n");
    printf("0. Exit\n");

    printLine();
}


/* =========================================================
   MAIN FUNCTION
   ========================================================= */
int main() {

    Student *root = NULL;

    int choice;
    int id;
    float threshold;

    while (1) {

        menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &id);
            root = insert(root, id);
            break;

        case 2:
            printf("\n--- STUDENT RECORDS ---\n");
            inorder(root);
            break;

        case 3: {
            printf("Enter ID to search: ");
            scanf("%d", &id);

            Student *s = search(root, id);

            if (s != NULL)
                displayStudent(s);
            else
                printf("Student not found!\n");

            break;
        }

        case 4:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            updateStudent(root, id);
            break;

        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            root = deleteNode(root, id);
            break;

        case 6:
            printf("Total Students: %d\n", countStudents(root));
            break;

        case 7: {
            Student *topper = NULL;

            findTopper(root, &topper);

            if (topper != NULL) {
                printf("\n🏆 TOPPER DETAILS:\n");
                displayStudent(topper);
            }
            else
                printf("No records available!\n");

            break;
        }

        case 8:
            printf("Enter minimum marks: ");
            scanf("%f", &threshold);

            printf("\nStudents scoring above %.2f:\n", threshold);
            displayAboveMarks(root, threshold);
            break;

        case 0:
            printf("Freeing memory...\n");
            freeTree(root);
            printf("Program exited safely.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}