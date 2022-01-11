/******************************************
* Shaked Chen
* 207253220
* 83-120-01
* Ex 4
******************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
// #include <malloc.h>

#define NUMBER_OF_GRADES 4
#define NUMBER_OF_CHAR 80
#define NOT_DEFIND_INDEX -1


typedef struct {
    char* username;
    int id;
    int* grades;
    float average;
} Student;

typedef struct {
    char* teacherName;
    Student* students;
    int studentsNumber;
} ClassRoom;
void setClassRome(ClassRoom *cls,char *teacherName);

int main(int argc, const char * argv[]) {
    ClassRoom classRome;
    printf("Hello, please enter teacher name:\n");
    char teacherName[80];
    scanf("%s", teacherName);
    setClassRome(&classRome, teacherName);
    if (classRome.teacherName == NULL) return 1;
    printf("Would you like to add a student (1) yes (else) no?\n");
    int doYouWantToPlay = 0;
    scanf("%d" , &doYouWantToPlay);
    
    int lowestAvgIndex = NOT_DEFIND_INDEX;
    int highestAvgIndex = NOT_DEFIND_INDEX;
    while (doYouWantToPlay == 1) {
        Student tempStudent;
        printf("Student username?\n");
        char* studentName = (char*) malloc(NUMBER_OF_CHAR * sizeof(char));
        if (studentName == NULL) return 1;
        scanf("%s", studentName);
        int studentNameLen =  ((int) strlen(studentName)) + 1;
        tempStudent.username = (char*) realloc(studentName,studentNameLen * sizeof(char));
        if (tempStudent.username == NULL) return 1;
        printf("Student ID?\n");
        scanf("%d", &tempStudent.id);
        printf("Student Grades?\n");
        // this will reinit the grades location
        tempStudent.grades = (int*) malloc(NUMBER_OF_GRADES * sizeof(int));
        if (tempStudent.grades == NULL) return 1;
        tempStudent.average = 0;
        int gradeIndex = 0;
        for (; gradeIndex < NUMBER_OF_GRADES; gradeIndex++) {
            int grade;
            scanf("%d", &grade);
            *(tempStudent.grades + gradeIndex) = grade;
            // to reduce the amount of loops needed and calculate each grade effect
            tempStudent.average = tempStudent.average + ( (float) grade / NUMBER_OF_GRADES);
        }
        classRome.studentsNumber = classRome.studentsNumber + 1;
        if (classRome.studentsNumber == 1) classRome.students = (Student*) malloc(sizeof(Student));
        else classRome.students = (Student*) realloc(classRome.students ,classRome.studentsNumber * sizeof(Student));
        if (classRome.students == NULL) return 1;
        int lastIndex = classRome.studentsNumber - 1;
        (classRome.students + lastIndex)->username = tempStudent.username;
        (classRome.students + lastIndex)->grades = tempStudent.grades;
        float average = tempStudent.average;
        (classRome.students + lastIndex)->average = average;
        (classRome.students + lastIndex)->id = tempStudent.id;
        // setting the best and the worst student
        if (lowestAvgIndex == NOT_DEFIND_INDEX) lowestAvgIndex = lastIndex;
        else if ((classRome.students + lowestAvgIndex)->average > average) lowestAvgIndex = lastIndex;
        if (highestAvgIndex == NOT_DEFIND_INDEX) highestAvgIndex = lastIndex;
        else if ((classRome.students + highestAvgIndex)->average < average) highestAvgIndex = lastIndex;
        printf("Would you like to add a student (1) yes (else) no?\n");
        scanf("%d" , &doYouWantToPlay);
    }
    // check if there is no students and if are print and free them
    if (classRome.studentsNumber) {
        printf("There are %d students in the class.\n" , classRome.studentsNumber);
        Student *bestStudent = classRome.students + highestAvgIndex, *workStudent = classRome.students + lowestAvgIndex;
        printf("Best student is %s, with ID of %d. Average is %f.\n", bestStudent->username, bestStudent->id, bestStudent->average);
        printf("Worst student is %s, with ID of %d. Average is %f.\n", workStudent->username, workStudent->id, workStudent->average);
        // get class avg
        int i = 0;
        float classAvg = 0;
        for (; i < classRome.studentsNumber; i++) classAvg = classAvg + ( (float) (classRome.students + i)->average / classRome.studentsNumber );
        printf("Class average is %f.\n", classAvg);
        printf("Teacher is %s\n", classRome.teacherName);
        printf("Students are:\n");
        int index = 0;
        for (; index < classRome.studentsNumber; index++) {
            Student *studentDelete = classRome.students+index;
            printf("%s\n", studentDelete->username);
            free(studentDelete->username);
            free(studentDelete->grades);
        }
        free(classRome.students);
    }
    else {
        printf("There are 0 students in the class.\n");
        printf("There are no students.\n");
    }
    // free the teacher name here because I created the teacher name dynamically and here is better the one in the if and one in the else.
    free(classRome.teacherName);
    return 0;
}
/*********************************************************************
Function name: setClassRome
Input: ClassRoom *cls,char *teacherName
Output: void
The function operation: setting the class rome inital values tracher name, studentsNumber and the pointer to the students
************************************************************************/
void setClassRome(ClassRoom *cls,char *teacherName) {
    (*cls).teacherName = (char*) malloc((strlen(teacherName) + 1) * sizeof(char));
    strcpy(cls->teacherName, teacherName);
    cls->studentsNumber = 0;
    cls->students = NULL;
}
