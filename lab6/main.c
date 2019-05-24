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
double f1(double x);

struct student{
        int id;
        char name[NAME];
        char tel[TEL];
        char kurs[KURS];
        int math;
        int phych;
};

struct student* fscan(FILE* fp, struct student* s) {
    if (!fp) {
        return NULL;
    }
    char buffer[256] = {0};
    fscanf(fp, "%[^\n]s", buffer);
    sscanf(buffer, "%d,%s,%s,%s,math:%d,phych:%d",
               &(s->id), s->name, s->tel, s->kurs,&(s->math), &(s->phych));
   // fscanf(fp, "%d,%s,%s,%s,math:%d,phych:%d;\n",
   //            &(s->id), s->name, s->tel, s->kurs,&(s->math), &(s->phych));
    return s;
};

void print(const struct student* s) {
    printf("%d,%s,%s,%s,math:%d,phych:%d\n",
            s->id, s->name, s->tel, s->kurs,s->math, s->phych);
}

int main()
{
    char answer;
    while((answer = menu()) != '4') {
        if(answer == '1'){
            FILE *f;
            if((f = fopen("task1.txt", "w"))== NULL){
                fprintf(stderr,"Cannot open file!");
                return -11;
            }
            double a = 2, b = 5, h = 0.1;

            fprintf(f,"\t\t\t\t\t\t *****TABULATION*****\n");
            fprintf(f,"\nIntegral [%.0f,%.0f];\n",a,b);
            fprintf(f,"x:\t");
            for (double x = a; x <= b; x += h) {
                char c = x + h < b ? '\t' : '\n';
                fprintf(f,"%.3f%c", x, c);
            }

            fprintf(f,"y:\t");
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
            fprintf(f,"\n sum:  %.5f;",a,b,intres);
        fclose(f);
    }
    if(answer == '2'){
    struct student s;
    memset(&s, 0, sizeof(s));
    char fname[256] = "stud.txt";
    FILE *fp = fopen(fname, "r");
    FILE *fo = fopen("stud1.bin", "rb+");
    FILE *ft = fopen("stud1.txt", "r+");

    if (!fp) {
        printf("Can't open file %s\n", fname);
        return -1;

    }
    if (!fo) {
        printf("Can't open file stud1.bin");
        return -1;

    }
    if (!ft) {
        printf("Can't open file stud1.txt");
        return -1;

    }


    fscan(fp, &s);
    print(&s);
    fwrite(&s, sizeof(int), 1, fo);
    fread(&s,sizeof(int), 1, ft);
    fwrite(&s, sizeof(int), 1, ft);

    fclose(fp);
}return 0;}

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
}
char menu() {
    char choo;
    printf("------------------------\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("[1]Tabulation\n");
    printf("[2]LOCALIZATIon\n");
    printf("[3]INTEGRAL\n");
    printf("[C]CLEAR CON\n");
    printf("[Q]Exit\n");
    while((choo = getchar()) == '\n');
    printf("\n");
    return choo;
}


