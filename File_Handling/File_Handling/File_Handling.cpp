/********************************************************************************
  * @file           : File_Handling.c
  * @brief          : Main program body
  ******************************************************************************
  * @author         : Jabed-Akhtar (GitHub)
  * @date           : 02.10.2022
  ******************************************************************************
  * Description:
  *     - A simple of File Handling functionalities.
  *     - Here, records of students are recorded (for e.g.: Roll No., Name of student,
  *       marks get on subjects, total mark and percentage obtained.
  *     - Functions:
  *         |- create               :   Creating new student record (will replace old data)
  *         |- display              :   Displaying recorded records
  *         |- append               :   Appending new data/records of student(s)
  *         |- noofrec              :   Displaying number of records
  *         |- search_withRollNr    :   Searching for record with Roll No.
  *         |- update               :   Updating any recorded Data
  *         |- delete_rec           :   deleting any record
  *         |- sort_byTotal_onScreen:   sorting recorded Data by Total-Marks (only on Screen)
  *         |- sort_byTotal_inFile  :   sorting recorded Data by Total-Marks (saving to file)
  *         |- sort_byName_onScreen :   sorting recorded Data by Name (only on Screen)
  *******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // to avoid errror while using fopen

/* Includes --------------------------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Private typedef -------------------------------------------------------------*/
typedef struct student {
    int rno;
    char name[20];
    struct subject {
        int scode;
        char sname[20];
        int mark;
    }sub[3];
    int total;
    float per;
}student;

/* Declaration of functions ----------------------------------------------------*/
void create();
void display();
void append();
void noofrec();
void search_withRollNr();
void update();
void delete_rec();
void sort_byTotal_onScreen();
void sort_byTotal_inFile();
void sort_byName_onScreen();

/*
* Main-Function ----------------------------------------------------------------//
*/
int main()
{
    int op; // variable for user inputs
    do {
        printf("\n------------------------------------------------------------------------");
        printf("\n1. CREATE");
        printf("\n2. DISPLAY");
        printf("\n3. APPEND");
        printf("\n4. NO. OF RECORDS");
        printf("\n5. SEARCH FOR RECORDS (WITH ROLL-NR.)");
        printf("\n6. UPDATE");
        printf("\n7. DELETE");
        printf("\n8. SORT BY TOTAL DESC - ON SCREEN");
        printf("\n9. SORT BY TOTAL DESC - IN FILE");
        printf("\n10. SORT BY NAME - ON SCREEN");
        printf("\n0. EXIT");

        // User Choice/Input
        printf("\n\nEnter Your Choise: ");
        scanf_s("%d", &op);

        switch (op) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                append();
                break;
            case 4:
                noofrec();
                break;
            case 5:
                search_withRollNr();
                break;
            case 6:
                update();
                break;
            case 7:
                delete_rec();
                break;
            case 8:
                sort_byTotal_onScreen();
                break;
            case 9:
                sort_byTotal_inFile();
                break;
            case 10:
                sort_byName_onScreen();
                break;
        }
    } while (op != 0); // exit loop and end programm

    return 0;
}

/* Function - create()
 * info: to create new data/record
 * IMPORTANT: Old record/data will be deleted
 */
