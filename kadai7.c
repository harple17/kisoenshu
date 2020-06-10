#include<stdio.h>
#define M 2
#define N 3
#define K 3

void madd(int a1[M][N], int a2[M][N],int a3[M][N])
{
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            a3[i][j]=0;
        }
    }
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            a3[i][j]=a1[i][j]+a2[i][j];
        }
    }
}
void msub(int a1[M][N], int a2[M][N],int a3[M][N])
{
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            a3[i][j]=0;
        }
    }
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            a3[i][j]=a1[i][j]-a2[i][j];
        }
    }
}
void mmul(int a1[M][N], int a2[N][K],int a3[M][K])
{
    for (int i=0;i<M;i++) {
        for (int j=0;j<K;j++) {
            a3[i][j]=0;
        }
    }
    for (int i=0;i<M;i++) {
        for (int j=0;j<K;j++) {
            for (int k=0;k<N;k++) {
                a3[i][j]+=a1[i][k]*a2[k][j];
            }
        }
    }   
}

int main ()
{
    int in1[M][N]={{1,2,3},{5,2,1}};
    int in2[M][N]={{4,1,2},{1,3,2}};
    int in3[N][K]={{1,2,3},{4,2,1},{3,2,2}};
    int out1[M][N],out2[M][K];
    madd(in1,in2,out1);
    printf("行列の和\n");
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            if ((j+1)%N==0) printf("%3d\n",out1[i][j]);
            else printf("%3d",out1[i][j]);
        }
    }
    msub(in1,in2,out1);
    printf("行列の差\n");
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            if ((j+1)%N==0) printf("%3d\n",out1[i][j]);
            else printf("%3d",out1[i][j]);
        }
    }
    mmul(in1,in3,out2);
    printf("行列の積\n");
    for (int i=0;i<M;i++) {
        for (int j=0;j<K;j++) {
            if ((j+1)%N==0) printf("%3d\n",out2[i][j]);
            else printf("%3d",out2[i][j]);
        }
    }
    return 0;
}