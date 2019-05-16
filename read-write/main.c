#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define DEBUG
#define ID 10
#define NAME 30
#define TEL 14
#define KURS 3
#define LEN 50

#ifdef DEBUG
#define debug(data) printf("%s", data);
#else
#define debug(data)
#endif

const char inputFile[] = "D:/work/Programming-1k-105-SS/lab6/stud.txt";
const char outputFile[] = "D:/work/Programming-1k-105-SS/lab6/stud1.bin";

struct someArgs{
        int id;
        char name[NAME];
        char tel[TEL];
        char kurs[KURS];
        int math;
        int phych;
        int* items;
        size_t number
};

int writeToFile(FILE *file, void* args) {
    size_t i;
    struct someArgs *data = (struct someArgs*) args;
    debug("write to file\n")
    fwrite(data->items, sizeof(int), data->number, file);
    debug("write finished\n")
    return 0;
}

int readAndCallback(FILE *file, void* args) {
    struct someArgs data;
    size_t size, i = 0;
    int result;
    debug("read from file\n")
    fscanf(file, "%d", &size);
    data.items = (int*) malloc(size*sizeof(int));
    data.number = size;
    while (!feof(file)) {
        fscanf(file, "%d", &data.items[i]);
        i++;
    }
    debug("call withOpenFile\n")
    result = withOpenFile(outputFile, "w", writeToFile, &data);
    debug("read finish\n")
    free(data.items);
    return result;
}

int doStuff() {
    return withOpenFile(inputFile, "r", readAndCallback, NULL);
}

//Обёртка - функция открывает файл. Если файл был благополучно открыт,
//то вызывается функция fun. Так как аргументы могут быть самые разные,
//то они передаются через указатель void*. В качестве типа аргумента
//разумно использовать структуру
int withOpenFile(const char *filename,
                 const char *mode,
                 int (*fun)(FILE* source, void* args),
                 void* args) {
    FILE *file = fopen(filename, mode);
    int err;

    debug("try to open file ")
    debug(filename)
    debug("\n")

    if (file != NULL) {
        err = fun(file, args);
    } else {
        return 1;
    }
    debug("close file ")
    debug(filename)
    debug("\n")
    fclose(file);
    return err;
}

void main() {
    printf("result = %d", doStuff());
    getch();
}
