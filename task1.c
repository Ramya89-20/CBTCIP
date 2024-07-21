#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10
typedef struct {
    char name[50];
    float scores[MAX_SUBJECTS];
    float avg;
    float high;
    float low;
} Student;
void input(Student students[], int *num_students,int *num_subjects,char subjects[][50]) {
    printf("Enter the number of students: ");
    scanf("%d",num_students);
    printf("Enter the number of subjects: ");
    scanf("%d",num_subjects);
    printf("Enter the names of the subjects:\n");
    for (int i=0;i<*num_subjects;i++) {
        printf(" Subject %d: ",i+1);
        scanf("%s",subjects[i]);
    }

    for (int i=0;i<*num_students;i++) {
        printf("Enter name of student %d: ",i+1);
        scanf("%s", students[i].name);
        printf("Enter scores for %s:\n",students[i].name);
        for (int j=0;j<*num_subjects;j++) {
            printf("  %s: ",subjects[j]);
            scanf("%f",&students[i].scores[j]);
        }
    }
}
void Performance(Student students[], int num_students, int num_subjects) {
    for (int i=0;i<num_students;i++) {
        float total=0.0;
        students[i].high=students[i].scores[0];
        students[i].low=students[i].scores[0];
        for (int j=0;j<num_subjects;j++) {
            float score=students[i].scores[j];
            total+=score;
            if(score>students[i].high) {
                students[i].high=score;
            }
            if (score<students[i].low) {
                students[i].low=score;
            }
        }
        students[i].avg= total/num_subjects;
    }
}
void displaySummary(const Student students[],int num_students,int num_subjects,const char subjects[][50]) {
    printf("\nSummary of Students' Performance:\n");
    printf("%-15s", "Name");
    for (int j=0;j<num_subjects;j++) {
        printf("%-10s",subjects[j]);
    }
    printf("%-10s%-10s%-10s\n","Average","Highest","Lowest");
    printf("---------------------------------------------------------------\n");
    for (int i=0;i<num_students;i++) {
        printf("%-15s",students[i].name);
        for (int j=0;j<num_subjects;j++) {
            printf("%-10.2f",students[i].scores[j]);
        }
        printf("%-10.2f%-10.2f%-10.2f\n",students[i].avg,students[i].high,students[i].low);
    }
}
int main() {
    Student students[MAX_STUDENTS];
    char subjects[MAX_SUBJECTS][50];
    int num_students, num_subjects;
    input(students, &num_students, &num_subjects, subjects);
    Performance(students, num_students, num_subjects);
    displaySummary(students,num_students,num_subjects,subjects);
return 0;
}