void create() {
    student* s;
    FILE* fp;
    int n, i, j;
    printf("!!! Old recorded Data/Record would be removed from File.");
    printf("\nEnter how many students to be created: ");
    scanf_s("%d", &n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("studentsRec.txt", "w");

    // Getting data of student(s) from user
    for (i = 0; i < n; i++) {
        s[i].total = 0;
        s[i].per = 0;

        printf("Enter Roll-No.: ");
        scanf_s("%d", &s[i]);
        fflush(stdin);
        printf("Enter Name: ");
        scanf_s("%s", s[i].name, _countof(s[i].name));
        for (j = 0; j < 3; j++) {
            printf("Enter Marks of subject-%d: ", j + 1);
            scanf_s("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per += s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}

/* Function - display()
 * info: to display recorded data
 */
void display() {
    student s1;
    FILE* fp;
    int j;
    fp = fopen("studentsRec.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        // printf("File not found.\n");
        return; // or exit(1);
    }

    // Displaying/Printing Data from file on Screen
    printf("\nRoll-Nr. - Name -------- Sub-1 - Sub-2 - Sub-3 --- Total --- Percentage");
    while (fread(&s1, sizeof(student), 1, fp)) {
        printf("\n%-11d%-12s", s1.rno, s1.name);
        for (j = 0; j < 3; j++) {
            printf("%7d", s1.sub[j].mark);
        }
        printf("%10d%12.2f", s1.total, s1.per);
    }
    fclose(fp);
}

/* Function - append()
 * info: to append new data/record
 */
void append() {
    student* s;
    FILE* fp;
    int n, i, j;
    printf("Enter how many students to be appended: ");
    scanf_s("%d", &n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("studentsRec.txt", "a");

    // Getting data of student(s) from user and appending it to old data/File
    for (i = 0; i < n; i++) {
        s[i].total = 0;
        s[i].per = 0;

        printf("Enter Roll-No.: ");
        scanf_s("%d", &s[i]);
        fflush(stdin);
        printf("Enter Name: ");
        scanf_s("%s", s[i].name, _countof(s[i].name));
        for (j = 0; j < 3; j++) {
            printf("Enter Marks of subject%d: ", j + 1);
            scanf_s("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}

/* Function - noofrec()
 * info: to display total number of records of students recorded in file
 */
void noofrec() {
    student s1;
    FILE* fp;
    fp = fopen("studentsRec.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    printf("\n No. Of Records = %d.", n);
    fclose(fp);
}

/* Function - search_withRollNr()
 * info: to search and display data/student with Roll Nr.
 */
void search_withRollNr() {
    student s1;
    FILE* fp;
    int j, rno, found=0;
    fp = fopen("studentsRec.txt", "r");
    printf("Enter Roll-Nr. to Search: ");
    scanf_s("%d", &rno);

    // Searching for Data/Record within file
    while (fread(&s1, sizeof(student), 1, fp)) {
        if (s1.rno == rno) {
            found = 1;
            printf("\n%-11d%-12s", s1.rno, s1.name);
            for (j = 0; j < 3; j++) {
                printf("%7d", s1.sub[j].mark);
            }
            printf("%10d%12.2f", s1.total, s1.per);
        }
    }
    if (!found)
        printf("Record not fould!");
    fclose(fp);
}

/* Function - update()
 * info: to update recorded data/student in File
 */
void update() {
    student s1;
    FILE *fp, *fp1;
    int j, rno, found = 0;
    fp = fopen("studentsRec.txt", "r");
    fp1 = fopen("tmp.txt", "w");
    printf("Enter Roll-Nr. to Update: ");
    scanf_s("%d", &rno);

    // Searching for record with roll no. and updating with new data from User-Input
    while (fread(&s1, sizeof(student), 1, fp)) {
        if (s1.rno == rno) {
            s1.total = 0;
            s1.per = 0;
            found = 1;
            fflush(stdin);
            printf("Enter New Name: ");
            scanf_s("%s", s1.name, _countof(s1.name));
            for (j = 0; j < 3; j++) {
                printf("Enter New Marks of subject%d: ", j + 1);
                scanf_s("%d", &s1.sub[j].mark);
                s1.total += s1.sub[j].mark;
            }
            s1.per = s1.total / 3.0;
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);

    // Putting changed data into 'studentsRec.txt' file
    if (found) {
        fp1 = fopen("tmp.txt", "r");
        fp = fopen("studentsRec.txt", "w");

        while (fread(&s1, sizeof(student), 1, fp1)) {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        
    }
    else
        printf("Record not fould!");

    fclose(fp);
    fclose(fp1);
}

/* Function - delete_rec()
 * info: to delete recorded data/student in File
 */
void delete_rec() {
    student s1;
    FILE* fp, * fp1;
    int j, rno, found = 0;
    fp = fopen("studentsRec.txt", "r");
    fp1 = fopen("tmp.txt", "w");
    printf("Enter Roll-Nr. to Delete: ");
    scanf_s("%d", &rno);

    // Not recording data / deleting data
    while (fread(&s1, sizeof(student), 1, fp)) {
        if (s1.rno == rno) {
            found = 1;
        }
        else
            fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);

    // Putting changed data into 'studentsRec.txt' file
    if (found) {
        fp1 = fopen("tmp.txt", "r");
        fp = fopen("studentsRec.txt", "w");

        while (fread(&s1, sizeof(student), 1, fp1)) {
            fwrite(&s1, sizeof(student), 1, fp);
        }

    }
    else
        printf("Record not fould!");

    fclose(fp);
    fclose(fp1);
}

/* Function - sort_byTotal_onScreen()
 * info: to sort the data by Total Marks in descending and only on Screen
 */
void sort_byTotal_onScreen() {
    student *s, s1;
    FILE *fp;
    int i, j;
    fp = fopen("studentsRec.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);

    // Reading Data/record
    for (i = 0; i < n; i++) {
        fread(&s[i], sizeof(student), 1, fp);
    }

    // Swapping/Sorting Data
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].total < s[j].total) {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    // Displaying/Printing sorted Data on Screen
    for (i = 0; i < n; i++) {
        printf("\n%-11d%-12s", s[i].rno, s[i].name);
        for (j = 0; j < 3; j++) {
            printf("%7d", s[i].sub[j].mark);
        }
        printf("%10d%12.2f", s[i].total, s[i].per);
    }
    fclose(fp);
}

/* Function - sort_byTotal_inFile()
 * info: to sort the data by Total Marks in descending and save the sorted data in file
 */
void sort_byTotal_inFile() {
    student* s, s1;
    FILE* fp;
    int i, j;
    fp = fopen("studentsRec.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);

    // Reading Data/record
    for (i = 0; i < n; i++) {
        fread(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
    
    // Swapping/Sorting Data
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].total < s[j].total) {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    // Writting sorted Data in File
    fp = fopen("studentsRec.txt", "w");
    for (i = 0; i < n; i++) {
        printf("\n%-11d%-12s", s[i].rno, s[i].name);
        for (j = 0; j < 3; j++) {
            printf("%7d", s[i].sub[j].mark);
        }
        printf("%10d%12.2f", s[i].total, s[i].per);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}

/* Function - sort_byName_onScreen()
 * info: to sort the data by name in ascending and only on Screen
 */
void sort_byName_onScreen() {
    student *s, s1;
    FILE* fp;
    int i, j;
    fp = fopen("studentsRec.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);

    // Reading Data/record
    for (i = 0; i < n; i++) {
        fread(&s[i], sizeof(student), 1, fp);
    }

    // Swapping/Sorting Data
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(s[i].name, s[j].name)>0) {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    // Displaying/Printing sorted Data on Screen
    for (i = 0; i < n; i++) {
        printf("\n%-11d%-12s", s[i].rno, s[i].name);
        for (j = 0; j < 3; j++) {
            printf("%7d", s[i].sub[j].mark);
        }
        printf("%10d%12.2f", s[i].total, s[i].per);
    }
    fclose(fp);
}

/* ************************* END OF FILE ************************************** */