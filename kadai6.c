#include<stdio.h>
#define M 12 /*num of Months*/
#define D 7 /*num of Days in a week*/
#define W 6 /*max num of Weeks*/
#define N 5 /*Num of calenders of a row*/

int z_fm(int y,int m,int d); /*zeller formula*/
int isleap(int y);/*if the yaer is leap year,return true,else return false*/

int main()
{
    int end_of_months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int y;
    printf("西暦を入力してください。:"); scanf("%d",&y);
    if (isleap(y)) end_of_months[1]=29;/*consider leap year*/

    
    /*substitute date*/
    int buff[M][W][D]={0};
    for (int i1=0;i1<M;i1++) {
        int d=1;
        for (int i2=0;i2<W;i2++) {
            for (int i3=z_fm(y,i1+1,d);i3<D;i3++) {
                buff[i1][i2][i3]=d;
                d++;
            }
        }        
    }
    /*show calenders*/
    for (int i1=0;i1<M/N;i1++) {
        for (int i2=0;i2<N;i2++){
            printf("           %2d月       ",N*i1+i2+1);
        }
        printf("\n");
        for (int i2=0;i2<N;i2++) {
            printf("  月 火 水 木 金 土 日");
        }
        printf("\n");
        for (int i2=0;i2<W;i2++) {
            printf(" ");
            for (int i3=0;i3<N;i3++) {
                if (i2==0) {
                    for (int i4=0;i4<z_fm(y,N*i1+i3+1,1);i4++) {
                        printf("   ");
                    }   
                    for (int i4=z_fm(y,N*i1+i3+1,1);i4<D;i4++) {
                        printf("%3d",buff[N*i1+i3][i2][i4]);
                    }
                    printf(" ");
                } else {
                    for (int i4=0;i4<D;i4++) {
                        if (buff[N*i1+i3][i2][i4]<=end_of_months[N*i1+i3])printf("%3d",buff[N*i1+i3][i2][i4]);
                        else printf("   ");
                    }
                    printf(" ");
                }    
            }
            printf("\n");
        }

    }    
    return 0;
}

int z_fm(int y, int m, int d)
{
    if (m<3) {
        y--; 
        m+=12;
    }
    return ((y+y/4-y/100+y/400+(13*m+8)/5+d)-1)%7;
}

int isleap(int y)
{
    if ((y%4==0&&y%100!=0)||(y%400==0)) return 1;
    else return 0;
}