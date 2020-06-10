#include<stdio.h>

int count(char *p1,char *p2) {
    int c=0;
    for (int i=0;*(p1+i)!='\0';i++) {
        if (*(p1+i)==*p2) c++;
    }
    return c;
}

int main() {
    char c1[128],c2[2];
    while(1) {
        printf("input word(if the input is \"end\", the program will be closed)："); scanf("%s",c1);
        if (*c1=='e'&&*(c1+1)=='n'&&*(c1+2)=='d') {
            break;
        }
        printf("input character:"); scanf("%s",c2);
        printf("%c appeared %d times in the word\n",c2[0],count(c1,c2));
    }
    return 0;
}