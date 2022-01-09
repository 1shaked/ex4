//
//  main.cpp
//  ex4
//
//  Created by shaked chen on 02/01/2022.
//

typedef struct {
    char* username;
    int id;
    int* grades;
    double avrage;
} Student;

typedef struct {
    char* teacherName;
    Student* students;
    int studentsNumber;
} ClassRoom;

#include <iostream>
#include <string.h>
#include <stdio.h>
// #include <malloc.h>
#define NUMBER_OF_GRADES 4
#define NUMBER_OF_CHAR 80
#define NOT_DEFIND_INDEX -1
int main(int argc, const char * argv[]) {
    ClassRoom classRome;
    printf("Hello, please enter teacher name:\n");
    char* teacherName = (char*) malloc(NUMBER_OF_CHAR * sizeof(char));
    scanf("%s", teacherName);
    int teacherLen = (int) strlen(teacherName) + 1;
    // release the memory
    classRome.teacherName = (char*) realloc(teacherName, teacherLen * sizeof(char));
    classRome.studentsNumber = 0;
    printf("Would you like to add a student (1) yes (else) no?\n");
    int doYouWantToPlay = 0;
    scanf("%d" , &doYouWantToPlay);
    
    int lowestAvgIndex = NOT_DEFIND_INDEX;
    int highestAvgIndex = NOT_DEFIND_INDEX;
    // free(teacherName);
    while (doYouWantToPlay == 1) {
        Student tempStudent;
        printf("Student username?\n");
        char* studentName = (char*) malloc(NUMBER_OF_CHAR * sizeof(char));
        scanf("%s", studentName);
        int studentNameLen =  ((int) strlen(studentName)) + 1;
        tempStudent.username = (char*) realloc(studentName,studentNameLen * sizeof(char));
        // tempStudent.username = studentName;
        
        printf("Student ID?\n");
        scanf("%d", &tempStudent.id);
        // this will reinit the grades location
        tempStudent.grades = (int*) malloc(NUMBER_OF_GRADES * sizeof(int));
        tempStudent.avrage = 0.0;
        int gradeIndex = 0;
        for (; gradeIndex < NUMBER_OF_GRADES; gradeIndex++) {
            int grade;
            scanf("%d", &grade);
            tempStudent.grades[gradeIndex] = grade;
            // to reduce the amount of loops needed and calculate each grade effect
            double gradeWight = (double) grade / NUMBER_OF_GRADES;
            tempStudent.avrage = tempStudent.avrage + gradeWight;
        }
        
        classRome.studentsNumber = classRome.studentsNumber + 1;
        if (classRome.studentsNumber == 1) {
            classRome.students = (Student*) malloc(sizeof(Student));
        }
        else classRome.students = (Student*) realloc(classRome.students ,classRome.studentsNumber * sizeof(Student));
        int lastIndex = classRome.studentsNumber - 1;
        classRome.students[lastIndex].username = tempStudent.username;
        classRome.students[lastIndex].grades = tempStudent.grades;
        float avrage = tempStudent.avrage;
        classRome.students[lastIndex].avrage = tempStudent.avrage;
        classRome.students[lastIndex].id = tempStudent.id;
        
        if (lowestAvgIndex == NOT_DEFIND_INDEX) lowestAvgIndex = lastIndex;
        else if (classRome.students[lowestAvgIndex].avrage > avrage) lowestAvgIndex = lastIndex;
        if (highestAvgIndex == NOT_DEFIND_INDEX) highestAvgIndex = lastIndex;
        else if (classRome.students[highestAvgIndex].avrage < avrage) highestAvgIndex = lastIndex;
        
        
        printf("Would you like to add a student (1) yes (else) no?\n");
        scanf("%d" , &doYouWantToPlay);
        // remove the pointer of the temp studnet to
    }
    // if (highestAvgIndex == lowestAvgIndex) {}
    if (classRome.studentsNumber) {
        Student bestStudent = classRome.students[highestAvgIndex], workStudent = classRome.students[lowestAvgIndex];
        printf("Best student is %s, with ID of %d. Average is %f\n", bestStudent.username, bestStudent.id, bestStudent.avrage);
        printf("Worst student is %s, with ID of %d. Average is %f\n", workStudent.username, workStudent.id, workStudent.avrage);
        // get class avg
        int i = 0;
        float classAvg = 0;
        for (; i < classRome.studentsNumber; i++) {
            classAvg = classAvg + classRome.students[i].avrage / classRome.studentsNumber;
        }
        printf("Class average is %f\n", classAvg);
        printf("Teacher is %s\n", classRome.teacherName);
        free(classRome.teacherName);
        printf("Students are:\n");
        int index = 0;
        for (; index < classRome.studentsNumber; index++) {
            printf("%s\n", classRome.students[index].username);
            free(classRome.students[index].username);
            free(classRome.students[index].grades);
        }
        free(classRome.students);
        
    }
    return 0;
}
