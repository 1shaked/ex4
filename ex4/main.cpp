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
    float avrage;
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
int main(int argc, const char * argv[]) {
    ClassRoom classRome;
    printf("Hello, please enter teacher name:\n");
    char* teacherName = (char*) malloc(NUMBER_OF_CHAR * sizeof(char));
    scanf("%s", teacherName);
    // teacherName.length
    int teacherLen = (int) strlen(teacherName) + 1;
    classRome.teacherName = (char*) realloc(teacherName, teacherLen * sizeof(char));
    printf("%s ,%d \n", teacherName, teacherLen); // TODO: DELETE THIS LINE
    // classRome.teacherName = (char*) malloc(teacherLen * sizeof(char));
    // classRome.teacherName = teacherName;
    // release the memory
    classRome.studentsNumber = 0;
    printf("%s ,%d \n", classRome.teacherName, teacherLen);
    printf("Would you like to add a student (1) yes (else) no?\n");
    int doYouWantToPlay = 0;
    scanf("%d" , &doYouWantToPlay);
    
    
    /*
     Testing
     
    Student s1, s2;
    // {"s", "H", "K"}
    s1.username = (char*) malloc( 5 * sizeof(char) );
    s1.grades = (int*) malloc(3 * sizeof(int));
    *(s1.grades + 1) = 100;
    *(s1.grades + 2) = 80;
    *(s1.grades + 3) = 50;
    ClassRoom cls;
    cls.students = (Student*) malloc(3 * sizeof(Student));// malloc(sizeof(Student));
    cls.students[0] = s1;
    
    s2 = s1;
    cls.students[1] = s2;
    cls.students[2] = s2;
    printf("%d \n", s2.grades[0]);
    cls.students[1].grades[0] = -100;
    printf("%d \n", s2.grades[0]);
    // s2 = NULL;
    s2.grades = (int*) malloc(3 * sizeof(int));
    *s2.grades = 50;
    *(s2.grades + 1) = 74;
    printf("%d %d\n", s2.grades[0], s2.grades[1]);
    printf("%d %d\n", cls.students[1].grades[0], cls.students[1].grades[1]);
    
    cls.students[1].avrage = 1.1;
    cls.students[2].avrage = 0.9;
    printf("%f %f\n", cls.students[2].avrage , cls.students[1].avrage);
    // if (&s2 == &s1) printf("the same addres");
    
    
     End Testing
     */
    
    
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
        int gradeIndex = 0;
        for (; gradeIndex < NUMBER_OF_GRADES; gradeIndex++) {
            int grade;
            scanf("%d", &grade);
            tempStudent.grades[gradeIndex] = grade;
            // to reduce the amount of loops needed and calculate each grade effect
            tempStudent.avrage = grade / NUMBER_OF_GRADES;
        }
        
        classRome.studentsNumber = classRome.studentsNumber + 1;
        if (classRome.studentsNumber == 1) {
            classRome.students = (Student*) malloc(sizeof(Student));
        }
        else classRome.students = (Student*) realloc(classRome.students ,classRome.studentsNumber * sizeof(Student));
        int lastIndex = classRome.studentsNumber - 1;
        char ptr = *(classRome.students + lastIndex)->username;
        printf("%c\n", ptr);
        classRome.students[lastIndex].username = tempStudent.username;
        classRome.students[lastIndex].grades = tempStudent.grades;
        classRome.students[lastIndex].avrage = tempStudent.avrage;
        
        
        printf("Would you like to add a student (1) yes (else) no?\n");
        scanf("%d" , &doYouWantToPlay);
        
        // remove the pointer of the temp studnet to
    }
    return 0;
}
