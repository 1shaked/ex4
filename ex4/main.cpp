//
//  main.cpp
//  ex4
//
//  Created by shaked chen on 02/01/2022.
//

typedef struct {
    char* firstName;
    int id;
    int* grades;
    float avrage;
} Student;

typedef struct {
    char* teacherName;
    Student* student;
    int studentsNumber;
} ClassRoom;

#include <iostream>
#include <string.h>
#include <stdio.h>
// #include <malloc.h>

int main(int argc, const char * argv[]) {
    ClassRoom classRome;
    printf("Hello, please enter teacher name:\n");
    char teacherName[100];
    gets(teacherName);
    // teacherName.length
    int teacherLen = (int) strlen(teacherName) + 1;
    printf("%s ,%d \n", teacherName, teacherLen);
    classRome.teacherName = (char*) malloc(teacherLen * sizeof(char));
    classRome.teacherName = teacherName;
    printf("%s ,%d \n", classRome.teacherName, teacherLen);
    printf("Would you like to add a student (1) yes (else) no?\n");
    
    return 0;
}
