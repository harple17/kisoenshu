#include<stdio.h>
#include<stdlib.h>

int main () {
    FILE *fp; //これ使うん？よくわからんから残しといた
    printf("学籍番号の下4桁を入力して下さい。\n");
    int n1,n2,n3,n4;
    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
    printf("動的に確保するint型変数の数を入力してください。\n"); //動的にって言われてからこれ付けたけど多分これ削ってn=9にしていい
    int n;
    scanf("%d",&n);
    int X[3]={n4+n3,n3+n2,n2+n1};
    int *A=(int*)malloc(n*sizeof(int));
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            *(A+3*i+j)=(*(X+i))*(*(X+j));
        }
    }
    int det;
    det = (*A)*(*(A+4))*(*(A+8))+(*(A+7))*(*(A+3))*(*(A+2))+(*(A+1))*(*(A+5))*(*(A+6))-(*(A+6))*(*(A+4))*(*(A+2))-(*(A+1))*(*(A+3))*(*(A+8))-(*(A+7))*(*(A+5))*(*(A));
    printf("A=\n");
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            printf(" %3d",*(A+3*i+j));
        }
        printf("\n");
    }
    printf("detA=%d",det);
    free(A);
    return 0;
}