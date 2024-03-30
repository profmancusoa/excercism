#include "grade_school.h"
#include <string.h>
#include <stdlib.h>

void init_roster(roster_t *roster) {
    roster->count = 0;
    memset(roster->students, 0, MAX_STUDENTS * sizeof(student_t));
}

bool is_student_present(roster_t *roster, const char name[]) {
    for(size_t i = 0; i < roster->count; i++)
        if(strcmp(name, roster->students[i].name) == 0) return true;

    return false;
}

int compare (const void * elem1, const void * elem2) {
    student_t *s1 = (student_t *)elem1;
    student_t *s2 = (student_t *)elem2;

    if(s1->grade == s2->grade) {
        return strcmp(s1->name, s2->name);
    }

    return s1->grade - s2->grade;
} 

void sort_students(roster_t *roster) {
    qsort(roster->students, roster->count, sizeof(student_t), compare);
}

bool add_student(roster_t *roster, const char name[], uint8_t grade) {
    if(!is_student_present(roster, name)) {
        roster->students[roster->count].grade = grade;
        strcpy(roster->students[roster->count].name, name);
        roster->count += 1;
        sort_students(roster);

        return true;
    }

    return false;
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade) {
    roster_t grade;
    init_roster(&grade);

    for(size_t i = 0; i < roster->count; i++) {
        if(roster->students[i].grade == desired_grade) {
            grade.students[grade.count] = roster->students[i];
            grade.count += 1;
        }
    }  

    return grade; 
}