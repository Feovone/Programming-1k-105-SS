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
    struct student s;
    memset(&s, 0, sizeof(s));
    char fname[256] = "stud.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Can't open file %s\n", fname);
        return -1;
    }

    fscan(fp, &s);
    print(&s);
    fclose(fp);
}
