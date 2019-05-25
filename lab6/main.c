#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ID 10
#define NAME 30
#define TEL 14
#define KURS 3
#define LEN 50
char menu();
double f1();
//for 2 task
void clrscr()
{
    system("@cls||clear");
}
typedef struct _tagStudent{
    int id;
    int kurs;
    int math;
    int phych;
    int ukr;
} STUDENT, *PSTUDENT;

PSTUDENT read(FILE* fp,PSTUDENT ps);
void step(STUDENT student);


int main()
{
  //  double f1(double x);
    char answer;
    while((answer = toupper(menu())) != 'Q') {
        if(answer == '1'){
            FILE *f;
            if((f = fopen("task1.txt", "w"))== NULL){
                fprintf(stderr,"Cannot open file!");
                return -11;
            }
            double a = 2, b = 5, h = 0.1;

            fprintf(f,"\t\t\t\t\t\t *****TABULATION*****");
            fprintf(f,"\nIntegral [%.0f,%.0f];\n",a,b);
            fprintf(f,"x:\t\t");
            for (double x = a; x <= b; x += h) {
                char c = x + h < b ? '\t' : '\n';
                fprintf(f,"%.3f%c", x, c);
            }

            fprintf(f,"y:\t\t");
            for (double x = a; x <= b; x += h) {
                char c = x + h < b ? '\t' : '\n';
                fprintf(f,"%.3f%c", f1(x), c);
            }
            fprintf(f, "MIN/MAX DOTS:\t");
            int e=0;
            for (double x = a; x <= b; x += h) {
                char c = x + h < b ? '\t' : '\n';
                if(f1(x-h)<f1(x)&&f1(x)>f1(x+h)){
                    ++e;
                    fprintf(f," MAX%c", c);
                } else if (f1(x-h)>f1(x)&&f1(x)<f1(x+h)){
                    ++e;
                    fprintf(f," MIN%c", c);
                }else{
                fprintf(f,"  --%c", c);
                }
            }

            fprintf(f,"Function have %d extreme dot('s);",e);


            double intres=0;
            for(double i = a; i <= b; i+=h){
                intres += h*f1(i);
            }
            fprintf(f,"\nSum:  %.5f;",a,b,intres);
        fclose(f);
        printf("Check task1.txt\n");
    }
    if(answer == '2'){
    char file_name[256] = "stud.txt";
    FILE* fp = fopen(file_name, "r+");
    if (!fp) {
        printf("Cannot open file %s\n", file_name);
        return -1;
    }

    STUDENT student;
    memset(&student, 0, sizeof(student));
    int i=0;
    while(ID>i){
    memset(&student, 0, sizeof(student));
    read(fp, &student);
    step(student);
    i++;
    }

    fclose(fp);

    return 0;
}if(answer == 'C'){
   clrscr(); }}}



//1 task
double f1(double x) {
    if (x <= 1.0) {
        return 3-fabs(x-pow(3-x,1.0/3));
    }
        if (x > 1 && x <= 4) {
            return pow(x, 1.0/3);
        }
        if (x>4){
            return pow(2+x,1.0/3);
        }
    }

//2 task
void print_student(STUDENT ps) {
    printf("{Student with id=%d, kurs=%d, math=%d, phych=%d, ukrainian=%d have salary. Avarage marks=%d}\n",
          ps.id,
          ps.kurs,
          ps.math,
          ps.phych,
          ps.ukr,
         ((ps.math+ps.phych+ps.ukr)/3)
          );
}

PSTUDENT read(FILE* fp,PSTUDENT ps) {
    char str[256] = {0};
    char c;
    fscanf(fp, "%[^\n]s", str);
    fscanf(fp, "%c", &c);
    // printf("====%s====\n", str); //CHECK WORK
    sscanf(str, "%d,%d,%d,%d,%d\n",
           &(ps->id),
           &(ps->kurs),
           &(ps->math),
           &(ps->phych),
           &(ps->ukr)
           );

   return ps;
}

step(STUDENT student){
if((student.math+student.phych+student.ukr)/3>=75){
    print_student(student);
}else if(student.id!=0){printf("Student with id=%d did't have a salary, because avarage marks=%d\n",student.id, ((student.math+student.phych+student.ukr)/3));
}}

char menu() {
    char choo;
    printf("------------------------\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("[1]Tabulation\n");
    printf("[2]Student's salary\n");
    printf("[C]CLEAR CON\n");
    printf("[Q]Exit\n");
    while((choo = getchar()) == '\n');
    printf("\n");
    return choo;
}


