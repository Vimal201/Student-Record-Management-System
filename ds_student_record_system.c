//Data Structure project "student record management system using linked list"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int r_no;
    char name[30];
    char phone[15];
    float percentage;
    struct Student *next;

}*head;

void insert(int rollnumber, char *name, char *phone, float percentage)
{

    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    student->r_no = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->next = NULL;

    if (head == NULL)
    {
        // if head is NULL,then we will set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty,then we will insert student in beginning of head
        student->next = head;
        head = student;
    }
}

void search(int rollnumber)
{
    struct Student *temp = head;
    while(temp != NULL)
    {
        if(temp->r_no == rollnumber)
        {
            printf("Roll Number: %d\n", temp->r_no);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Percentage: %0.2f\n", temp->percentage);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found!!\n", rollnumber);
}

void update(int rollnumber)
{

    struct Student *temp = head;
    while (temp != NULL)
    {

        if (temp->r_no == rollnumber)
        {
            printf("Record with roll number %d has found!!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f", &temp->percentage);
            printf("Record Updated Successfully!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}

void Delete(int rollnumber)
{
    struct Student *temp1 = head;
    struct Student *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->r_no == rollnumber)
        {

            printf("Record with roll number %d Found!!!\n", rollnumber);

            if (temp1 == temp2)
            {
                //this condition will run if the record that we need to delete is the first node of the linked list
                head = head->next;
                free(temp1);
            }
            else
            {
                //temp1 is the node we need to delete
                //temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("Record Deleted Successfully!!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student's record with roll number %d is not found !!!\n",rollnumber);
}

void display()
{
    struct Student *temp = head;
    while (temp != NULL)
    {

        printf("Roll Number: %d\n", temp->r_no);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Percentage: %0.2f\n\n", temp->percentage);
        temp = temp->next;
    }
}

int main()
{
    printf("\t\t*****Student Record Management System*****\n");
    head = NULL;
    int choice;
    char name[30];
    char phone[15];
    int rollnumber;
    float percentage;
   
    do
    {   
        printf("\n1. To insert student details\n2. To search for student details\n3. To update student details\n4. To delete student details\n5. To display all student details\n6. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        system("cls");

        switch(choice)
        {
        case 1:
            //to insert student details
            printf("Enter roll number: ");
            scanf("%d", &rollnumber);
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            printf("Enter percentage: ");
            scanf("%f", &percentage);
            insert(rollnumber, name, phone, percentage);
            system("cls");
            break;
        case 2:
            //to search student details using roll number
            printf("Enter roll number to search: ");
            scanf("%d", &rollnumber);
            search(rollnumber);
            break;
        case 3:
            //to update student details
            printf("Enter roll number to update record: ");
            scanf("%d", &rollnumber);
            update(rollnumber);
            break;
           
        case 4:
            //to delete student details
            printf("Enter roll number to delete record: ");
            scanf("%d", &rollnumber);
            Delete(rollnumber);
            break;
        case 5:
            //to display all the details of the student present in the record
            display();
            break;
        case 6:
            //exit
            system("cls");
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!!\nPlease select again...");
        }
    }while (choice != 6);
}