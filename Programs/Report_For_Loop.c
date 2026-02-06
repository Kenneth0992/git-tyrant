#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ID[20];
    char name[50];
    float GPA;
} Student;

void showMenu();
void add(Student **arr, int *size);
void search(Student *arr, int size);
void display(int count, Student *people);

int main(){

    Student *people = NULL;
    int count = 0;
    int option; 

    do{
       
        showMenu();

        printf("Enter the number of the option: ");
        scanf("%d", &option);

        while(getchar() != '\n');

        switch(option){
            case 1:
                add(&people, &count);
                break;
            case 2:
                search(people, count);
                break;
            case 3:
                display(count, people);
                break;
            case 5:
                printf("\nEXITING...\n\n");
                free(people);
                break;
            default:
                printf("\nINVALID INPUT\n");
                break;
        }

    } while(option != 5);

    return 0;
}

void showMenu(){
    printf("\n<----------| MENU |---------->\n\n");
    printf("(1) Add Student\n");
    printf("(2) Search Student by ID\n");
    printf("(3) Display all students\n");
    printf("(4) Sort Students by GPA\n");
    printf("(5) Save & Exit\n");
}

void add(Student **arr, int *size){
    Student temp;

    printf("Enter ID: ");
    fgets(temp.ID, sizeof(temp.ID), stdin);
    temp.ID[strcspn(temp.ID, "\n")] = '\0';


    printf("Enter name of the student: ");
    fgets(temp.name, sizeof(temp.name), stdin);
    temp.name[strcspn(temp.name, "\n")] = '\0'; // remove newline

    printf("Enter GPA: ");
    while (scanf("%f", &temp.GPA) != 1) {
        printf("Invalid GPA. Enter again: ");
        while (getchar() != '\n');
    }

    *arr = realloc(*arr, (*size + 1) * sizeof(Student));

    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    (*arr)[*size] = temp;
    (*size)++;

    printf("Student added successfully!\n");
}


void search(Student *arr, int size){
    Student temp;
    int id;
    printf("\nEnter ID to search: ");
    fgets(temp.ID, sizeof(temp.ID), stdin);

    for(int i = 0; i < size; i++){
        if(arr[i].ID == temp.ID){
            printf("Student found: %s %s %.2f\n", arr[i].ID, arr[i].name, arr[i].GPA);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void display(int count, Student *people){
    printf("\n<-----| ENROLLED STUDENTS |----->\n");

    for(int i = 0; i < count; i++){
        printf("%d: %s %s %.2f\n", i + 1, people[i].ID, people[i].name, people[i].GPA);
    }
}
