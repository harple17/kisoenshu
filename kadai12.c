#include<stdio.h>
#include<string.h>

void swapcase(char *p) {
    int i = 0;
    while (*(p+i) != '\0') {
        if (*(p+i) >= 'A' && *(p+i) <= 'Z') {
            *(p+i) += 'a' - 'A';
        }
        else if (*(p+i) >= 'a' && *(p+i) <= 'z') {
            *(p+i) -= 'a' - 'A';
        }
        i++;
    }
}

int main () {

    char in[64];

    scanf("%s",in);
    while (strcmp(in,"quit")) {
        swapcase(in);
        printf("%s\n",in);
        scanf("%s",in);
    } 

    return 0;
}