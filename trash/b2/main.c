#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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


double f1(double x);

int main(){
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
}
return 0;
}
}

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


